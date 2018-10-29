//
// Created by MaxBe on 10/26/2018.
//

#include "Hero.h"
#include "nostd/String.h"

Hero::Hero(nostd::String name) {
    this->name = name;
    this->_level = 1;
    this->_hp = 10;
    this->_exp = 0;
    this->_attack_chance = 40;
    this->_def_chance = 30;
    this->Item_bag = nostd::Array<Item>(5);
    this->_skill_points = 0;
}

Hero::~Hero() {
    delete name;
    delete _level;
    delete _hp;
    delete _exp;
    delete _attack_chance;
    delete _def_chance;
    delete[] Item_bag;
    delete _skill_points;
}

int Hero::Attack() {
    nostd::Random r{};
    int totalDamage = 0;

    if( r.getRand(0, 100) <= this->_attack_chance) {
        //just some calculation to have some scaling damage
        totalDamage += r.getRand(this->_level, this->_attack_chance/4);
    }

    return totalDamage;
}

bool Monster::Block() {
    nostd::Random r{};
    return r.getRand(0, 100) <= this->_defence_chance;
}

void Hero::AddExp(int exp) {
    this->_exp += _exp;
    if(this->_exp == this->_level * 3) {
        this->LevelUp();
    }
}

void Hero::LevelUp() {
        _level++;
        _skill_points += 10;
}