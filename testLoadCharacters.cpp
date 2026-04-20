/* TODO: Complete testLoadPlayers.cpp */

#include <string>
#include <iostream>

#include "character.h"
#include "loadCharacters.h"

using namespace std;

int main()
{
    std::string fileName = "characters.txt";
    const int test_numberOfPlayers = 10;
    Character characterArray[test_numberOfPlayers];

    int out = loadCharacters(fileName, characterArray, test_numberOfPlayers);
    cout << out << endl;


    for (int i = 0; i < test_numberOfPlayers; i ++){
        cout << characterArray[i].getCharacterString() << endl;
    }

}