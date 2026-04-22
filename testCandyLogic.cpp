/* TODO: Complete testCandyLogic.cpp */
#include <iostream>
#include "candyLogic.h"
using namespace std;

int main(){

    candyLogic test;

    cout << "Test Candy Jar Sort:" << endl;
    string batch="taffy,sour,sweet,chocolate,mike,ike,taffy,taffy";
    string targetCandy="taffy";
    char c1='a' ;
    int count = test.candyJarSort(c1, batch, targetCandy);
    cout << "Expected: 3 Got:" << count << endl;
    if(count==3){
        cout<< "PASS";
    }
    else{
        cout << "FAIL";
    }
    cout << endl;


    cout << "Test Inventory Scrambler:" << endl;
    string inventory= "chocolate";
    char c2='a';
    string scramble= test.inventoryScrambler(c2, inventory);
    cout << "Expected: eTaLoCoHc Got:" << scramble << endl;
    if(scramble=="eTaLoCoHc"){
        cout<< "PASS";
    }
    else{
        cout << "FAIL";
    }
    cout << endl;
    
    cout << "Test Combine Candies" << endl;
    string candy1="Sweet";
    string candy2="Sour";
    char c3='a';
    string wombo_combo= test.combineCandies(c3, candy1, candy2);
    cout << "Expected: SSwoeuert  Got:" << wombo_combo << endl;
    if(wombo_combo=="SSwoeuert"){
        cout<< "PASS";
    }
    else{
       cout << "FAIL";
    }
    cout << endl;
    

    cout << "Test Find Golden Ticket" << endl;
    char c4='a';
    string goldBatch= "MatchToTheBestIndex";
    string Golden_Boy= "best";
    int PWRBAL= test.findGoldenTicket(c4, goldBatch, Golden_Boy);
    cout << "Expected: 10 Got:"<< PWRBAL << endl;
    if(PWRBAL==10){
        cout<< "PASS";
    }
    else{
        cout << "FAIL";
    }
    cout << endl;
}