#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H
#include <string>

using namespace std;

class HangmanGame;

class ConsoleDisplay{
public:
    void showMainMenu();
    void showHowToPlay();
    void showGameModeMenu();
    void showTopicMenu();
    void showGameStatus(HangmanGame game);
    void showCorrectGuess();
    void showIncorrectGuess();
    void showLeaveConfirmation();

    //We are not using these two functions
    void showWinResult(HangmanGame game);
    void showGameOver(HangmanGame game);

    void showGameScreen(
        string playerName,
        string mode,
        string topic,
        string displayedWord,
        int score,
        int attemptsLeft);


};

#endif