#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]){
    // Capture input from command line using argc and argv
    // ./decibel 0 5
    // argc - count
    // argv - vector

    cout << "The first CL parameter is " << atoi(argv[1]) << ". " << endl;
    cout << "The second CL parameter is " << atoi(argv[2]) << ". " << endl;
    // Branch to one of either calculating dB from a linear amplitude
    // Or a linear amplitude from dB

    if(atoi(argv[1])==0) {
        cout << "Calculate dB" << endl;
        cout << setprecision(12) << 20 * log10(atoi(argv[2])) << endl;
        // cout << "The log, base10 of 13 is " << setprecision(12) << log10(13) << endl;
        // cout << "In other words, 10 to the power of 1.11394 is 13." << endl;
    } 
    else {
        cout <<"Calculate linear amplitude" << endl;
        // cout << "To calculate the antilog is to use pow()" << endl;
        // cout << "The antilog of 1.11394 is " << pow(10, 1.11394) << endl;
        cout << setprecision(12) << pow(10, 0.05 * atoi(argv[2])) << endl;
    }
    return 0;

}