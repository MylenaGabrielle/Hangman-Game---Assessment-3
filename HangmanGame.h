#ifndef HANGMANGAME_H
#define HANGMANGAME_H
#include "ConsoleDisplay.h"
#include "WordBank.h"
#include <string>
#include <set>

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
    bool gameOver;

    ConsoleDisplay display;
    WordBank wordBank;

    public:
    HangmanGame();
    void startGame();
    void selectGameMode();
    void setUpPlayers();

};

#endif