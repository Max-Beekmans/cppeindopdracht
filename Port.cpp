//
// Created by MaxBe on 09-Jan-19.
//

#include "Port.h"

Port::Port(const nostd::String port_name, const nostd::Array<Cargo> cargo_inventory, const nostd::Array<Ship> ship_inventory) :
        _port_name{port_name}, _cargo_inventory{cargo_inventory}, _ship_inventory{ship_inventory} {

}

Port::~Port() {}
