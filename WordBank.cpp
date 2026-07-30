#include "WordBank.h"

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
}

bool WordBank::isValidTopic(string topic)
{
    if (topic == "Fruits")
    {
        return true;
    }
    else if (topic == "Countries")
    {
        return true;
    }
    else if (topic == "Colours")
    {
        return true;
    }

    return false;
}