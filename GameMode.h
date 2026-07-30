#ifndef GAMEMODE_H
#define GAMEMODE_H
#include <string>

using namespace std;

class GameMode{
public:
    virtual string getModeName() = 0;
    virtual int switchPlayer(int currentPlayer) = 0;
    virtual ~GameMode() {};
};


#endif