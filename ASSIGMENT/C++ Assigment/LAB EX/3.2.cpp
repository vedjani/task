#include <iostream>
#include <cstdlib>  
#include <ctime>     
using namespace std;

int main() {
    srand(time(0)); 
    int secretNumber = rand() % 100 + 1; 
    int guess;

    cout << "Guess the number (between 1 and 100): " << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess == secretNumber) {
            cout << "Correct! You guessed the number!" << endl;
            break; 
        }
        else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        }
        else {
            cout << "Too low! Try again." << endl;
        }
    }

    return 0;
}
