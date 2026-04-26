#include <string>

#define ABSTRACT_PATH Path{10, 5, -10, "Abstract Path", 40}
#define APPLIED_PATH Path{-10, -5, 15, "Applied Path", 20}

#ifndef PATH_H
#define PATH_H

struct Path
{
    int agilityBonus;
    int luckBonus;
    int focusBonus;

    std::string pathName;

    int tileModifier;
};

#endif