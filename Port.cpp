//
// Created by MaxBe on 09-Jan-19.
//

#include "Port.h"

Port::Port(const nostd::String port_name, const nostd::Array<Cargo> cargo_inventory,
           const nostd::Array<Cannon> cannon_inventory, const nostd::Array<Ship> ship_inventory) :
        _port_name{port_name}, _cargo_inventory{cargo_inventory}, _cannon_inventory{cannon_inventory}, _ship_inventory{ship_inventory} {}

Port::~Port() = default;

void Port::PrintValues() {
    PrintPortHeader();
    PrintCargo();
    PrintShips();
    PrintCannons();
//    nostd::IOHandler io{};
//    io.Print("Port name: ");
//    io.PrintLine(_port_name);
//    io.PrintLine("Cargo inv: ");
//    for(const auto &i : _cargo_inventory) {
//        io.Print(i);
//    }
//    io.PrintLine("Cannon inv: ");
//    for(const auto &j : _cannon_inventory) {
//        io.Print(j);
//    }
//    io.PrintLine("Ship inv: ");
//    for(const auto &k : _ship_inventory) {
//        io.Print(k);
//    }
}

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

const nostd::Array<Cargo>& Port::GetCargoInventory() const {
    return _cargo_inventory;
}






