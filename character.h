/* TODO: Write character.h, a header file for the character class */


#ifndef CHARACTER_H
#define CHARACTER_H


class Character
{
    private:
        std::string name;
        float agility, focus, luck;

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
    void setCharacterString();

    void setcharictureFromFileLine(std::string line);

    // getters

    std::string getName();
    float getAgilityu();
    float getFocus();
    float getLuck();

    // opperators

    std::string getCharacterString();

};

#endif
