// This program is a random number guessing game.
// The program will prompt the user for two numbers, and within those two numbers, generate a secret random number.
// The user will get three tries to guess the correct secret number. 
// The user can choose if they want to try again after correctly guessing it, or after three tries.
// If the user chooses to repeat, the program repeats. If not, the program ends.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
#include <chrono>

using namespace std;

int main(int argc, const char *argv[]) {
    const int base = 2; 

// Begin program header
    cout << endl;
    cout << "  sSSSs   d       b d sss     sss.   sss.   ##  " << endl;
    cout << " S     S  S       S S       d      d        ##  " << endl;
    cout << "S         S       S S       Y      Y        ##  " << endl;
    cout << "S         S       S S sSSs    ss.    ss.    ##  " << endl;
    cout << "S    ssSb S       S S            b      b   ##  " << endl;
    cout << " S     S   S     S  S            P      P       " << endl;
    cout << "   sss       sss    P sSSss ` ss'  ` ss'    ##  " << endl;
    cout << "                                                " << endl;
    cout << "           ----------------------------         " << endl;
    cout << "                                                " << endl;
    cout << "          Guess! - A Random Number Game         " << endl;
    cout << "         By Charlie Cluff, February 2019        " << endl;
    cout << "       DAT150 - Intro to Audio Programming      " << endl;
    cout << "                                                " << endl;
    cout << "           ----------------------------         " << endl;
    cout << "                                                " << endl;
    cout << "   Welcome! This is a random number game about  " << endl;
    cout << "     guessing a randomly generated number.      " << endl;
    cout << "                    Good luck!                  " << endl;
    cout << "                                                " << endl;
    cout << "︵‿︵‿︵‿︵‿︵︵‿︵‿︵‿︵‿︵︵‿︵‿︵‿︵‿︵︵‿︵‿" << endl;
    cout << endl;
// End program header

    int number1a;
    int number2a;

      char repeat = 'y';
  while( repeat == 'y'){

    cout << "Enter two numbers separated by a space. These two numbers will set the range in which the guessing will take place." << endl;
    cin >> number1a >> number2a;

    int rand_num;
    int guess1;
    int guess2;
    int guess3;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(number1a,number2a);

    rand_num = distribution(generator);

    cout << "Between those two numbers, guess the secret number. You only get three tries!" << endl;
    cout << "After three tries, if you haven't guessed the secret number, you can start over." << endl;

    cin >> guess1;

    if (guess1 < rand_num){
        cout << "Your guess is lower than the secret number. " << "Try again." << endl;
        cin >> guess2;
    if (guess2 < rand_num){
        cout << "Your guess is lower than the secret number. " << "Try again." << endl;
        cin >> guess3;
    if (guess3 < rand_num)
        cout << "Your guess is lower than the secret number. " << "The secret number is " << rand_num << "." << endl;
    else if (guess3 > rand_num) 
        cout << "Your guess is higher than the secret number. " << "The secret number is " << rand_num << "." << endl;
    else 
        cout << "Correct - you got it!" << "The secret number is " << rand_num << "." << endl;
        }
    else if (guess2 > rand_num){
        cout << "Your guess is higher than the secret number. " << "Try again." << endl;
        cin >> guess3;
    if (guess3 < rand_num)
        cout << "Your guess is lower than the secret number. " << "The secret number is " << rand_num << "." << endl;
    else if (guess3 > rand_num) 
        cout << "Your guess is higher than the secret number. " << "The secret number is " << rand_num << "." << endl;
    else 
        cout << "Correct - you got it!" << "The secret number is " << rand_num << "." << endl;
    }
    else 
        cout << "Correct - you got it!" << "The secret number is " << rand_num << "." << endl;
    }
    else if (guess1 > rand_num){ 
        cout << "Your guess is higher than the secret number. " << "Try again." << endl;
        cin >> guess2;
    if (guess2 < rand_num){
        cout << "Your guess is lower than the secret number. " << "Try again." << endl;
        cin >> guess3;
    if (guess3 < rand_num)
        cout << "Your guess is lower than the secret number. " << "The secret number is " << rand_num << "." << endl;
    else if (guess3 > rand_num) 
        cout << "Your guess is higher than the secret number. " << "The secret number is " << rand_num << "." << endl;
    else 
        cout << "Correct - you got it!" << "The secret number is " << rand_num << "." << endl;
        }
    else if (guess2 > rand_num){
        cout << "Your guess is higher than the secret number. " << "Try again." << endl;
        cin >> guess3;
    if (guess3 < rand_num)
        cout << "Your guess is lower than the secret number. " << "The secret number is " << rand_num << "." << endl;
    else if (guess3 > rand_num) 
        cout << "Your guess is higher than the secret number. " << "The secret number is " << rand_num << "." << endl;
    else 
        cout << "Correct - you got it!" << "The secret number is " << rand_num << "." << endl;
    }
    else 
        cout << "Correct - you got it!" << "The secret number is " << rand_num << "." << endl;
    }
    else 
        cout << "Correct - you got it!" << "The secret number is " << rand_num << "." << endl;

  cout<< "Do you want to repeat?(y/n):";
  cin>> repeat;
  }
    cin.get(); // This will end the program.
 
    return 0;
}