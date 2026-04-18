// Header files do not only have to be used for classes
// Here, we see an example of a header file so that the loadCharacters func can be accessed from the gameEngine.cpp
// Make sure to use '#include "loadCharacters.h"' in your loadCharacters.cpp!

#ifndef LOADCHARACTERS_H
#define LOADCHARACTERS_H

#include<string>

#include"character.h"

using namespace std;

// Function prototype
int loadCharacters(string filename, Character (&characters)[10], int max_players);

#endif