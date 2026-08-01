#include "ConsoleDisplay.h"
#include "HangmanGame.h"
#include <iostream>
#include <string>

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

void ConsoleDisplay::showTopicMenu(){
    cout << "==============================================================" << endl;
    cout << endl;
    cout << "                        HANGMAN" << endl;
    cout << endl;
    cout << "==============================================================" << endl;
    cout << endl;
    cout << "                    SELECT TOPIC" << endl;
    cout << endl;

    cout << endl;
    cout << "                [1] Fruits" << endl;
    cout << "                [2] Countries" << endl;
    cout << "                [3] Colours" << endl;
    cout << "                [4] Back" << endl;

    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your choice [1-4]: ";
}

void ConsoleDisplay::showLeaveConfirmation(){
    cout << "==============================================================" << endl;
    cout << endl;
    cout << "                        HANGMAN" << endl;
    cout << endl;
    cout << "==============================================================" << endl;
    cout << endl;
    cout << "            ARE YOU SURE YOU WANT TO LEAVE?" << endl;
    cout << endl;
    cout << "      Your current progress will be lost." << endl;

    cout << endl;
    cout << "          Return to the Main Menu?" << endl;
    cout << endl;
    cout << "                [1] Yes" << endl;
    cout << "                [2] No" << endl;
    
    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your choice [1-2]: ";
}

void ConsoleDisplay::showGameScreen(string playerName,
                                    string mode,
                                    string topic,
                                    string displayedWord,
                                    int score,
                                    int attemptsLeft){
    cout << "==================================================" << endl;
    cout << "                     HANGMAN" << endl;
    cout << "==================================================" << endl;

    cout << "Player: " << playerName << endl;
    cout << "Mode: " << mode << endl;
    cout << "Topic: " << topic << endl;
    cout << endl;

    cout << "Word: ";

    for (char letter : displayedWord){
        cout << letter << " ";
    }

    cout << endl << endl;

    cout << "Score: " << score << endl;
    cout << "Attempts Left: " << attemptsLeft << endl;
    cout << endl;

    cout << "[1] Guess a Letter" << endl;
    cout << "[2] Guess the Word" << endl;
    cout << "[3] Leave Game" << endl;
}