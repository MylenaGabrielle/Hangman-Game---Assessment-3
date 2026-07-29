#include <iostream>
#include "Player.h"

using namespace std;

int main(){
    Player player1("Mylena");

    cout << "Player: " << player1.getName() << endl;
    cout << "Score: " << player1.getScore() << endl;
    cout << "Attempts: " << player1.getAttemptsLeft() << endl;
    
    player1.updateScore(10);
    player1.decreaseAttempts();

    cout << endl;
    cout << "After playing: " << endl;
    cout << "Score: " << player1.getScore() << endl;
    cout << "Attempts: " << player1.getAttemptsLeft() << endl;

    player1.resetPlayer();

    cout << endl;
    cout << "After reset: " << endl;
    cout << "Score: " << player1.getScore() << endl;
    cout << "Attempts: " << player1.getAttemptsLeft() << endl;

    return 0;
}
