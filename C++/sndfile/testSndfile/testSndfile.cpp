// testSndfile.cpp: copy the contents of one audio file to another

#include <iostream>
#include <cstdlib>
#include <sndfile.h>

// SNDFILE is a custom data type that belongs to the library libsndfile
// Its purpose is to provide a type that holds sound file data.

SNDFILE *infile, *outfile;

// Each audio file will contain format information. To hold that format information,
// we need to use another custom data type, SF_INFO.
// When we declare a variable name using the '*', it means that it is a pointer, in other words
// a variable that holds the address of another variable.

SF_INFO sfInInfo, sfOutInfo;

// Whenever we do a file operation, such as read or write, we will want to keep track of
// the number or count of samples that were transferred.

sf_count_t readCount, writeCount;

// We will need an input buffer and output buffer

double *inp, *outp;

using namespace std;

int main(int argc, const char *argv[]) {

    double gainFac = 1.0;

    cout << "If you are reading this, then the compiler must have found libsndfile." << endl;

    if(argc<4) {
        cout << "Please supply an input file and an output file" << endl;
        return 0;
    }

    // Examine the three input arguments
    cout << argv[1] << "\t\t" << argv[2] << argv[3] << endl;

    // Open the input file. Opening files is "risky."
    // In other words, it might fail. For example: if the file cannot be found.
    // If the file open operation fails and the program encounters an exception,
    // then that exception must be handled.

    if(! (infile = sf_open(argv[1], SFM_READ, &sfInInfo))) {
        cout << "Not able to open input file." << endl;
        cout << "Application will now close." << endl;
        sf_error(NULL);
        return 1;
    }

    // Examine the file format information
     cout << "The number of frames is " << sfInInfo.frames << "." << endl;
     cout << "The number of channels is " << sfInInfo.channels << "." << endl;
     cout << "The sample rate is " << sfInInfo.samplerate << "." << endl;
     cout << "The file format is " << sfInInfo.format << "." << endl;

    // Next, set up the output file
    sfOutInfo.frames = sfInInfo.frames;
    sfOutInfo.channels = sfInInfo.channels;
    sfOutInfo.samplerate = sfInInfo.samplerate;
    sfOutInfo.format = sfInInfo.format;
    
    // Now open the output file. The same precautions apply.
        if(! (outfile = sf_open(argv[2], SFM_WRITE, &sfOutInfo))) {
        cout << "Not able to open output file." << endl;
        cout << "Application will now close." << endl;
        sf_error(NULL);
        return 1;
    }

    // Allocate some memory for the two buffers.
    // The number of frames is the same for both monophonic and stereo files.
    // The difference is the number of channels.
    inp = new double[sfInInfo.frames*sfInInfo.channels];
    outp = new double[sfInInfo.frames*sfInInfo.channels];

    // Read in audio data from the input file
    readCount = sf_read_double(infile, inp, sfInInfo.frames*sfInInfo.channels);
    // Print the number of frames read
    cout << "The number of samples read is " << "\t\t" << readCount << endl;

    // Copy audio from the input buffer to the output buffer
    // Add a gain factor
    gainFac = atof (argv[3]);
    for(int ndx=0;ndx<sfInInfo.frames*sfInInfo.channels;ndx++){
        outp[ndx] = inp[ndx] * gainFac;
    }

    writeCount = sf_write_double(outfile, outp, sfInInfo.frames*sfInInfo.channels);

    // Look to see if the number of samples written is equal to the number of samples read.

    cout << "The number of input samples is " << "\t" << readCount << endl;
    cout << "The number of output samples is " << "\t" << writeCount << endl;

    // Clean up
    sf_close(infile);
    sf_close(outfile);
    delete [] inp;
    delete [] outp;

    return 0;
}
