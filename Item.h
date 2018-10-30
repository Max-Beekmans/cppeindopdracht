//
// Created by MaxBe on 10/26/2018.
//

#ifndef EINDOPDRACHT_ITEM_H
#define EINDOPDRACHT_ITEM_H


#include "nostd/String.h"

class Item {
public:
    Item() = default;
    ~Item() = default;
    Item(nostd::String stat, nostd::String item_name, nostd::String on_use, int factor, int uses = 1);
    Item(const Item& copy);
    Item(Item&& move) noexcept;

    Item& operator=(const Item& copy);
    Item& operator=(Item&& move) noexcept;

    nostd::String ConsumeItem();

    nostd::String use; //return this when item gets consumed once
    nostd::String stat; //needs to match Attack, Defend, HP, AC (attack chance), DC (defend chance) or EXP
    nostd::String name; //name for the item
    int uses; //default is 1 uses, 0 uses means the item has ran out, -1 = infinite uses
    int factor; //int amount to influence matching stat.
private:
    void copy_from(const Item& copy);
    void move_from(Item& move);
};


#endif //EINDOPDRACHT_ITEM_H
