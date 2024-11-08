#include "../include/game.h"


struct GameStats
{
    int livesLeft;
    string word;
    vector<char> guesses;
    int correctGuesses;
    int incorrectGuesses;
    bool isWin;

    void init() {
        livesLeft = MAX_LIVES;
        word = getRandomWord();
        guesses.clear();
        correctGuesses = 0;
        incorrectGuesses = 0;
        isWin = false;
    }

    int numGuesses() {
        return guesses.size();
    }

    void addGuess(char guess) {
        guesses.push_back(guess);
    }

    void displayGame(string prompt) {
        displayAll(livesLeft, word, guesses, prompt, correctGuesses, incorrectGuesses);
    }

};

GameStats game;

string getRandomWord() {
    srand(time(0));

    int randIndex = rand() % NUM_WORDS;

    return wordList[randIndex];
}

// one char and not already guessed and a letter
bool isValidInput(string guess, string* err) {
    // Checks that the input is one char
    if (guess.size() != 1) {
        *err = "Invalid input, 1 character max.";
        return false;
    }

    char guessChar = tolower(guess[0]);

    // Checks that the input is a letter
    if (!isalpha(guessChar)) {
        *err = "Invalid input, only letters are allowed.";
        return false;
    }

    // Checks that the letter has not already been guessed
    for (int i = 0; i < game.numGuesses(); i++) {
        if (guessChar == game.guesses[i]) {
            *err = "Invalid input, letter already guessed.";
            return false;
        }
    }
    
    return true;
}

bool isCorrectGuess(char guess) {
    for (char c : game.word) {
        if (guess == c)
            return true;
    }
    return false;
}

bool playerHasWon() {
    for (char c: game.word) {
        bool hasBeenGuessed = false;

        for (int i = 0; i < game.numGuesses(); i++) {
            if (game.guesses[i] == c)
                hasBeenGuessed = true;
        }

        if (!hasBeenGuessed) 
            return false;
    }
    return true;
}


void gameLoop() {
    game.init();
    string prompt = "Enter: ";

    while (!playerHasWon()) {

        game.displayGame(prompt);

        string userInput;
        cin >> userInput;

        string err;
        while (!isValidInput(userInput, &err)) {
            prompt = err + " Guess a letter: ";
            game.displayGame(prompt);
            cin >> userInput;
        }

        char userInputChar = tolower(userInput[0]);
        game.addGuess(userInputChar);

        if (isCorrectGuess(userInputChar)) {
            prompt = "Correct! Guess a letter: ";
            game.correctGuesses++;
        } else {
            prompt = "Incorrect. Guess a letter: ";
            game.incorrectGuesses++;
            game.livesLeft--;
        }
    }
    
    postGameMenu("Enter: ");
}

void postGameMenu(string postGamePrompt) {
    system("clear");

    char userChoice;

    string prompt = "Correct! The word is \"" + game.word + "\". It took you " + to_string(game.numGuesses()) + " guesses!";
    game.displayGame(prompt);

    cout << endl << endl;

    cout << "[1] Play again" << endl;
    cout << "[2] Exit" << endl << endl;

    cout << postGamePrompt;
    cin >> userChoice;

    if (userChoice == '1') {
        gameLoop();
    } else if (userChoice == '2') {
        return;
    } else {
        postGameMenu("Invalid input. Enter: ");
    }
}