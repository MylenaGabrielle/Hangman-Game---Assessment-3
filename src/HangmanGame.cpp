#include "HangmanGame.h"
#include "SoloMode.h"
#include "TwoPlayerMode.h"

#include <cctype>
#include <iostream>
#include <limits>

using namespace std;

// Initialises the main game attributes
HangmanGame::HangmanGame(){
    secretWord = "";
    displayedWord = "";
    selectedTopic = "";
    gameMode = nullptr;
    currentPlayerIndex = 0;
}

// Releases the dynamically allocated game mode
HangmanGame::~HangmanGame(){
    delete gameMode;
}

// Controls the setup and execution of one complete game
void HangmanGame::startGame(){
    // Clears information from the previous game
    guessedLetters.clear();
    players.clear();
    currentPlayerIndex = 0;

    while (true){
        // Releases the previous game mode before selecting another one
        delete gameMode;
        gameMode = nullptr;

        selectedTopic = "";

        selectGameMode();

        // A null game mode means that the user selected Back
        if (gameMode == nullptr){
            return;
        }

        setUpPlayers();
        selectTopic();

        // An empty topic means that the user returned to game-mode selection
        if (selectedTopic == ""){
            continue;
        }

        break;
    }

    secretWord = wordBank.getRandomWord(selectedTopic);

    // Creates one underscore for each letter in the secret word
    displayedWord = "";

    for (size_t i = 0; i < secretWord.length(); i++){
        displayedWord += "_";
    }

    bool gameRunning = true;

    // Repeats the gameplay until the player wins, loses, or leaves
    while (gameRunning){
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

        // Prevents invalid text input from breaking the input stream
        if (!(cin >> action)){
            cout << "Input error. Please enter a number from 1 to 3."
                 << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

            if (!(cin >> leaveChoice)){
                cout << "Invalid input. Returning to the game..."
                     << endl;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                continue;
            }

            if (leaveChoice == 1){
                cout << "Returning to the Main Menu..." << endl;
                gameRunning = false;
                break;
            }
            else if (leaveChoice == 2){
                cout << "Returning to the game..." << endl;
                continue;
            }
            else{
                cout << "Invalid option. Returning to the game..."
                     << endl;
                continue;
            }
        }
        else{
            cout << "Invalid option. Please enter a number from 1 to 3."
                 << endl;
            continue;
        }

        // Checks the result after a valid guess
        if (checkWin()){
            cout << "\nCongratulations! You guessed the word!" << endl;
            gameRunning = false;
        }
        else if (checkGameOver()){
            cout << "\nGame Over!" << endl;
            cout << "The word was: " << secretWord << endl;

            if (gameMode->getModeName() == "Two-Player"){
                int winnerIndex =
                    gameMode->switchPlayer(currentPlayerIndex);

                cout << players[currentPlayerIndex].getName()
                     << " has no attempts left." << endl;

                cout << "Winner: "
                     << players[winnerIndex].getName()
                     << endl;
            }

            gameRunning = false;
        }
    }
}

// Allows the user to select Solo or Two-Player mode
void HangmanGame::selectGameMode(){
    int option = 0;

    do{
        display.showGameModeMenu();

        if (!(cin >> option)){
            cout << "Invalid input. Please enter a number from 1 to 3."
                 << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            option = 0;
            continue;
        }

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
            cout << "Invalid option. Please enter a number from 1 to 3."
                 << endl;
        }

    } while (option < 1 || option > 3);

    if (gameMode != nullptr){
        cout << "Selected mode: "
             << gameMode->getModeName()
             << endl;
    }
}

// Creates the appropriate number of players for the selected mode
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

// Allows the user to select a word topic
void HangmanGame::selectTopic(){
    int option = 0;

    do{
         display.showTopicMenu();

        if (!(cin >> option)){
            cout << "Invalid input. Please enter a number from 1 to 4."
                 << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            option = 0;
            continue;
        }

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
            selectedTopic = "";
            return;
        }
        else{
            cout << "Invalid option. Please enter a number from 1 to 4."
                 << endl;
        }

    } while (option < 1 || option > 4);

    cout << "Selected topic: "
         << selectedTopic
         << endl;
}

