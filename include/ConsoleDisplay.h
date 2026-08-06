#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H

#include <string>

using namespace std;

class ConsoleDisplay{
    public:
    // Displays the main menu
    void showMainMenu();

    // Displays the game instructions
    void showHowToPlay();

    // Displays the game mode selection menu
    void showGameModeMenu();

    // Displays the topic selection menu
    void showTopicMenu();

    // Displays the confirmation screen before leaving the game
    void showLeaveConfirmation();

    // Displays the current gameplay screen
    void showGameScreen(
        string playerName,
        string mode,
        string topic,
        string displayedWord,
        int score,
        int attemptsLeft
    );
};

#endif