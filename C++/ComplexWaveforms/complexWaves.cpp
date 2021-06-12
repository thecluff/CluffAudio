#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <sndfile.h>

using namespace std;

int getChoice();
int SR = 4411;
int genTriangle(double *buf, int nSamps, int nHarms, double freqs, double amps, double phs);
void normalize(double *buf, int size);
double PI = 4.0 * atan(1.0);

int main(int argc, const char *argv[]) {

SNDFILE *outfile;
SF_INFO sfOutInfo;
sf_count_t writeCount;

double *buffer;
double amp = 0.75;
double freq = 440.0;
int numHarms = 15;
double length = 1.0;
int numSamps = length * SR;
double phase = 0.0;
int choice;

buffer = new double[numSamps];

cout << "If you're reading this, its safe to assume that libsndfile is installed" << endl;
cout << "This program will make a tone that is " << length << "seconds long at a frequency of " << freq << "." << endl;
choice = getChoice();

sfOutInfo.frames = numSamps;
sfOutInfo.samplerate = SR;
sfOutInfo.channels = 1;
sfOutInfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

if(! (outfile = sf_open("triangle440.wav", SFM_WRITE, &sfOutInfo)))
cout << "Not able to open output file triangle440.wav." << endl;
sf_perror(NULL);
return 1;

switch(choice) {
    case 1: // genSine(buffer, numSamps, amp, freq, phase);
        break;
    case 2: // genSaw
        break;
    case 3: //genSquare
        break;
    case 4: genTriangle(buffer, numSamps, numHarms, freq, amp, phase);
}


normalize(buffer, numSamps);

writeCount = (int) sf_write_double(outfile, buffer, numSamps);
cout << "The number of samples in the buffer is " << numSamps << "." << endl;
cout << "The number of samples written to file is " << writeCount << "." << endl;

delete[] buffer;
sf_close(outfile);
return 0;
}

int getChoice () {
	int choice = 0;

	cout << "Please select a waveform type." << endl;
	cout << "1. Sine" << endl;
	cout << "2. Saw" << endl;
	cout << "3. Square" << endl;
	cout << "4. Triangle" << endl;
	cin >> choice;

	return choice;
}

int genTriangle(double *buf, int nSamps, int nHarms, double freqs, double amps, double phs) {
    double sign = 1.0;

    for(int ndx=0;ndx<nSamps;ndx++) {

        for(int kh=1;kh<=nHarms;kh+=2) {
            buf[ndx] = buf[ndx] + sign * amps * (1.0/pow(kh,2) * sin(freqs*kh*2*PI*ndx/SR + phs));
            sign *= -1.0;
        }
    }
    return 0;
}

void normalize(double *buf, int size) {

    double peakAmp = 0.0;

    for(int ndx=0;ndx<size;ndx++) {
        if(buf[ndx]>peakAmp) {
            peakAmp = buf[ndx];
        }
    }
    for(int ndx=0;ndx<size;ndx++) {
        buf[ndx] *= 1.0/peakAmp;
    }
}
