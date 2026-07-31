#include "HangmanGame.h"
#include "SoloMode.h"
#include "TwoPlayerMode.h"
#include <iostream>

HangmanGame::HangmanGame(){
    secretWord = "";
    displayedWord = "";
    selectedTopic = "";
    gameMode = nullptr;
    currentPlayerIndex = 0;
    gameOver = false;
}

void HangmanGame::startGame(){
    selectGameMode();
}

void HangmanGame::selectGameMode(){
    display.showGameModeMenu();

    int option;
    cin >> option;

    if (option == 1){
        gameMode = new SoloMode();
    }
    else if (option == 2){
        gameMode = new TwoPlayerMode();
    }
    if (gameMode != nullptr){
        cout << "Selected mode: "
             << gameMode->getModeName()
             << endl;
    }
}

void HangmanGame::setUpPlayers(){
    // Will be implemented later
}

