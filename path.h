#include <string>

#define SUGAR_RUSH_PATH Path{10, 5, -10, "Sugar Rush Path"}
#define FROST_BITE_PATH Path{-10, -5, 15, "Frostbite Path"}

#ifndef PATH_H
#define PATH_H

struct Path
{
    int agilityBonus;
    int luckBonus;
    int focusBonus;

    std::string pathName;
};

#endif