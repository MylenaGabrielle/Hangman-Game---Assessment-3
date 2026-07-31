#include "HangmanGame.h"
#include "SoloMode.h"
#include "TwoPlayerMode.h"

HangmanGame::HangmanGame(){
    secretWord = "";
    displayedWord = "";
    selectedTopic = "";
    gameMode = nullptr;
    currentPlayerIndex = 0;
    gameOver = false;
}

void HangmanGame::selectGameMode(){
    // Will be implemented later
}

void HangmanGame::setUpPlayers(){
    // Will be implemented later
}

