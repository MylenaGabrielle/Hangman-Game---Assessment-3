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
    while (true){
        gameMode = nullptr;
        selectedTopic = "";

        selectGameMode();

        if (gameMode == nullptr){
            return;
        }

        setUpPlayers();
        selectTopic();

        if (selectedTopic == ""){
            continue;
        }

        break;
    }

    secretWord = wordBank.getRandomWord(selectedTopic);

displayedWord = "";

for (int i = 0; i < secretWord.length(); i++)
{
    displayedWord += "_";
}

bool gameRunning = true;

while (gameRunning)
{
    display.showGameScreen(
        players[currentPlayerIndex].getName(),
        gameMode->getModeName(),
        selectedTopic,
        displayedWord,
        players[currentPlayerIndex].getScore(),
        players[currentPlayerIndex].getAttemptsLeft()
    );
    
    showGuessedLetters();

    int action;

    cout << endl;
    cout << "Enter your choice [1-3]: ";

    if (!(cin >> action))
    {
        cout << "Input error. Please enter a number from 1 to 3." << endl;

        cin.clear();
        cin.ignore(10000, '\n');

        continue;
    }

    if (action == 1){
        guessLetter();
    }

    else if (action == 2){
        guessCompleteWord();
    }
    else if (action == 3){
         display.showLeaveConfirmation();

        int leaveChoice;
         cin >> leaveChoice;
         
         if (leaveChoice == 1){
        cout << "Returning to the Main Menu..." << endl;
        gameRunning = false;
    }
    else if (leaveChoice == 2){
         cout << "Returning to the game..." << endl;
         continue;
    }
    else{
         cout << "Invalid option. Returning to the game..." << endl;
         continue;
    }
}
    else{
        cout << "Invalid option. Please enter a number from 1 to 3." << endl;
        continue;
    }
    if (checkWin()){
            cout << "\nCongratulations! You guessed the word!" << endl;
            gameRunning = false;
        }
        else if (checkGameOver()){
             cout << "\nGame Over!" << endl;
             cout << "The word was: " << secretWord << endl;
             
             if (gameMode->getModeName() == "Two-Player"){
             int winnerIndex = gameMode->switchPlayer(currentPlayerIndex);
             
             cout << players[currentPlayerIndex].getName() << " has no attempts left." << endl;
             
             cout << "Winner: " << players[winnerIndex].getName() << endl;
    }

    gameRunning = false;
}
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

void HangmanGame::guessLetter(){
    char letter;

    cout << "Enter a letter: ";
    cin >> letter;

    letter = toupper(letter);
    if (guessedLetters.count(letter) > 0){
    cout << "This letter has already been guessed." << endl;

    return;
}

     guessedLetters.insert(letter);

    cout << "You guessed: " << letter << endl;

    if (checkLetterGuess(letter)){
    revealLetter(letter);

    players[currentPlayerIndex].updateScore(10);

    cout << "Correct letter!" << endl;
    cout << "Updated word: ";

    for (char currentCharacter : displayedWord){
        cout << currentCharacter << " ";
    }

    cout << endl;
}
else{
    players[currentPlayerIndex].decreaseAttempts();

    cout << "Wrong letter!" << endl;

    if (gameMode->getModeName() == "Two-Player"
        && players[currentPlayerIndex].getAttemptsLeft() > 0){
        currentPlayerIndex = gameMode->switchPlayer(currentPlayerIndex);
    }
}
}

bool HangmanGame::checkLetterGuess(char letter){
    for (char currentLetter : secretWord){
        if (toupper(currentLetter) == toupper(letter)){

            return true;
        }
    }

    return false;
}

void HangmanGame::revealLetter(char letter){
    for (int i = 0; i < secretWord.length(); i++){
        if (toupper(secretWord[i]) == toupper(letter)){
            displayedWord[i] = toupper(letter);
        }
    }
}

bool HangmanGame::checkWin(){
    return displayedWord == secretWord;
}

bool HangmanGame::checkGameOver(){
    return players[currentPlayerIndex].getAttemptsLeft() == 0;
}

void HangmanGame::guessCompleteWord(){
    string guessedWord;

    cout << "Enter the complete word: ";
    cin >> guessedWord;

    for (char& letter : guessedWord){
        letter = toupper(letter);
    }

    if (guessedWord == secretWord){
        players[currentPlayerIndex].updateScore(50);
        displayedWord = secretWord;

        cout << "Correct word!" << endl;
    }
    else{
    players[currentPlayerIndex].decreaseAttempts();

    cout << "Wrong word!" << endl;

    if (gameMode->getModeName() == "Two-Player"
        && players[currentPlayerIndex].getAttemptsLeft() > 0){
        currentPlayerIndex =
            gameMode->switchPlayer(currentPlayerIndex);
    }
}
}

void HangmanGame::showGuessedLetters(){
    cout << "Guessed Letters: ";

    for (char letter : guessedLetters){
        cout << letter << " ";
    }

    cout << endl;
}

void HangmanGame::run(){
    bool running = true;

    while (running){
        display.showMainMenu();

        int choice;
        cin >> choice;

        if (choice == 1){
            startGame();
        }
        else if (choice == 2){
            display.showHowToPlay();

            int backChoice;
            cin >> backChoice;
        }
        else if (choice == 3){
            cout << "Exiting game..." << endl;
            running = false;
        }
        else{
            cout << "Invalid option. Please enter a number from 1 to 3." << endl;
        }
    }
}