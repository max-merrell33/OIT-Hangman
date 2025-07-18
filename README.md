# Summary
My name is Max Merrell and this is a CLI Hangman game written in C++. This is my project for my BYU OIT application

---

# How to run
- Clone repository and `cd` into the directory 
    - Note: there is a large library included in the repository (more comments below) and the repository may take a while to clone
- `.\setup.ps1`
    - This will add the library to the PATH variable for the current terminal instance
    - If you receive an error running the script, try running `Set-ExecutionPolicy -Scope Process Unrestricted`. This will allow you to run scripts in this instance of the terminal.
- `make`
    - This will compile the code abd place the executable in \build\
- `make run`
    - This will run the executable in a new terminal window and close that window when the program exits

---

# File Structure
```
Hangman
|-build/
| |-hangman.exe
|
|-include/
| |-display.h
| |-game.h
|
|-src/
| |-display.cpp
| |-game.cpp
|
|-lib/
| |-mingw32
|
|-Makefile
|-main.cpp
|-setup.ps1
```

---

# External Dependencies: 
- mingw32 Library
    - Allows the program to run GNU commands on windows and allows for the compilation of the program using 'make'
    - Running setup.ps1 adds the library to the PATH variable and allows the 'make' commands to run

---

# Thought Process:
### Initial Thoughts
- I began by writing out the following notes
- 3 source files
```
    - Main.cpp - runs the welcome menu and begins the game loop
        - Welcome menu - 2 options (play game, how to play)
    - Display.cpp - contains all the code to display the hangman game
        - Display total number of guesses (correct/incorrect), hangman graphic, letters already guessed, and the word with blanks/correctly guessed letters
    - Game.cpp - contains the game loop and all of the game logic
        - Main game loop
            - Display
            - Receive and validate user input
            - If correct = Display new string, replacing spaces
            - Else = subtract from lives left, add letter to guesses
```

### Writing the code
- With this initial rough outline, I began writing display.cpp and experimenting with the design in the terminal.
- Once I had the visuals the way I wanted them, I wrote the functions that will make the visuals dynamic based on parameters such as the chosen word and the vector of guesses.
- I split the display up into various functions that made the file more organized and combined those functions in displayAll().
- Once the display was dynamic, I began writing the game logic in game.cpp.
- I wrote the main game loop that selected a random word, verified the user input, and updated the display.
- As I was writing this file, I realized that I was passing a lot of different variables into the displayAll() function and it was difficult to change every function call everytime I made a slight change to displayAll().
- I decided to make a struct and contain all the game variable there. I then created a method that passed all the necessary game variables, simplifying the program.
- Once the main game loop was working, I created the start menu, the instructions page and the post-game display. I added all these into main.cpp
- This wrapped up my code writing and the hangman terminal program worked great!

### Running on Windows
- All my academic classes and my hobby projects have been coded on my Macbook or on a university linux machine. I am much more familair with the UNIX style systems and so I wrote this project on my Macbook in C++.
- I assumed that Windows machines had a preinstalled C++ compiler like the Mac/Linux systems do, and when I used a Windows machine and tried to compile I was unpleasantly surprised.
- After doing some reading, I decided the easiest way to create a repository that included everything necessary to compile and run the code would be to include the MinGW library. I understand this makes the repository quite large and if I had more time, I would find a simpler way that did not require such a large library in the directory. 

---
# Future Features:

- The last step that I was doing when I ran out of time was the documentation of the code with comments. The first thing I would finish if I had more time would be the comments in the header files giving detailed descriptions about the functions. 
- Reorganize the before and after game menu so that the code to display the menus is located in display.cpp and the code is more uniformly organized
- Learn more about MinGW and other libraries that make compiling C++ code easier and more efficient, reducing the size of the project
- Create a way to keep score and/or average number of guesses over multiple different games
- 2 player mode where one user inputs the word and the other player plays the game using the input word
- This was a great project and I learned much while working on it!

---

# Time Spent on Project:
- 20 minutes - planning layout of project
- 40 minutes - writing display.cpp and how the visuals would look
- 40 minutes - writing game.cpp and writing the game logic
- 30 minutes - writing main.cpp and finishing the before/after game menus
- 70 minutes - configuring the program to run on Windows 
- 40 minutes - write README and finish documentation

**Total time: 4 hrs**
