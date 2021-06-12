#include <iostream>
#include <iomanip>
#include <cmath>

// Generate the sample values for a very simple sine wave
// The most basic elements of any signal are its
// apmlitude, frequency, and phase.
// Amplitude is wave height 
// Frequency is the number of cycles per second
// Phase is wave angle
// Generate one cycle of a sine wave with 8 samples
// A sample is a momentary amplitude

using namespace std;

const double PI = 4.0 * atan(1.0);
const int nSamps = 8;
const double amp = 0.5;
double phase = PI/2;     // Phase will be in radians
double *buffer;         // A buffer is a place to hold samples

// Objective is to generate 8 sample values that collectively trace a sine wave,
// temporarily store those samples in a buffer, then print the values to the console.
// One loop is for generating and storing the sample values
// The second loop is for displaying the contents of the buffer

int main(int argc, const char * argv[]) {
    // Allocate the buffer
    buffer = new double[nSamps];
    // Generate and store sample values
    for(int ndx=0;ndx<nSamps;ndx++){
        buffer[ndx]  = amp * sin(2*PI*ndx/nSamps + phase);
    }

    // Display values in the buffer

    for(int ndx=0;ndx<nSamps;ndx++){
        cout << ndx << "\t\t" << buffer[ndx] << endl;

    }

    return 0;

}