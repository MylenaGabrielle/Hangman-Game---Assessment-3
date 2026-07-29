#include "Player.h"

Player::Player(string playerName){
    name = playerName;
    score = 0;
    attemptsLeft = 4;
}

string Player::getName(){
    return name;
}

void Player::updateScore(int points){
    score += points;
}

int Player::getScore(){
    return score;
}

void Player::decreaseAttempts(){
    attemptsLeft = attemptsLeft - 1;
}

int Player::getAttemptsLeft(){
    return attemptsLeft;
}

void Player::resetPlayer(){
    score = 0;
    attemptsLeft = 4;
}