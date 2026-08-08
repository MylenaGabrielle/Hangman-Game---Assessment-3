#include <cassert>
#include "WordBank.h"

int main(){
    WordBank wordBank;
    // UT09
    // Test Fruits word
    string fruit = wordBank.getRandomWord("Fruits");
    assert(
        fruit == "MANGO" ||
        fruit == "BANANA" ||
        fruit == "GRAPE"
    );

    // UT10
    // Test Countries word
    string country = wordBank.getRandomWord("Countries");
    assert(
        country == "BRAZIL" ||
        country == "AUSTRALIA" ||
        country == "KOREA"
    );

    // UT11
    // Test Colours word
    string colour = wordBank.getRandomWord("Colours");
    assert(
        colour == "YELLOW" ||
        colour == "RED" ||
        colour == "GREEN"
    );

    // UT12
    // Test invalid topic
    string invalid = wordBank.getRandomWord("Animals");
    assert(invalid == "");

    return 0;
}