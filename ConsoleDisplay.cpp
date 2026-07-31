#include "ConsoleDisplay.h"
#include "HangmanGame.h"
#include <iostream>

using namespace std;

void ConsoleDisplay::showMainMenu()
{
    cout << "==============================================================" << endl;
    cout << endl;
    cout << "                        HANGMAN" << endl;
    cout << endl;
    cout << "==============================================================" << endl;
    cout << endl;
    cout << "            Welcome to the Hangman Game" << endl;
    cout << endl;
    cout << "                    MAIN MENU" << endl;
    cout << endl;

    cout << endl;
    cout << "                [1] Play Hangman" << endl;
    cout << "                [2] How to Play" << endl;
    cout << "                [3] Exit" << endl;
    
    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your choice [1-3]: ";
}

void ConsoleDisplay::showHowToPlay(){
    cout << "==============================================================" << endl;
    cout << endl;
    cout << "                        HANGMAN" << endl;
    cout << endl;
    cout << "==============================================================" << endl;
    cout << endl;
    cout << "                    HOW TO PLAY" << endl;
    cout << endl;

    cout << "OBJECTIVE" << endl;
    cout << "Complete the hidden word before making 4 wrong letter guesses." << endl;
    cout << endl;

    cout << "GAME MODES" << endl;
    cout << "Solo       - Play alone." << endl;
    cout << "Two-Player - Turns change after a wrong letter." << endl;
    cout << endl;

    cout << "INSTRUCTIONS" << endl;
    cout << "1. Choose: Fruits, Countries, or Colours." << endl;
    cout << "2. Guess one letter or the complete word." << endl;
    cout << "3. Correct letter: +10 points and guess again." << endl;
    cout << "4. Wrong letter: lose 1 attempt." << endl;
    cout << "5. Correct word: +50 bonus points." << endl;
    cout << "6. Wrong word: game lost." << endl;
    cout << endl;

    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
    cout << "[1] Back to the Main Menu" << endl;
    cout << "Enter your choice: ";
}

void ConsoleDisplay::showGameModeMenu(){
    cout << "==============================================================" << endl;
    cout << endl;
    cout << "                        HANGMAN" << endl;
    cout << endl;
    cout << "==============================================================" << endl;
    cout << endl;
    cout << "                  SELECT GAME MODE" << endl;
    cout << endl;

    cout << endl;
    cout << "                [1] Solo" << endl;
    cout << "                [2] Two-Player" << endl;
    cout << "                [3] Back to the Main Menu" << endl;

    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your choice [1-3]: ";
}