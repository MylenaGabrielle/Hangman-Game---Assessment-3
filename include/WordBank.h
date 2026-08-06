#ifndef WORDBANK_H
#define WORDBANK_H

#include <string>
#include <vector>

using namespace std;

class WordBank{
    private:
    vector<string> colourWords;
    vector<string> countryWords;
    vector<string> fruitWords;
    
    public:
    // Creates and initialises the word categories
    WordBank();

    // Returns a random word from the selected topic
    string getRandomWord(string topic);
};

#endif