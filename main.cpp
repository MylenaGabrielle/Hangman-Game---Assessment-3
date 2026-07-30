#include <iostream>
#include "WordBank.h"

using namespace std;

int main(){
    WordBank wordBank;

    cout << "Fruits: " << wordBank.isValidTopic("Fruits") << endl;
    cout << "Countries: " << wordBank.isValidTopic("Countries") << endl;
    cout << "Colours: " << wordBank.isValidTopic("Colours") << endl;
    cout << "Animals: " << wordBank.isValidTopic("Animals") << endl;

    return 0;
}