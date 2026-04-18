/* TODO: Initialize candyLogic.cpp */
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
string inventoryScrambler(char c, string inventory);








string combineCandies(char c, string candy1, string candy2);









int findGoldenTicket(char c, string batch, string ticket);