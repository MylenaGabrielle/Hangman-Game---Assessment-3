#ifndef TWOPLAYERMODE_H
#define TWOPLAYERMODE_H

#include "GameMode.h"

// Represents the two-player game mode
class TwoPlayerMode : public GameMode{
    public:
    // Returns the name of the Two-Player game mode
    string getModeName() override;

    // Switches between Player 1 and Player 2
    int switchPlayer(int currentPlayer) override;
};

#endif