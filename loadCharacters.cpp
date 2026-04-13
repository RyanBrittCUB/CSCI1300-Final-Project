/* TODO: Complete loadCharacters.cpp */

#include<string>
#include <fstream>

#include"character.h"

using namespace std;


int loadCharacters(string filename, Character characters[], int max_players)
{
    fstream infile;
    infile.open(filename);

    string line = "";
    while (infile.getline(line)))
}