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