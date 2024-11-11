#ifndef GAME
#define GAME

#include <cstdlib>
#include <ctime>

#include "display.h"

#define MAX_LIVES 6
#define NUM_WORDS 10

const string wordList[NUM_WORDS] = {"string", "galaxy", "melon", "purple", "television", "shoes", "marathon", "squirrel", "table", "pumpkin"};

/**
 * @brief Returns a random word from the defined wordList above
 *
 * @return The random word as a string
 */
string getRandomWord();

/**
 * @brief Checks that the user input is a single char, is a letter, and has not already been guessed
 * 
 * @param guess The user input as a string
 * @param err If the input is invalid, assigns an error message telling the user what was invalid
 *
 * @return The random word as a string
 */
bool isValidInput(string guess, string* err);

/**
 * @brief 
 * 
 * @param 
 *
 * @return
 */
bool isCorrectGuess(char guess);

/**
 * @brief 
 *
 * @return 
 */
bool playerHasWon();

/**
 * @brief 
 */
void gameLoop();

/**
 * @brief 
 * 
 * @param
 */
void postGameMenu(string postGamePrompt);







#endif