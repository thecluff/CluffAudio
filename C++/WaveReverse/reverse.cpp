// Copy from one audio file to another, reversing the order of the sample sequence.

#include <iostream>
#include <cstdlib>
#include <sndfile.h>

using namespace std;

// Global variables for file functions, etc.
SNDFILE *infile, *outfile;
SF_INFO sfInInfo, sfOutInfo;
sf_count_t readCount, writeCount;

int setGain(double *buf, int length, int gainFac);
int reverse(double *buf, int length);
int reverse2(double *buf, double *temp, int length);
int normalize(double *buf, int length);

int main(int argc, const char *argv[]) {

	double *inBuf, *outBuf;

	if(argc<4) {
		cout << "Please type an input file, an output file, and a gain factor" << endl;
		return 0;
	}
	// Open the input file
	if(! (infile=sf_open(argv[1], SFM_READ, &sfInInfo))) {
		cout << "Not able to open the input file." << endl;
		cout << "Application will now close." << endl;
		sf_error(NULL);
		return 1;
	}

	// Examine the input format information
	cout << "The number of input frames is " << sfInInfo.frames << "." << endl;
	cout << "The number of input channels is " << sfInInfo.channels << "." << endl;
	cout << "The sample rate is " << sfInInfo.samplerate << "." << endl;
	cout << "The input file format is" << sfInInfo.format << "." << endl;

	// Set up the output file format
	sfOutInfo.frames = sfInInfo.frames;
    sfOutInfo.channels = sfInInfo.channels;
    sfOutInfo.samplerate = sfInInfo.samplerate;
    sfOutInfo.format = sfInInfo.format;

	// Open the output file
	if(! (outfile=sf_open(argv[2], SFM_WRITE, &sfOutInfo))) {
		cout << "Not able to open the output file." << endl;
		cout << "Application will now close." << endl;
		sf_error(NULL);
		return 1;
	}

	// Allocate input and output buffers
	inBuf = new double[sfInInfo.frames*sfInInfo.channels];
	outBuf = new double[sfInInfo.frames*sfInInfo.channels];

	// Read audio data from input file
	readCount = sf_read_double(infile, inBuf, sfInInfo.frames*sfInInfo.channels);
	cout << "The read count is " << readCount << endl;

	// Copy and reverse the audio samples
	reverse2(inBuf, outBuf, sfInInfo.frames*sfInInfo.channels);
	normalize(outBuf, sfInInfo.frames*sfInInfo.channels);
	// Set the output gain
	setGain(outBuf, sfInInfo.frames*sfInInfo.channels, atof(argv[3]));

	// Write the audio data to the output file
	writeCount = sf_write_double(outfile, outBuf, sfInInfo.frames*sfInInfo.channels);
	cout << "The write count is " << writeCount << endl;

	// Good housekeeping
	sf_close(infile);
	sf_close(outfile);
	delete[] inBuf;
	delete[] outBuf;

    return 0;
}

int setGain(double *buf, int length, int gainFac) {

	for(int ndx=0;ndx<length;ndx++){
		// buf[ndx] = buf[ndx] * gainFac;
		buf[ndx] *= gainFac;
	}

	return 0;
}

int reverse(double *buf, int length) {
	double *temp;

	temp = new double(length);
	
	for(int ndx=0;ndx<length;ndx++) {
		temp[length - 1 - ndx] = buf[ndx];
	}

	for(int ndx=0;ndx<length;ndx++) {
		buf[ndx] = temp[ndx];
	}

	return 0;
}

// Make sure that temp is already allocated

int reverse2(double *buf, double *temp, int length) {
	
	for(int ndx=0;ndx<length;ndx++) {
		temp[length - 1 - ndx] = buf[ndx];
	}

	return 0;
}

int normalize(double *buf, int length) {

    double peakAmp = 0.0;

    for(int ndx=0;ndx<length;ndx++) {
        if(buf[ndx]>peakAmp) {
            peakAmp = buf[ndx];
        }
    }
    for(int ndx=0;ndx<length;ndx++) {
        buf[ndx] *= 1.0/peakAmp;
    }
	return 0;
}