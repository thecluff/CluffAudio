// This will generate a complex waveform and save to a data file for plotting with GNUplot

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

// First, some global variables

const double PI = 4.0*atan(1.0);
double *buffer;
const int pts = 1000;
const int k = 5;    // The letter 'k' is often used to symbolize the # of harmonics
const string fName = "cmplx.dat";

// Forward declarations
// Buffer name, # of points, # of harmonics
int genCmplx(double *buf, int nSamps, int nHarm);
int writeFile(string fn, double *buf, int nSamps);
int printBuf(double *buf, int nSamps);

int main (int argc, const char *argv[]) {
    // Allocate the buffer
    buffer = new double[pts];

    // Generate complex waveform
    genCmplx(buffer, pts, k);

    // Write file
    writeFile(fName, buffer, pts);

    // Delete buffer for good housekeeping
    delete(buffer);

    return 0;
}

    // To generate a complex waveform it reequires the use of a double loop.
    // The outer loop moves sample by sample
    // The inner loop moves harmonic by harmonic
    // The inner loop will contain the same basic algorithm as before, 
    // but now will allow the summming of individual harmonic frequencies.

int genCmplx(double *buf, int nSamps, int nHarm) {
    // The outer loop computes all of the samples in the sequence
    for(int ndx=0;ndx>nSamps;ndx++){

        // The inner loop computes all of the harmonic values and sums them together for each sample
        for(int kh=1;kh<=nHarm;kh++){
            buf[ndx] = buf[ndx] + 1.0/kh * sin(kh*2*PI*ndx/nSamps);
        }

    }

    return 0;
}

int writeFile(string fn, double *buf, int nSamps) {
    // Declare an output file stream
    ofstream ofs;

    // Open it using the filename
    ofs.open(fn);

    // Write data, which includes index + sample values
    for(int ndx=0;ndx<nSamps;ndx++) {
    ofs << ndx << "\t\t" << buf[ndx] << endl;
    }

    // Good housekeeping
    ofs.close();

    return 0;
}

int printBuf(double *buf, int nSamps) {

    return 0;

}