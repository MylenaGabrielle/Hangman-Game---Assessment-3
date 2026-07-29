#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player{
    private:
    string name;
    int score;
    int attemptsLeft;



    public:
    Player(string playerName);

    string getName();
    int getScore();
    int getAttemptsLeft();
    
    void updateScore(int points);
    void decreaseAttempts();
    void resetPlayer();
};

#endif