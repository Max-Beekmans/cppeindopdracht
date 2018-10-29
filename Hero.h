//
// Created by MaxBe on 10/26/2018.
//

#ifndef EINDOPDRACHT_HERO_H
#define EINDOPDRACHT_HERO_H

#include "nostd/Array.h"
#include "nostd/String.h"
#include "Item.h"
#include "Coordinate.h"
#include "Monster.h"
#include "nostd/IOHandler.h"

class Hero {
public:
    Hero();
    Hero(nostd::String name);
    ~Hero();
    nostd::Array<Item> Item_bag;
    nostd::String name;
    void AddExp(int exp);
    int Attack();
    int Block(int damage);
    // takes 'N'for North, 'S' for South, 'W' for West and 'E' for East.
    void Move(char dir);
    void UseSkillPoints();
    void PickUpItem(Item item);
    Coordinate location;
    int current_hp;
private:
    void LevelUp();
    int _level;
    int _hp;
    int _exp;
    int _skill_points;
    int _attack_chance;
    int _def_chance;
    int _item_count;
    nostd::IOHandler _io;
};


#endif //EINDOPDRACHT_HERO_H
