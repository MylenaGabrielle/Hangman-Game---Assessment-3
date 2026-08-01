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

    if (gameMode == nullptr){
        return;
    }

    setUpPlayers();

    selectTopic();
    
    if (selectedTopic == ""){
        return;
    }
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
    players.clear();

    if (gameMode->getModeName() == "Solo"){
        players.push_back(Player("Player 1"));
    }
    else if (gameMode->getModeName() == "Two-Player"){
        players.push_back(Player("Player 1"));
        players.push_back(Player("Player 2"));
    }

    currentPlayerIndex = 0;
}

void HangmanGame::selectTopic(){
    int option;

    do{
        display.showTopicMenu();
        cin >> option;

        if (option == 1){
            selectedTopic = "Fruits";
        }
        else if (option == 2){
            selectedTopic = "Countries";
        }
        else if (option == 3){
            selectedTopic = "Colours";
        }
        else if (option == 4){
            cout << "Returning to the Game Mode Menu..." << endl;
            return;
        }
        else{
            cout << "Invalid option. Please enter a number from 1 to 4." << endl;
        }

    } while (option < 1 || option > 4);

    cout << "Selected topic: "
         << selectedTopic
         << endl;
}
