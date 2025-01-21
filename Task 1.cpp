#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;   

int main() {
    
    srand(time(0));
    int randomNumber = rand() % 100 + 1; 

    int yourGuess = 0;

    cout << "hiii.... wlcome to game"<< endl;
    cout << "I have chosen a number between 1 and 100. Try to guess it\n";

    
    while (true) {
       cout<< "Enter your guess: ";
      cin>> yourGuess;

        if (yourGuess < randomNumber) {
            cout << "Too low! guess another number\n";
        } else if (yourGuess > randomNumber) {
            cout << "Too high! guess another number.\n";
        } else {
        cout << "Congratulations! You guessed the correct number: " << randomNumber << "\n";
            break; 
        }
    }

    return 0;
}

