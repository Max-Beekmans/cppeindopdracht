//
// Created by Martijn Coomans on 25-10-2018.
//

#include "Monster.h"
#include "nostd/Random.h"

Monster::Monster() : _attackChance(-1), _attackAmount(-1), _minDamage(-1), _maxDamage(-1), _defenceChance(-1), _maxHP(-1), _currentHP(-1) {}

Monster::Monster(const nostd::String name, const nostd::String level, const int attackChance, const int attackAmount, const int minDamage, const int maxDamage, const int defenceChance, const int maxHP)
    : name(name), level(level), _attackChance(attackChance), _attackAmount(attackAmount), _minDamage(minDamage), _maxDamage(maxDamage), _defenceChance(defenceChance), _maxHP(maxHP), _currentHP(maxHP) {
}

Monster::~Monster() {

}

int Monster::Attack() {
    nostd::Random r{};
    int totalDamage = 0;

    for(int i = 0; i < this->_attackAmount; i++) {
        if( r.getRand(0, 100) <= this->_attackChance) {
            totalDamage += r.getRand(this->_minDamage, this->_maxDamage);
        }
    }

    return totalDamage;
}

bool Monster::Block() {
    nostd::Random r{};
    return r.getRand(0, 100) <= this->_defenceChance;
};

Monster& Monster::operator=(const Monster& copy) {
    if (this == &copy) return *this;
    copy_from(copy);
    return *this;
}

Monster& Monster::operator=(Monster&& move) noexcept{
    if (this == &move) return *this;
    move_from(move);
    return *this;
}

void Monster::copy_from(const Monster& copy) {
    this->name = copy.name;
    this->level = copy.level;
    this->_attackChance = copy._attackChance;
    this->_attackAmount = copy._attackAmount;
    this->_minDamage = copy._minDamage;
    this->_maxDamage = copy._maxDamage;
    this->_defenceChance = copy._defenceChance;
    this->_maxHP = copy._maxHP;
    this->_currentHP = copy._currentHP;
}

void Monster::move_from(Monster &move) {
    this->name = move.name;
    this->level = move.level;
    this->_attackChance = move._attackChance;
    this->_attackAmount = move._attackAmount;
    this->_minDamage = move._minDamage;
    this->_maxDamage = move._maxDamage;
    this->_defenceChance = move._defenceChance;
    this->_maxHP = move._maxHP;
    this-> _currentHP = move._currentHP;
}

Monster::Monster(const Monster &copy) {
    copy_from(copy);
}

Monster::Monster(Monster &&move) {
    move_from(move);
}
