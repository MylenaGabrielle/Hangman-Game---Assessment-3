#include "Player.h"

// Creates a new player with the default score and attempts
Player::Player(string playerName){
    name = playerName;
    score = 0;
    attemptsLeft = 4;
}

// Returns the player's name
string Player::getName(){
    return name;
}

// Adds points to the player's score
void Player::updateScore(int points){
    score += points;
}

// Returns the player's current score
int Player::getScore(){
    return score;
}

// Decreases the player's remaining attempts
void Player::decreaseAttempts(){
    attemptsLeft--;
}

// Returns the player's remaining attempts
int Player::getAttemptsLeft(){
    return attemptsLeft;
}

