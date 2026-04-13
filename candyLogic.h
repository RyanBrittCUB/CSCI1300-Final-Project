#include<iostream>
#include"character.h"

using namespace std;

class candyLogic {
    private:
        // Feel free to create any helper functions that you may need

    public:

        int candyJarSort(Character c, string candies, string targetCandy);
        string inventoryScrambler(Character c, string inventory);
        string combineCandies(Character c, string candy1, string candy2);
        int findGoldenTicket(Character c, string batch, string ticket);
};