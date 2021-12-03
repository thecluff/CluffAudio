#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 4.0 * atan(1.0);
const int nSamps = 8;
double freq = 1.0;
const double amp = 0.5;
double phase = PI/2;     // Phase will be in radians
double *buffer;         // A buffer is a place to hold samples

// The two main tasks in this program are to 1) generate a sequence of waveform samples
// and 2) display those sample values in the console.

int genWvfrm(int nSamps, double freq, double amp, double phase, double *buf);
int displayWvfrm(int nSamps, double *buf);

int main(int argc, const char * argv[]) {
    buffer = new double[nSamps];
    
    // Generate waveform
    genWvfrm(nSamps, freq, amp, phase, buffer );

    // Display waveform
    displayWvfrm(nSamps, buffer);

    return 0;
}

int genWvfrm(int nSamps, double freq, double amp, double phase, double *buf) {
  
   // Generate and store sample values
    for(int ndx=0;ndx<nSamps;ndx++){
        buffer[ndx]  = amp * sin(freq*2*PI*ndx/nSamps + phase);
    }

   return 0; 
}

int displayWvfrm(int nSamps, double *buf) {

    // Display values in the buffer
    for(int ndx=0;ndx<nSamps;ndx++){
        cout << ndx << "\t\t" << buffer[ndx] << endl;

    }

    return 0;
}


// Study functions: function signature - parameters, return value, how to call when we've defined it
// For loops
// Name, return type, parameter, body

// Any tone has Frequency, phase, amplitude
