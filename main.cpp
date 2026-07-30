#include <iostream>
#include "WordBank.h"

using namespace std;

int main(){
    WordBank wordBank;

    cout << "Random fruit: " << wordBank.getRandomWord("Fruits") << endl;
    cout << "Random country: " << wordBank.getRandomWord("Countries") << endl;
    cout << "Random colour: " << wordBank.getRandomWord("Colours") << endl;

    return 0;
}