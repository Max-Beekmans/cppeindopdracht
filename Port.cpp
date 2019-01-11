//
// Created by MaxBe on 09-Jan-19.
//

#include "Port.h"

Port::Port(const nostd::String port_name, const nostd::Array<Cargo> cargo_inventory,
           const nostd::Array<Cannon> cannon_inventory, const nostd::Array<Ship> ship_inventory) :
        _port_name{port_name}, _cargo_inventory{cargo_inventory}, _cannon_inventory{cannon_inventory}, _ship_inventory{ship_inventory} {
    nostd::IOHandler io;
    io.PrintLine(_port_name);
}

Port::~Port() = default;

void Port::PrintValues() {
    nostd::IOHandler io{};
    io.Print("Port name: ");
    io.PrintLine(_port_name);
    io.Print("Cargo inv: ");
    for(auto i : _cargo_inventory) {
        io.Print(i);
        io.Print(" ,");
    }
    io.PrintLine(' ');
    io.Print("Cannon inv: ");
    for(auto j : _cannon_inventory) {
        io.Print(j);
        io.Print(" ,");
    }
    io.PrintLine(' ');
    io.Print("Ship inv: ");
    for(auto k : _ship_inventory) {
        io.Print(k);
        io.Print(" ,");
    }
    io.PrintLine(' ');
}


