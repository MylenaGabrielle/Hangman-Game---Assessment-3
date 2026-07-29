#include <iostream>
#include "TwoPlayerMode.h"

using namespace std;

int main(){
    TwoPlayerMode mode;

    cout << "Mode: " << mode.getModeName() << endl;
    cout << "Current player after switch from 0: " << mode.switchPlayer(0) << endl;
    cout << "Current player after switch from 1: " << mode.switchPlayer(1) << endl;

    return 0;
}