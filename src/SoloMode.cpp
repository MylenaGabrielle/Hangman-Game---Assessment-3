#include "SoloMode.h"

// Returns the name of the Solo game mode
string SoloMode::getModeName(){
    return "Solo";
}

// Keeps the same player in Solo mode
int SoloMode::switchPlayer(int currentPlayer){
    return currentPlayer;
}