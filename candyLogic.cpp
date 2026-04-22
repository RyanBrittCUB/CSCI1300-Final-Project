/* TODO: Initialize candyLogic.cpp */
#include "candyLogic.h"
#include <algorithm>


int candyLogic:: candyJarSort(char c, string candies, string targetCandy){

int count=0;
string testcandy;
//Need to find string version of the getline command


/*while(getline(candies, testcandy, ',')){
    if(getline(candies, testcandy, ',')==targetCandy){
        count++;
    }
}*/
    int L=candies.length();
for(int c=0; c < L;c++){
    if(candies.substr(c, targetCandy.length())==targetCandy){
        count++;
    }
}



return count;
}



string candyLogic:: inventoryScrambler(char c, string inventory){
    reverse(inventory.begin(), inventory.end());
    int L=inventory.length();

    for(int i=1; i<L; i=i+2){
        inventory[i]=inventory[i]-32;
    }
    return inventory;
}






string candyLogic::combineCandies(char c, string candy1, string candy2)
{
    int candy1length = candy1.length();
    int candy2length = candy2.length();
    int outputLength = candy1length + candy2length;
    int candy1Index = 0, candy2Index = 0;

    string combinedCandies = "";

    for (int i = 0; i < outputLength; i ++)
    {
        if (i % 2 == 0){
            if (candy1Index < candy1length) {
                combinedCandies += candy1[candy1Index];
                candy1Index ++;
            } else {
                combinedCandies += candy2[candy2Index];
                candy2Index ++;
            }
        } else {
            if (candy2Index < candy2length) {
                combinedCandies += candy2[candy2Index];
                candy2Index ++;
            } else {
                combinedCandies += candy1[candy1Index];
                candy1Index ++;
            }
        }
    }

    return combinedCandies;
}





int candyLogic::findGoldenTicket(char c, string batch, string ticket){

    int idx = -1;
    int L=batch.length();
    int lT = ticket.length();

    for(int c=0; c<L; c++){
        if(batch[c]<91){
            batch[c]= batch[c]+32;
        }
    }
     for(int c=0; c<lT; c++){
        if(ticket[c]<91){
            ticket[c]= ticket[c]+32;
        }
    }

    for(int i=0; i<L; i++){
        if(batch.substr(i, ticket.length()) == ticket){
            idx=i;
        }
    }

    return idx;
}