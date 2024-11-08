#include <iostream>
#include <string>

#include "include/display.h"
#include "include/game.h"

void howToPlayMenu();

void beforeGameMenu(string prompt) {
    system("clear");

    char userChoice;

    cout << "Welcome to HANGMAN!" << endl << endl;
    cout << "[1] New Game" << endl;
    cout << "[2] How to Play" << endl;
    cout << "[3] Quit" << endl << endl;

    cout << prompt;
    cin >> userChoice;

    if (userChoice == '1') {
        gameLoop();
        beforeGameMenu("Enter: ");
    } else if (userChoice == '2') {
        howToPlayMenu();
    } else if (userChoice == '3') {
        return;
    } else {
        beforeGameMenu("Invalid input. Enter: ");
    }
}


void howToPlayMenu() {
    string userChoice;

    displayHowToPlay();

    cin.ignore();
    getline(cin, userChoice);

    beforeGameMenu("Enter: ");

}

int main() {

    beforeGameMenu("Enter: ");

    return 0;
}



