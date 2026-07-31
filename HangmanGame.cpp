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
    int option;

    do{
        display.showGameModeMenu();
        cin >> option;

        if (option == 1){
            gameMode = new SoloMode();
        }
        else if (option == 2){
            gameMode = new TwoPlayerMode();
        }
        else if (option == 3){
            cout << "Returning to the Main Menu..." << endl;
            return;
        }
        else{
            cout << "Invalid option. Please enter a number from 1 to 3." << endl;
        }

    } while (option < 1 || option > 3);

    if (gameMode != nullptr){
        cout << "Selected mode: "
             << gameMode->getModeName()
             << endl;
    }
}

void HangmanGame::setUpPlayers(){
    // Will be implemented later
}

