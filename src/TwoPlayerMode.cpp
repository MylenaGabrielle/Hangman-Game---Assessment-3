#include "TwoPlayerMode.h"

// Returns the name of the Two-Player game mode
string TwoPlayerMode::getModeName(){
    return "Two-Player";
}

// Switches between Player 1 and Player 2
int TwoPlayerMode::switchPlayer(int currentPlayer){
    if (currentPlayer == 0){
        return 1;
    }
    else{
        return 0;
    }
}