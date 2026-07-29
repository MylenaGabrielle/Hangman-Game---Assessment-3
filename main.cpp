#include <iostream>
#include "SoloMode.h"

using namespace std;

int main(){
    SoloMode solo;

    cout << "Mode: " << solo.getModeName() << endl;
    cout << "Current player: " << solo.switchPlayer(0) << endl;

    return 0;
}