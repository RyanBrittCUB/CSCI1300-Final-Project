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









int findGoldenTicket(char c, string batch, string ticket);