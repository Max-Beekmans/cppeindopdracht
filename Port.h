//
// Created by MaxBe on 09-Jan-19.
//

#ifndef EINDOPDRACHT_PORT_H
#define EINDOPDRACHT_PORT_H

#include "nostd/String.h"
#include "Cargo.h"
#include "Cannon.h"
#include "Ship.h"

//create this class on arriving in a port.
//Have builder class assign a value within the range of the data from the files
//Builder class needs to be static so that there is only a couple static data lists.
class Port {
public:
    Port(const nostd::String port_name, const nostd::Array<Cargo> cargo_inventory, const nostd::Array<Ship> ship_inventory);
    ~Port();
private:
    //once created we don't change the values of the port until we reach a new port.
    const nostd::String _port_name;
    const nostd::Array<Cargo> _cargo_inventory;
    const nostd::Array<Cannon> _cannon_inventory;
    const nostd::Array<Ship> _ship_inventory;
};


#endif //EINDOPDRACHT_PORT_H
