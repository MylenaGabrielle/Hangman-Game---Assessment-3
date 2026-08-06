#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include "ConsoleDisplay.h"
#include "Player.h"
#include "WordBank.h"

#include <set>
#include <string>
#include <vector>

using namespace std;

class GameMode;

class HangmanGame{
private:
    string secretWord;
    string displayedWord;
    string selectedTopic;

    GameMode* gameMode;

    set<char> guessedLetters;
    int currentPlayerIndex;

    ConsoleDisplay display;
    WordBank wordBank;
    vector<Player> players;

public:
    HangmanGame();
    ~HangmanGame();

    // Main game control
    void run();
    void startGame();

    // Game setup
    void selectGameMode();
    void setUpPlayers();
    void selectTopic();

    // Guess handling
    void guessLetter();
    void guessCompleteWord();
    bool checkLetterGuess(char letter);
    void revealLetter(char letter);

    // Game status
    bool checkWin();
    bool checkGameOver();

    // Display support
    void showGuessedLetters();
};

#endif