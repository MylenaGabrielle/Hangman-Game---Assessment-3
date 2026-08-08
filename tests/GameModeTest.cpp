#include <cassert>
#include "SoloMode.h"
#include "TwoPlayerMode.h"

int main(){
    // UT04
    // Create Solo Mode
    SoloMode soloMode;

    // Test mode name
    assert(soloMode.getModeName() == "Solo");

    // UT05
    // Test player remains the same
    assert(soloMode.switchPlayer(0) == 0);

    // UT06
    // Create Two-Player Mode
    TwoPlayerMode twoPlayerMode;
    
    // Test mode name
    assert(twoPlayerMode.getModeName() == "Two-Player");

    // UT07
    // Test switch from Player 1
    assert(twoPlayerMode.switchPlayer(0) == 1);
    
    // UT08
    // Test switch from Player 2
    assert(twoPlayerMode.switchPlayer(1) == 0);

    return 0;
}