#ifndef DISPLAY
#define DISPLAY

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 
 * 
 * @param 
 * @param 
 * @param 
 */
void displayStats(vector<char> guesses, int correct, int incorrect);

/**
 * @brief 
 * 
 * @param 
 * @param 
 */
void displayVisual(int livesLeft, vector<char> guesses);

/**
 * @brief 
 * 
 * @param 
 * @param 
 */
void displayString(string word, vector<char> guesses);

/**
 * @brief 
 * 
 * @param 
 */
void displayPrompt(string prompt);

/**
 * @brief 
 * 
 * @param 
 * @param 
 * @param 
 * @param 
 * @param 
 * @param 
 */
void displayAll(int livesLeft, string word, vector<char> guesses, string prompt, int correct, int incorrect);

/**
 * @brief 
 */
void displayHowToPlay();

#endif