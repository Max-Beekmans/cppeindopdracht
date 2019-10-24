//
// Created by MaxBe on 09-Jan-19.
//

#include "Port.h"

models::Port::Port(const std::string port_name, const nostd::Array<Cargo> cargo_inventory,
           const nostd::Array<Cannon> cannon_inventory, const nostd::Array<Ship> ship_inventory) {
    _port_name = port_name;
    _cargo_inventory = cargo_inventory;
    _cannon_inventory = cannon_inventory;
    _ship_inventory = ship_inventory;
}

void models::Port::PrintPortHeader() {
    //_io.ClearConsole();
    _io.Print("Port name: ");
    _io.PrintLine(_port_name);
    _io.PrintDivider();
}

void models::Port::PrintCargo() {
    for(const auto &i : _cargo_inventory) {
        _io.Print(i);
        _io.PrintDivider();
    }
}

void models::Port::PrintCannons() {
    for(const auto &i : _cannon_inventory) {
        _io.Print(i);
        _io.PrintDivider();
    }
}

void models::Port::PrintShips() {
    for(const auto &i : _ship_inventory) {
        _io.Print(i);
        _io.PrintDivider();
    }
}

nostd::Array<models::Cargo>& models::Port::GetCargoInventory() {
    return _cargo_inventory;
}

nostd::Array<models::Ship>& models::Port::GetShipInventory() {
    return _ship_inventory;
}

nostd::Array<models::Cannon>& models::Port::GetCannonInventory() {
    return _cannon_inventory;
}

std::string models::Port::GetPortName() const {
    return _port_name;
}






