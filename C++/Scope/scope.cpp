#include <iostream>

using namespace std;

// These are global variables
int gVar1 = INT_MAX;
signed int gVar2 = -1200;
unsigned int gVar3 = INT_MAX * 2 + 1 -1200;

int main(int argc, const char *argv[])
{
    // The parameters argc and argv allow communication with
    // the program from the command line.

    {
        // This is a new block and we can use blocks to demonstrate scope.
        int a = 100;
        cout << "This is value a: " << a << endl;
        cout << "This is value gVar1: " << gVar1 << endl;

    }
    {
        // This is another block
        int b = 1000;
        cout << "This is value b: " << b << endl;
        cout << "This is value gVar2: " << gVar2 << endl;
        cout << "This is value gVar3: " << gVar3 << endl;

    }

    return 0;
}