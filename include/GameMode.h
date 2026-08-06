#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <string>

using namespace std;

// Abstract base class for all game modes
class GameMode{
    public:
    // Returns the name of the selected game mode
    virtual string getModeName() = 0;

    // Switches to the next player
    virtual int switchPlayer(int currentPlayer) = 0;

    // Virtual destructor
    virtual ~GameMode() {}
};

#endif