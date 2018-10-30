#include <utility>

#include <utility>

//
// Created by MaxBe on 10/26/2018.
//

#include "Item.h"

Item::Item(nostd::String stat, nostd::String item_name, nostd::String on_use, int factor, int uses) :
        stat(std::move(stat)), name(std::move(item_name)), use(std::move(on_use)), factor(factor), uses(uses) {}

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
    this->use = copy.use;
    this->factor = copy.factor;
    this->uses = copy.uses;
}

void Item::move_from(Item& move) {
    this->name = move.name;
    this->stat = move.stat;
    this->use = move.use;
    this->factor = move.factor;
    this->uses = move.uses;
}

nostd::String Item::ConsumeItem() {
    if(this->uses < 0) {
        this->use = nostd::String{"This item is out of uses"};
    } else {
        this->uses--;
    }
    return this->use;
}
