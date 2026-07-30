#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H

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
    void showWinResult(HangmanGame game);
    void showGameOver(HangmanGame game);
};

#endif