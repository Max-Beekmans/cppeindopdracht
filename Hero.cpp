#include <utility>

//
// Created by MaxBe on 10/26/2018.
//

#include <iostream>
#include "Hero.h"
#include "nostd/String.h"
#include "nostd/Random.h"
#include "nostd/IOHandler.h"

Hero::Hero() : _level(0), _hp(0), current_hp(0), _exp(0), _attack_chance(0), _def_chance(0), Item_bag(nostd::Array<Item>(0)), _skill_points(0), _item_count(0) {}

Hero::Hero(nostd::String name, Coordinate start) {
    this->name = std::move(name);
    this->_level = 1;
    this->_hp = 10;
    this->current_hp = this->_hp;
    this->_exp = 0;
    this->_attack_chance = 40;
    this->_def_chance = 30;
    this->Item_bag = nostd::Array<Item>(5);
    this->_skill_points = 0;
    this->location = start;
    this->_item_count = 0;
    this->layer = 0;
    this->_io = nostd::IOHandler();
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

void Hero::UseItem(Item item) {
    std::cout << item.use;
    if(item.stat.c_str() == "attack") {
        _attack_chance += item.factor;
        if(_attack_chance > 100) _attack_chance = 100;
    } else if(item.stat.c_str() == "defence") {
        _def_chance += item.factor;
        if(_def_chance > 100) _def_chance = 100;
    }
}

void Hero::PickUpItem(Item* item) {
    if(item != nullptr) {
        Item_bag.addBack(*item);
        std::cout << "You picked up " << item->name << "." << std::endl;
    }
}

int Hero::Block(int damage) {
    nostd::Random r{};
    if(r.getRand(0, 100) <= this->_def_chance) return 0;

    current_hp -= damage;
    return damage;
}

void Hero::Rest() {
    this->current_hp = _hp;
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
        std::cout << "You now have " << _skill_points << " unused skillpoints." << std::endl;
}

void Hero::PrintBag() {
    std::cout << "Contents of your bag: " << std::endl;
    for(int i = 0; i < Item_bag.size(); i++) {
        std::cout << Item_bag.at(i).name << ", which grants " << Item_bag.at(i).stat << std::endl;
    }
}

void Hero::PrintStats() {
    std::cout << "Your Hero stats: " << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Level: " << _level << std::endl;
    std::cout << "Hitpoints: " << current_hp << "/" << _hp << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Experience: " << _exp << std::endl;
    std::cout << "Skillpoints: " << _skill_points << std::endl;
    std::cout << "Attack Chance: " << _attack_chance << std::endl;
    std::cout << "Block Chance: " << _def_chance << std::endl;
}

void Hero::UseSkillPoints() {
    std::cout << "On what skill would you like to use your skillpoints?" << std::endl;
    nostd::String skill = _io.GetString();
    std::cout << "How many skillpoints would you like to use? You have " << _skill_points << "right now." << std::endl;
    int points = _io.GetInt();

    if(points < _skill_points) {
        if(skill.c_str() == "attack") {
            if(_attack_chance < 100) {
                _attack_chance += points;
                _skill_points -= points;
                std::cout << "Your attack is now: " << _attack_chance;
            } else {
                std::cout << "The attack stat is already at its maximum value(100).";
            }
        } else if(skill.c_str() == "defence") {
            if(_def_chance < 100) {
                _def_chance += points;
                _skill_points -= points;
                std::cout << "Your defence is now: " << _def_chance;
            } else {
                std::cout << "The defence stat is already at its maximum value(100).";
            }
        }
    } else {
        std::cout << "You dont have enough skillpoints.";
    }
}