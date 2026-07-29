#include "TwoPlayerMode.h"

string TwoPlayerMode::getModeName(){
    return "Two-Player";
}

int TwoPlayerMode::switchPlayer(int currentPlayer){
    if (currentPlayer == 0){
        return 1;
    }
    else{
        return 0;
    }
}