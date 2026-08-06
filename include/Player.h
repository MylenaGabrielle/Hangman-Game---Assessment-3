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
    // Creates a new player
    Player(string playerName);

    // Getters

    // Returns the player's name
    string getName();
    // Returns the player's current score
    int getScore();
    // Returns the player's remaining attempts
    int getAttemptsLeft();
    
    // Player actions

    // Adds points to the player's score
    void updateScore(int points);
    // Decreases the player's remaining attempts
    void decreaseAttempts();
};

#endif