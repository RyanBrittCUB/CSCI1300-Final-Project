/* TODO: Initialize character.cpp */

#include <string>
#include <iostream>

#include "character.h"

using namespace std;

Character::Character(){
    this->name = "";
    this->agility = 0;
    this->focus = 0;
    this->luck = 0;

    setCharacterString();
}
Character::Character(string _name){
    this->name = _name;
    this->agility = 0;
    this->focus = 0;
    this->luck = 0;

    setCharacterString();
}
Character::Character(std::string _name, float _adjility){
    this->name = _name;
    this->agility = _adjility;
    this->focus = 0;
    this->luck = 0;

    setCharacterString();
}
Character::Character(string _name, float _adjility, float _focus){
    this->name = _name;
    this->agility = _adjility;
    this->focus = _focus;
    this->luck = 0;

    setCharacterString();
}
Character::Character(string _name, float _adjility, float _focus, float _luck){
    this->name = _name;
    this->agility = _adjility;
    this->focus = _focus;
    this->luck = _luck;

    setCharacterString();

}

// setters

void Character::setName(string _name){
    this-> name = _name;
    setCharacterString();
}
void Character::setAgility(float _adjility)     {this->agility = _adjility; setCharacterString();}
void Character::setFocus(float _focus)          {this->focus = _focus;      setCharacterString();}
void Character::setLuck(float _luck)            {this->luck = _luck;        setCharacterString();}
void Character::setCharacterString()            {this -> characterString = "name: " + this->name +  ", adjility: " + to_string(this->agility) + ", Focus: " + to_string(this->focus) + ", Luck: " + to_string(this->luck);}

void Character::setcharictureFromFileLine(std::string line)
{
    int commas[4];
    int lineLength = line.length();
    int indexesSet = 0;

    for (int i = 0; i < lineLength; i++){
        if (line.at(i) == ','){
            commas[indexesSet] = i;
            indexesSet++;
        }
    }
    string stringName = line.substr(commas[0] + 1, commas[1] - commas[0] - 1);
    string stringAjility = line.substr(commas[1] + 1, commas[2] - commas[1] - 1);
    string stringFocus = line.substr(commas[2] +  1, commas[3] - commas[2] - 1);
    string stringLuck = line.substr(commas[3] + 1, lineLength - commas[3] - 1);

    name = stringName;
    agility = stof(stringAjility);
    focus = stof(stringFocus);
    luck = stof(stringLuck);

    setCharacterString();
    //cout << "test" << endl;
    //cout << "name: " << stringName <<endl;
    //cout << "/// Adjility: " << stringAjility <<endl;
    //cout << "/// focus: " << stringFocus <<endl;
    //cout << "/// luck: " << stringLuck << endl;

}

// getters

string Character::getName()             {return this->name;}
float Character::getAgility()           {return this->agility;}
float Character::getFocus()             {return this->focus;}
float Character::getLuck()              {return this->luck;}
string Character::getCharacterString()  {return this -> characterString;}

// methods


