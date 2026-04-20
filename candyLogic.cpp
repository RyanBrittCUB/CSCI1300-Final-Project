/* TODO: Initialize candyLogic.cpp */
#include "candyLogic.h"
#include <bits/stdc++.h>


int candyJarSort(char c, string candies, string targetCandy){

int count=0;
string testcandy;
//Need to find string version of the getline command
while(getline(candies, testcandy, ',')){
    if(getline(candies, testcandy, ',')==targetCandy){
        count++;
    }
}
return count;
}



string inventoryScrambler(char c, string inventory){
    reverse(inventory.begin(), inventory.end());

    for(int i=0; i<inventory.length(); i=i+2){
        inventory[i]=inventory[i]-32;
    }

}






string combineCandies(char c, string candy1, string candy2);

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





int findGoldenTicket(char c, string batch, string ticket);