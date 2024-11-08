#ifndef DISPLAY
#define DISPLAY

#include <iostream>
#include <vector>

using namespace std;

void displayStats(vector<char> guesses, int correct, int incorrect);

//TODO ADD comments
void displayVisual(int livesLeft, vector<char> guesses);

void displayString(string word, vector<char> guesses);

void displayPrompt(string prompt);

void displayAll(int livesLeft, string word, vector<char> guesses, string prompt, int correct, int incorrect);

void displayHowToPlay();

#endif