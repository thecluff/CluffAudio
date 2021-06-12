// This project provides a framework for building future projects

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sndfile.h>

using namespace std;

// Global variables for file functions, etc.
SNDFILE *infile1, *infile2, *outfile;
SF_INFO sfInInfo1, sfInInfo2, sfOutInfo;
sf_count_t readCount1, readCount2, writeCount;

// Buffers
double *inp1, *inp2, *outp;

// Forward declarations
int openInput1(const char *fn);
int openInput2(const char *fn);
int openOutput(const char *fn, int length);
// int allocateBuffers(double *inBuf, double *outBuf, int length);
int readInput1();
int readInput2();
int normalize(double * buffer, int length);
int gain(double *buffer, int length, double gainFac);
int writeOutput(int length);
int cleanUp();

int main(int argc, const char *argv[]){

    if(argc<5) {
        cout << "Input arguments are: input file 1, input file 2, output file, offset, gain." << endl;
        return 0;
    }

    openInput1(argv[1]);
    openInput2(argv[2]);

    if(sfInInfo1.samplerate != sfInInfo2.samplerate) {
        cout << "Differing sample rates. You're fired." << endl;
        return 0;
    }

    const int offsetInFrames = (int)(atof(argv[4]) * sfInInfo1.samplerate);
    const int offsetInSamples = offsetInFrames*sfInInfo1.channels;
    const int len1 = sfInInfo1.frames*sfInInfo1.channels;
    const int len2 = (sfInInfo2.frames+offsetInFrames) * sfInInfo2.channels;
    const int mixFrameLength = (sfInInfo1.frames>(sfInInfo2.frames+offsetInFrames)) ? sfInInfo1.frames : sfInInfo2.frames+offsetInFrames;
    const int outputBufferLength = mixFrameLength*sfInInfo1.channels;

    openOutput(argv[3], mixFrameLength);

    inp1 = new double[len1];
    inp2 = new double[sfInInfo2.frames*sfInInfo2.channels];
    outp = new double[outputBufferLength];

    readInput1();
    readInput2();

    cout << "Mixing..." << endl;

    for(int ndx=0;ndx<len1;ndx++){
        outp[ndx] = inp1[ndx];
    }

    for(int ndx=offsetInFrames*sfInInfo1.channels;ndx<outputBufferLength;ndx++) {
        outp[ndx] = outp[ndx] + inp2[ndx-offsetInSamples];
    }

    cout << "File streams mixed." << endl;

    normalize(outp, outputBufferLength);
    gain(outp, outputBufferLength, atof(argv[5]));
    writeOutput(outputBufferLength);
    cleanUp();

    cout << "The number of input1's frames is " << readCount1 << endl;
    cout << "The number of input2's frames is " << readCount2 << endl;
    cout << "The offset in frames is " << offsetInFrames << endl;
    cout << "The number of output frames is " << writeCount << endl;

    return 0;
}

int openInput1(const char *fn) {
    // Opens input file
    if (!(infile1 = sf_open(fn, SFM_READ, &sfInInfo1)))
	{
		cout << "Not able to open input file; closing now." << endl;
		sf_perror(NULL);
		return 1;
	}
    cout << "Input file 1 opened for reading." << endl;

    return 0;
}

int openInput2(const char *fn) {
    // Opens input file
    if (!(infile2 = sf_open(fn, SFM_READ, &sfInInfo2)))
	{
		cout << "Not able to open input file; closing now." << endl;
		sf_perror(NULL);
		return 1;
	}
    cout << "Input file 2 opened for reading." << endl;

    return 0;
}

int readInput1() {
    cout << "Now reading input 1." << endl;
    readCount1 = sf_read_double(infile1, inp1, sfInInfo1.frames*sfInInfo1.channels);
	cout << "The number of samples read is " << readCount1 << endl;
    return 0;
}

int readInput2() {
    cout << "Now reading input 2." << endl;
    readCount2 = sf_read_double(infile2, inp2, sfInInfo2.frames*sfInInfo2.channels);
	cout << "The number of samples read is " << readCount2 << endl;
    return 0;
}

int gain(double *buffer, int length, double gainFac) {
    for(int ndx=0;ndx<length;ndx++) {
        buffer[ndx] *= gainFac;
    }

    return 0;
}

int normalize(double *buffer, int length) {
    double highestAmp = 0.0;
    for(int ndx=0;ndx<length;ndx++) {
        if(fabs(buffer[ndx])>highestAmp) {
            highestAmp = fabs(buffer[ndx]);
        }
    }
    cout << "Normalizing.. The highest magnitude is " << highestAmp << "." << endl;
    double normFac = 1.0/highestAmp;
    for(int ndx=0;ndx<length;ndx++) {
        buffer[ndx] *= normFac;
    }
	return 0;
}

int openOutput(const char *fn, int length) {
    	// Open the output file
	sfOutInfo.frames = length;
	sfOutInfo.channels = sfInInfo1.channels;;
	sfOutInfo.samplerate = sfInInfo1.samplerate;
	sfOutInfo.format = sfInInfo1.format;

	if (!(outfile = sf_open(fn, SFM_WRITE, &sfOutInfo)))
	{
		cout << "Not able to open the output file." << endl;
		cout << "You're fired. Build the wall." << endl;
		sf_perror(NULL);
		return 1;
	}
	cout << "Output file  opened for writing" << endl;
    return 0;
}

int writeOutput(int length){
    cout << "Writing the output." << endl;
	writeCount = sf_write_double(outfile, outp, length);
	cout << writeCount << " samples written to output file." << endl;
	return 0;
}

int cleanUp() {
	sf_close(infile1);
	sf_close(infile2);
	sf_close(outfile);
	delete[] inp1;
	delete[] inp2;
	delete[] outp;
	cout << "Input and output files closed and buffers deleted." << endl;
	return 0;
}

// Arguments: input file, output file, and offset
