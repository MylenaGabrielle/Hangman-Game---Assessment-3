#include "WordBank.h"

#include <cstdlib>
#include <ctime>

// Initialises the words available for each topic
WordBank::WordBank(){
    fruitWords = {
        "MANGO",
        "BANANA",
        "GRAPE"
    };

    countryWords = {
        "BRAZIL",
        "AUSTRALIA",
        "KOREA"
    };

    colourWords = {
        "YELLOW",
        "RED",
        "GREEN"
    };

    // Seeds the random number generator
    srand(time(0));
}

// Returns a random word from the selected topic
string WordBank::getRandomWord(string topic){
    if (topic == "Fruits"){
        int index = rand() % fruitWords.size();
        return fruitWords[index];
    }
    else if (topic == "Countries"){
        int index = rand() % countryWords.size();
        return countryWords[index];
    }
    else if (topic == "Colours"){
        int index = rand() % colourWords.size();
        return colourWords[index];
    }

    return "";
}