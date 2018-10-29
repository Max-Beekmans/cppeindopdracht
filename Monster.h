//
// Created by Martijn Coomans on 25-10-2018.
//

#ifndef EINDOPDRACHT_MONSTER_H
#define EINDOPDRACHT_MONSTER_H

#include "nostd/String.h"
#include "nostd/Random.h"


class Monster {
public:
    Monster();
    Monster(const nostd::String name, const nostd::String level, const int attackChance, const int attackAmount, const int minDamage, const int maxDamage, const int defenceChance, const int maxHP);
    ~Monster();
    Monster(const Monster& copy);
    Monster(Monster&& move);
    nostd::String name;
    nostd::String level;
    int Attack();
    int Block(int damage);
    //copy
    Monster& operator=(const Monster& copy);
    //move
    Monster& operator=(Monster&& move) noexcept;
    int currentHP;
private:
    int _attackChance;
    int _attackAmount;
    int _minDamage;
    int _maxDamage;
    int _defenceChance;
    int _maxHP;
    void copy_from(const Monster& copy);
    void move_from(Monster& move);
};


#endif //EINDOPDRACHT_MONSTER_H
