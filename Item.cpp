#include <utility>

#include <utility>

//
// Created by MaxBe on 10/26/2018.
//

#include "Item.h"

Item::Item(nostd::String stat, nostd::String item_name, int factor, int uses) :
        stat(std::move(stat)), name(
        std::move(item_name)), factor(factor), uses(uses) {}

Item::Item(const Item& copy) { copy_from(copy); }

Item::Item(Item&& move) noexcept { move_from(move); }

Item& Item::operator=(const Item& copy) {
    if (this == &copy) return *this;
    copy_from(copy);
    return *this;
}

Item& Item::operator=(Item&& move) noexcept {
    if (this == &move) return *this;
    move_from(move);
    return *this;
}

void Item::copy_from(const Item& copy) {
    this->name = copy.name;
    this->stat = copy.stat;
    this->factor = copy.factor;
    this->uses = copy.uses;
}

void Item::move_from(Item& move) {
    this->name = move.name;
    this->stat = move.stat;
    this->factor = move.factor;
    this->uses = move.uses;
}
