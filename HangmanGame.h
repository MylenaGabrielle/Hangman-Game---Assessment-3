#ifndef HANGMANGAME_H
#define HANGMANGAME_H
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

    public:
    HangmanGame();

};

#endif