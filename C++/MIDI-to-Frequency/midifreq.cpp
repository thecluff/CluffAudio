#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Problem: The range of MIDI note numbers is 0-127 (128 in all)
// Each represents a specific frequency
// What is the frequency of each MIDI note number?

// What is equal temperament and why is it important for the purpose of this project?
// How, if we know the freqency of one note, such as A440, do we calculate the frequency of another note one half step away?

// If we multiply some frequency f by some other number, what would that other number be if we wanted the octave above f?
// What number, x, would equal 2 if we multiplied x*x*x*x*x*x*x*x*x*x*x*x or x^12?
// The 12th root of 2 

int main(int argc, const char * argv[]) {
    const double A440 = 440.0;

    const double magicInterval = pow(2,1.0/12);
    const double cAboveA440 = A440 * pow(magicInterval, 3);
    const double lowestC = cAboveA440 * pow(2,-6);

    cout << setprecision(14) << "The twelfth root of 2 is " << magicInterval << endl;
    cout << setprecision(14) << "The frequency of Bb above A440 is " << A440 * magicInterval << endl;
    cout << setprecision(14) << "The frequency of C above A440 is " << cAboveA440 << endl;
    cout << setprecision(14) << "The frequency of the lowest C is " << lowestC << endl;
    
    return 0;
}