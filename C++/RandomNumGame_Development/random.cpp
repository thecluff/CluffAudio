#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int main(int argc, const char *argv[]) {
    int rand_num;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(1,10);

    rand_num = distribution(generator);
    cout << rand_num << endl;
    return 0;
}