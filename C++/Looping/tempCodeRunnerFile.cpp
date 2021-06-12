#include <iostream>

using namespace std;

int main (int argc, const char *argv[]) {

int ndx = 100;
// This is not an infinite loop
while(ndx>=0) {
    cout << ndx-- << endl;
    // cout << (ndx = ndx + 1) << endl;
    // cout << (ndx += 1) << endl;

}
    return 0;
}