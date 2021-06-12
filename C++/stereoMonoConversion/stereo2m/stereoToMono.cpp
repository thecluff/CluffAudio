#include <iostream>
#include <cstdlib>
#include <sndfile.h>

using namespace std;

int main(int argc, const char *argv[])
{

	// Global variables for file functions, etc.
	SNDFILE *infile, *outfile;
	SF_INFO sfInInfo, sfOutInfo;
	sf_count_t readCount, writeCount;

    // Buffers
	double *inBuf, *outBuf;

	// Stop if the inputs are not complete
	if(argc<3) {
		cout << "Please pass an input file name, and an output audio file name." << endl;
		cout << "Application closing." << endl;
		return 0;
	}

    // Open input file
	if (!(infile = sf_open(argv[1], SFM_READ, &sfInInfo)))
	{
		cout << "Not able to open input file; closing program." << endl;
		sf_perror(NULL);
		return 1;
	}

    // Test to see if the input file is stereo
	if (sfInInfo.channels != 2)
	{
		cout << "Not a stereo file. closing program." << endl;
		return 0;
	}

	cout << "The number of input frames is " << sfInInfo.frames << "." << endl;
	cout << "The sample rate is " << sfInInfo.samplerate << "." << endl;
	cout << "The number of channels is " << sfInInfo.channels << "." << endl;

	// Set up output file
	sfOutInfo.frames = sfInInfo.frames;
	sfOutInfo.channels = 1;
	sfOutInfo.samplerate = sfInInfo.samplerate;
	sfOutInfo.format = sfInInfo.format;

	// Open the output file
	if (!(outfile = sf_open(argv[2], SFM_WRITE, &sfOutInfo)))
	{
		cout << "Not able to open the output file." << endl;
		cout << "Application will now close." << endl;
		sf_perror(NULL);
		return 1;
	}

	// Allocate input and output buffers
	// Check to see if the info structs are correct
	cout << "The number of input samples is " << sfInInfo.frames*sfInInfo.channels << "." << endl;
	cout << "The number of output samples is " << sfOutInfo.frames*sfOutInfo.channels << "." << endl;
	inBuf = new double[sfInInfo.frames * sfInInfo.channels];
	outBuf = new double[sfInInfo.frames * 1];

	readCount = sf_read_double(infile, inBuf, sfInInfo.frames*sfInInfo.channels);
	cout << "The number of samples read is " << readCount << endl;

	// Copy the samples
	cout << "Copying samples now..." << endl;
	for(int ndx=0;ndx<sfInInfo.frames;ndx++) {
		outBuf[ndx] = inBuf[ndx*2] * 0.5 + inBuf[ndx*2-1] * 0.5;
	}

	writeCount = sf_write_double(outfile, outBuf, sfInInfo.frames * 1);

	cout << "The number of samples read is" << readCount << "." << endl;
	cout << "The number of samples written is" << writeCount << "." << endl;

	sf_close(infile);
	sf_close(outfile);
	delete[] inBuf;
	delete[] outBuf;

	return 0;
}
