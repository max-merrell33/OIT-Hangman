#include "../include/display.h"

void displayStats(vector<char> guesses, int correct, int incorrect) {
    cout << "Number of Guesses: " << guesses.size() << endl;
    cout << "Correct: " << correct << "   Incorrect: " << incorrect << endl;
}

void displayVisual(int livesLeft, vector<char> guesses) {
    switch (livesLeft) {
        case 1:
            cout << "      ------- " << endl;
            cout << "      |     | " << endl;
            cout << "      O     | " << endl;
            cout << "     /|\\    | " << endl;
            cout << "     /      | " << endl;
            cout << "            | " << endl;
            cout << "     =========" << endl << endl << endl;

            break;
        case 2:
            cout << "      ------- " << endl;
            cout << "      |     | " << endl;
            cout << "      O     | " << endl;
            cout << "     /|\\    | " << endl;
            cout << "            | " << endl;
            cout << "            | " << endl;
            cout << "     =========" << endl << endl << endl;

            break;
        case 3:
            cout << "      ------- " << endl;
            cout << "      |     | " << endl;
            cout << "      O     | " << endl;
            cout << "     /|     | " << endl;
            cout << "            | " << endl;
            cout << "            | " << endl;
            cout << "     =========" << endl << endl << endl;

            break;
        case 4:
            cout << "      ------- " << endl;
            cout << "      |     | " << endl;
            cout << "      O     | " << endl;
            cout << "      |     | " << endl;
            cout << "            | " << endl;
            cout << "            | " << endl;
            cout << "     =========" << endl << endl << endl;

            break;
        case 5:
            cout << "      ------- " << endl;
            cout << "      |     | " << endl;
            cout << "      O     | " << endl;
            cout << "            | " << endl;
            cout << "            | " << endl;
            cout << "            | " << endl;
            cout << "     =========" << endl << endl << endl;

            break;
        case 6:
            cout << "      ------- " << endl;
            cout << "      |     | " << endl;
            cout << "            | " << endl;
            cout << "            | " << endl;
            cout << "            | " << endl;
            cout << "            | " << endl;
            cout << "     =========" << endl << endl << endl;

            break;
        default:
            cout << "      ------- " << endl;
            cout << "      |     | " << endl;
            cout << "      O     | " << endl;
            cout << "     /|\\    | " << endl;
            cout << "     / \\    | " << endl;
            cout << "            | " << endl;
            cout << "     =========" << endl << endl << endl;

            break;
    }
}

// COULD IMPROVE AND make more effecient
void displayString(string word, vector<char> guesses) {
    string displayString;
    vector<char> prevGuesses;


    // traverse the guesses, adding the letter to the previous guesses if the letter is not in the word (the incorrect guesses)
    for (int i = 0; i < guesses.size(); i++) {
        bool isInWord = false;
        for (char c : word) {
            if (c == guesses[i]) {
                isInWord = true;
            }
        }

        if (!isInWord) {
            prevGuesses.push_back(guesses[i]);
        }
    }

    //Print out the previous incorrect guesses
    cout << "Incorrect Guesses: ";
    for (char guess : prevGuesses) {
        cout << guess << " ";
    }
    cout << endl << endl;

    // traverse the word, printing the letter or a '_' if the letter has not been guessed
    for (char c : word) {
        bool hasBeenGuessed = false;
        
        for (int i = 0; i < guesses.size(); i++) {
            if (guesses[i] == c) {
                hasBeenGuessed = true;
            }
        }

        if (hasBeenGuessed)
            displayString += c;
        else
            displayString += '_';
        
        displayString += ' ';

    }
    cout << displayString << endl << endl;
}

void displayPrompt(string prompt) {
    cout << prompt;
}

void displayAll(int livesLeft, string word, vector<char> guesses, string prompt, int correct, int incorrect) {
    system("clear");
    displayStats(guesses, correct, incorrect);
    displayVisual(livesLeft, guesses);
    displayString(word, guesses);
    displayPrompt(prompt);
}

void displayHowToPlay() {
    system("clear");
    //TODO 
    cout << "THESE ARE THE INSTRUCTIONS" << endl << endl;
    cout << "Press enter to go back to menu" << endl << endl;

}