/* TODO: Initialize candyLogic.cpp */
#include <vector>

#include "candyLogic.h"

int candyJarSort(char c, string candies, string targetCandy){

int count=0;
string testcandy;

while(getline(candies, testcandy, ',')){
    if(getline(candies, testcandy, ',')==targetCandy){
        count++;
    }
}
return count;
}

string inventoryScrambler(char c, string inventory)
{
    const int stringLength = inventory.length();
    std::vector<char> letters1, letters2;
    std::string scrambledInventory = "";

    for (int i = 0; i < stringLength; i++){
        letters1.push_back(inventory[1]);
    }

    for (int j = 0; j < stringLength; j ++){
        int randIndex = rand() % (stringLength - j);
        letters2.push_back(letters1[randIndex]);
        // capitalization:

        if (j % 2 ==0) if (letters2[j] - 60 > 0){ letters2[j] = letters2[j] - 20; }
        else           if (letters2[j] - 60 < 0){ letters2[j] = letters2[j] + 20; }
        scrambledInventory = scrambledInventory + letters2[j];
        letters1.erase(letters1.begin() + randIndex);
    }

    return scrambledInventory;

}

string combineCandies(char c, string candy1, string candy2)
{
    int candy1length = candy1.length();
    int candy2length = candy2.length();
    int outputLength = candy1length + candy2length;

    int candy1Index = 0, candy2Index = 0;
    string combinedCandies = "";

    for (int i = 0; i < outputLength; i ++)
    {
        if (candy1Index > candy1length)         combinedCandies += candy2[i];
        else if (candy2Index > candy2length)    combinedCandies += candy1[i];
        else if (candy1Index == candy2Index)   {combinedCandies += candy1[i]; candy1Index ++; }
        else                                   {combinedCandies += candy2[i]; candy1Index ++; }
    }

    return combinedCandies;
}



int findGoldenTicket(char c, string batch, string ticket)
{
    return 0;
}