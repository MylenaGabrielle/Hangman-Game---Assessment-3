#include <cassert>
#include "Player.h"

int main() {
    //UT01
    // Create player
    Player player("Player 1");

    // Test initial name
    assert(player.getName() == "Player 1");

    // Test initial score
    assert(player.getScore() == 0);

    // Test initial attempts
    assert(player.getAttemptsLeft() == 4);

    // UT02
    // Test score update
    player.updateScore(10);
    assert(player.getScore() == 10);

    // UT03
    // Test attempt decrease
    player.decreaseAttempts();
    assert(player.getAttemptsLeft() == 3);

    return 0;
}