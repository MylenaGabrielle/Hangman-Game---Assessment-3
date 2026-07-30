#include "WordBank.h"
#include <cstdlib>
#include <ctime>

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

    srand(time(0));
}

bool WordBank::isValidTopic(string topic){
    if (topic == "Fruits"){
        return true;
    }
    else if (topic == "Countries"){
        return true;
    }
    else if (topic == "Colours"){
        return true;
    }

    return false;
}

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