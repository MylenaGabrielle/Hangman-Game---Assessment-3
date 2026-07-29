#ifndef SOLOMODE_H
#define SOLOMODE_H

#include "GameMode.h"

class SoloMode : public GameMode{
    public:
    string getModeName() override;
    int switchPlayer(int currentPlayer) override;
};

#endif