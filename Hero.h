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
    Hero();
    Hero(nostd::String name);
    ~Hero();
    nostd::Array<Item> Item_bag;
    nostd::String name;
    void AddExp(int exp);
    int Attack();
    bool Block();
private:
    void LevelUp();
    int _level;
    int _hp;
    int _exp;
    int _skill_points;
    int _attack_chance;
    int _def_chance;
};


#endif //EINDOPDRACHT_HERO_H
