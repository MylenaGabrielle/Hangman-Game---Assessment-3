#ifndef TWOPLAYERMODE_H
#define TWOPLAYERMODE_H

#include "GameMode.h"

class TwoPlayerMode : public GameMode{
public:
    string getModeName() override;
    int switchPlayer(int currentPlayer) override;
};

#endif