//
// Created by Martijn Coomans on 25-10-2018.
//

#ifndef EINDOPDRACHT_MONSTER_H
#define EINDOPDRACHT_MONSTER_H

#include "nostd/String.h"
#include "nostd/Random.h"


class Monster {
public:
    Monster(const nostd::String name, const nostd::String level, const int attackChance, const int attackAmount, const int minDamage, const int maxDamage, const int defenceChance, const int maxHP);
    ~Monster();
    const nostd::String name;
    const nostd::String level;
    int Attack();
    bool Block();
    //copy
    Monster& operator=(const Monster& copy);
    //move
    Monster& operator=(Monster&& move) noexcept;
private:
    nostd::Random _random{};
    const int _attackChance;
    const int _attackAmount;
    const int _minDamage;
    const int _maxDamage;
    const int _defenceChance;
    const int _maxHP;
    int _currentHP;
    void copy_from(const Monster& copy);
    void move_from(Monster& move);
};


#endif //EINDOPDRACHT_MONSTER_H
