/* TODO: Write character.h, a header file for the character class */

#include "path.h"

#ifndef CHARACTER_H
#define CHARACTER_H


class Character
{
    private:
        std::string name;
        float agility, focus, luck;
        Path characterPath;

        std::string characterString;
        

    public:

    // constructors

    Character();
    Character(std::string _name);
    Character(std::string _name, float _adjility);
    Character(std::string _name, float _adjility, float _focus);
    Character(std::string _name, float _adjility, float _focus, float _luck);

    // setters

    void setName(std::string _name);
    void setAgility(float _adjility);
    void setFocus(float _focus);
    void setLuck(float _luck);
    void setCharacterPath(Path _path);
    void setCharacterString();

    void setcharictureFromFileLine(std::string line);

    // getters

    std::string getName();
    float getAgility();
    float getFocus();
    float getLuck();
    Path getPath();
    std::string getPathName();

    // opperators

    std::string getCharacterString();
    std::string printCharacterArray(Character characters[], int numberOfCharacters);

};

#endif
