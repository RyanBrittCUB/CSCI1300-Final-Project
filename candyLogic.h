#include<iostream>
#include"character.h"

using namespace std;

class candyLogic {
    private:
        // Feel free to create any helper functions that you may need

    public:

        int candyJarSort(char c, string candies, string targetCandy);
        string inventoryScrambler(char c, string inventory);
        string combineCandies(char c, string candy1, string candy2);
        int findGoldenTicket(char c, string batch, string ticket);
};