// Reads and processes one letter guess
void HangmanGame::guessLetter(){
    string input;

    cout << "Enter a letter: ";
    cin >> input;

    // A valid letter guess must contain exactly one alphabetic character
    if (input.length() != 1 ||
        !isalpha(static_cast<unsigned char>(input[0]))){
        cout << "Invalid input. Please enter one letter." << endl;
        return;
    }

    char letter = static_cast<char>(
        toupper(static_cast<unsigned char>(input[0]))
    );

    // Prevents the same letter from being processed more than once
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

        // A wrong guess changes the player only in Two-Player mode
        if (gameMode->getModeName() == "Two-Player" &&
            players[currentPlayerIndex].getAttemptsLeft() > 0){
            currentPlayerIndex =
                gameMode->switchPlayer(currentPlayerIndex);
        }
    }
}

// Checks whether a letter exists in the secret word
bool HangmanGame::checkLetterGuess(char letter){
    for (char currentLetter : secretWord){
        if (toupper(static_cast<unsigned char>(currentLetter)) ==
            toupper(static_cast<unsigned char>(letter))){
            return true;
        }
    }

    return false;
}

// Reveals every occurrence of a correctly guessed letter
void HangmanGame::revealLetter(char letter){
    for (size_t i = 0; i < secretWord.length(); i++)
    {
        if (toupper(static_cast<unsigned char>(secretWord[i])) ==
            toupper(static_cast<unsigned char>(letter)))
        {
            displayedWord[i] = static_cast<char>(
                toupper(static_cast<unsigned char>(letter))
            );
        }
    }
}

// Returns true when the displayed word matches the secret word
bool HangmanGame::checkWin(){
    return displayedWord == secretWord;
}

// Returns true when the current player has no attempts remaining
bool HangmanGame::checkGameOver(){
    return players[currentPlayerIndex].getAttemptsLeft() <= 0;
}

// Reads and processes a complete-word guess
void HangmanGame::guessCompleteWord(){
    string guessedWord;

    cout << "Enter the complete word: ";
    cin >> guessedWord;

    // Rejects numbers and special characters.
    for (char letter : guessedWord){
        if (!isalpha(static_cast<unsigned char>(letter)))
        {
            cout << "Invalid input. Please enter letters only." << endl;
            return;
        }
    }

    // Converts the guess to uppercase for case-insensitive comparison
    for (char& letter : guessedWord){
        letter = static_cast<char>(
            toupper(static_cast<unsigned char>(letter))
        );
    }

    if (guessedWord == secretWord){
        players[currentPlayerIndex].updateScore(50);
        displayedWord = secretWord;

        cout << "Correct word!" << endl;
    }
    else{
        players[currentPlayerIndex].decreaseAttempts();

        cout << "Wrong word!" << endl;

        if (gameMode->getModeName() == "Two-Player" &&
            players[currentPlayerIndex].getAttemptsLeft() > 0)
        {
            currentPlayerIndex =
                gameMode->switchPlayer(currentPlayerIndex);
        }
    }
}

// Displays all letters already attempted during the current game
void HangmanGame::showGuessedLetters(){
    cout << "Guessed Letters: ";

    if (guessedLetters.empty()){
        cout << "None";
    }
    else{
        for (char letter : guessedLetters){
            cout << letter << " ";
        }
    }

    cout << endl;
}

// Controls the main menu until the user selects Exit
void HangmanGame::run(){
    bool running = true;

    while (running){
        display.showMainMenu();

        int choice;

        if (!(cin >> choice)){
            cout << "Invalid input. Please enter a number from 1 to 3."
                 << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        if (choice == 1){
            startGame();
        }
        else if (choice == 2){
            display.showHowToPlay();

            int backChoice;

            if (!(cin >> backChoice)){
                cout << "Invalid input. Returning to the Main Menu..."
                     << endl;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                continue;
            }

            if (backChoice != 1){
                cout << "Invalid option. Returning to the Main Menu..."
                     << endl;
            }
        }
        else if (choice == 3){
            cout << "Exiting game..." << endl;
            running = false;
        }
        else{
            cout << "Invalid option. Please enter a number from 1 to 3."
                 << endl;
        }
    }
}