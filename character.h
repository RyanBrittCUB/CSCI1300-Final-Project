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

        int points;

        std::string characterString;
        std::string secretWord;

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
    void setPoints(int _points);
    void setSecretWord(std::string _secretWord);

    void setcharictureFromFileLine(std::string line);

    // getters

    std::string getName();
    float getAgility();
    float getFocus();
    float getLuck();
    int getPoints();
    Path getPath();
    std::string getPathName();
    std::string getSecretWord();

    // opperators

    std::string getCharacterString();
    std::string printCharacterArray(Character characters[], int numberOfCharacters);
    void gainPoints(int newPoints);

};

#endif
