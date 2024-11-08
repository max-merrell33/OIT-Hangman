#ifndef GAME
#define GAME

#include <cstdlib>
#include <ctime>

#include "display.h"

#define MAX_LIVES 6
#define NUM_WORDS 10

const string wordList[NUM_WORDS] = {"string", "galaxy", "melon", "purple", "television", "shoes", "marathon", "squirrel", "table", "pumpkin"};

string getRandomWord();

bool isValidInput(string guess, string* err);

bool isCorrectGuess(char guess);

bool playerHasWon();

void gameLoop();

void postGameMenu(string postGamePrompt);







#endif