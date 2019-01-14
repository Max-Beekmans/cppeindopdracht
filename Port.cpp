//
// Created by MaxBe on 09-Jan-19.
//

#include "Port.h"

Port::Port(const nostd::String port_name, const nostd::Array<Cargo> cargo_inventory,
           const nostd::Array<Cannon> cannon_inventory, const nostd::Array<Ship> ship_inventory) :
        _port_name{port_name}, _cargo_inventory{cargo_inventory}, _cannon_inventory{cannon_inventory}, _ship_inventory{ship_inventory} {}

void Port::PrintPortHeader() {
    //_io.ClearConsole();
    _io.Print("Port name: ");
    _io.PrintLine(_port_name);
    _io.PrintDivider();
}

void Port::PrintCargo() {
    for(const auto &i : _cargo_inventory) {
        _io.Print(i);
        _io.PrintDivider();
    }
}

void Port::PrintCannons() {
    for(const auto &i : _cannon_inventory) {
        _io.Print(i);
        _io.PrintDivider();
    }
}

void Port::PrintShips() {
    for(const auto &i : _ship_inventory) {
        _io.Print(i);
        _io.PrintDivider();
    }
}

nostd::Array<Cargo>& Port::GetCargoInventory() {
    return _cargo_inventory;
}

nostd::Array<Ship>& Port::GetShipInventory() {
    return _ship_inventory;
}

nostd::Array<Cannon>& Port::GetCannonInventory() {
    return _cannon_inventory;
}

nostd::String Port::GetPortName() const {
    return _port_name;
}






