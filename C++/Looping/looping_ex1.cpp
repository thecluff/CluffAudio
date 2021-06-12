#include <iostream>

using namespace std;

int main (int argc, const char *argv[]) {

int ndx = 0;
// This is not an infinite loop
while(ndx<=100) {
    cout << ndx++ << endl;
    // cout << (ndx = ndx + 1) << endl;
    // cout << (ndx += 1) << endl;

}
    return 0;
}