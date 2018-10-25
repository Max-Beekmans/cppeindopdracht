//
// Created by Martijn Coomans on 25-10-2018.
//

#include "Monster.h"
#include "nostd/Random.h"

Monster::Monster(const nostd::String name, const nostd::String level, const int attackChance, const int attackAmount, const int minDamage, const int maxDamage, const int defenceChance, const int maxHP)
    : name(name), level(level), _attackChance(attackChance), _attackAmount(attackAmount), _minDamage(minDamage), _maxDamage(maxDamage), _defenceChance(defenceChance), _maxHP(maxHP), _currentHP(maxHP) {
}

Monster::~Monster() {

}

int Monster::Attack() {
    int totalDamage = 0;

    for(int i = 0; i < this->_attackAmount; i++) {
        if( this->_random.getRand(0, 100) <= this->_attackChance) {
            totalDamage += this->_random.getRand(this->_minDamage, this->_maxDamage);
        }
    }

    return totalDamage;
}

bool Monster::Block() {
    return this->_random.getRand(0, 100) <= this->_defenceChance;
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