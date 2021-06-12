// This program will generate powers of 2 and their decibel equivalents
// In other words, 2^0 is 1, 2^1 is 2, etc

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, const char *argv[]) {
    int npowers = 0;
    long int powerof2 = 0;
    double dB = 0.0;
    const int base = 2; // Once set, this cannot be changed.
    int ndx = 0;
    // Prompt user 

    cout << endl;

    cout << "How many powers of two would you like to calculate? (1 or above) " << endl;
    cin >> npowers;
    // pow(base, exp)
    // The decibel equivalent is 20 * log10 (x)

    while(ndx<=npowers) {
        // Calculate the power of 2 
        powerof2 = pow(base, ndx);

        // Calculate the dB equivalent
        dB = 20 * log10(powerof2);

        // Print it. the \t is an escape code to add a tab
        cout << "2 to " << ndx++ << " is equal to " << powerof2 << ". \tThe decibel equivalent is " << setprecision(10) << dB << endl;
    }

    return 0;
}