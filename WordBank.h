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
    WordBank();

    string getRandomWord(string topic);
    bool isValidTopic(string topic);
};

#endif