//
// Created by MaxBe on 11-Jan-19.
//

#ifndef EINDOPDRACHT_SHIPFACTORY_H
#define EINDOPDRACHT_SHIPFACTORY_H

#include "Factory.h"
#include "../Ship.h"

namespace factory {
    class ShipFactory : Factory {
    public:
        Ship CreateRandomShip();
    };
}

#endif //EINDOPDRACHT_SHIPFACTORY_H
