/* TODO: Complete loadCharacters.cpp */

#include <string>
#include <fstream>

#include"character.h"

//using namespace std;


int loadCharacters(std::string filename, Character characters[], int max_players)
{
    
    std::fstream infile;
    infile.open(filename);

    std::string line = "";
    int index = 0;
    bool firstLine = true;
    while ((getline(infile, line)) && index < max_players)
    {
        
        if (firstLine){
            firstLine = false;
            continue;
        } 
        characters[index].setcharictureFromFileLine(line);
        index++;
        
    }
    return  index;
}