//
// Created by MaxBe on 10/26/2018.
//

#ifndef EINDOPDRACHT_HERO_H
#define EINDOPDRACHT_HERO_H

#include "nostd/Array.h"
#include "nostd/String.h"
#include "Item.h"

class Hero {
public:
    nostd::Array<Item> Item_bag;
    nostd::String name;
    int _level;
    int hp;
    int exp;
    int attack_chance;
    int def_chance;
private:
};


#endif //EINDOPDRACHT_HERO_H
