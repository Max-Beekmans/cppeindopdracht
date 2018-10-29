#include <utility>

//
// Created by MaxBe on 10/26/2018.
//

#include <iostream>
#include "Hero.h"
#include "nostd/String.h"
#include "nostd/Random.h"

Hero::Hero() : _level(0), _hp(0), _exp(0), _attack_chance(0), _def_chance(0), Item_bag(nostd::Array<Item>(0)), _skill_points(0), _item_count(0) {}

Hero::Hero(nostd::String name) {
    this->name = std::move(name);
    this->_level = 1;
    this->_hp = 10;
    this->_exp = 0;
    this->_attack_chance = 40;
    this->_def_chance = 30;
    this->Item_bag = nostd::Array<Item>(5);
    this->_skill_points = 0;
    this->location = Coordinate();
    this->_item_count = 0;
}

Hero::~Hero() {
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

void Hero::Move(char dir) {
    dir = static_cast<char>(toupper(dir));
    switch (dir) {
        case 'N':
            location = Coordinate(location.x, location.y - 1);
            break;
        case 'S':
            location = Coordinate(location.x, location.y + 1);
            break;
        case 'W':
            location = Coordinate(location.x - 1, location.y);
            break;
        case 'E':
            location = Coordinate(location.x + 1, location.y);
            break;
        default:
            break;
    }
}

void Hero::PickUpItem(Item item) {
    Item_bag.addBack(item);
    std::cout << "You picked up " << item.name << "." << std::endl;
}

int Hero::Block(int damage) {
    nostd::Random r{};
    return r.getRand(0, 100) <= this->_def_chance ? 0 : damage;
}

void Hero::AddExp(int exp) {
    this->_exp += _exp;
    if(this->_exp == this->_level * 3) {
        this->LevelUp();
    }
    std::cout << "You received " << exp << " experience." << std::endl;
}

void Hero::LevelUp() {
        _level++;
        _skill_points += 10;
        std::cout << "Congratulations, you are now level" << _level << std::endl;
        std::cout << "You now have " << _skill_points << " skillpoints." << std::endl;
}