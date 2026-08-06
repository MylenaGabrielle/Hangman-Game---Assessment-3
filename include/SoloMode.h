#ifndef SOLOMODE_H
#define SOLOMODE_H

#include "GameMode.h"

// Represents the single-player game mode
class SoloMode : public GameMode{
    public:
    // Returns the game mode name
    string getModeName() override;

    // Keeps the same player in Solo mode
    int switchPlayer(int currentPlayer) override;
};

#endif