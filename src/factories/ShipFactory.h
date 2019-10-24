//
// Created by MaxBe on 11-Jan-19.
//

#ifndef EINDOPDRACHT_SHIPFACTORY_H
#define EINDOPDRACHT_SHIPFACTORY_H

#include "Factory.h"
#include "../models/Ship.h"

namespace factories {
    class ShipFactory : Factory {
    public:
        Ship CreateRandomShip();
        Ship CreateEnemyShip();
    };
}

#endif //EINDOPDRACHT_SHIPFACTORY_H
