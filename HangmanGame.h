#ifndef HANGMANGAME_H
#define HANGMANGAME_H
#include "ConsoleDisplay.h"
#include "WordBank.h"
#include <string>
#include <set>
#include <vector>
#include "Player.h"

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

    vector<Player> players;

    public:
    HangmanGame();
    void startGame();
    void selectGameMode();
    void setUpPlayers();
    void selectTopic();
    void guessLetter();
    bool checkLetterGuess(char letter);
    void revealLetter(char letter);

};

#endif