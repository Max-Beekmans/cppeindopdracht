#include <utility>

//
// Created by MaxBe on 09-Jan-19.
//

#include "PortFactory.h"
#include "ShipFactory.h"
#include "../exceptions/PortNotFoundException.h"
#include "../nostd/Random.h"

//TODO remove
#include "../nostd/IOHandler.h"

Port factory::PortFactory::CreatePort(nostd::String port_name) {
    nostd::Array<Cargo> cargo_arr{10};
    nostd::Array<Cannon> cannon_arr{10};
    nostd::Array<Ship> ship_arr{10};
    nostd::Random r;

    int random_ships = r.getRand(1 ,5);
    //get between 1 and 5 random ships from ShipFactory
    for (int j = 0; j < random_ships; ++j) {
        ShipFactory sf;
        Ship random_ship = sf.CreateRandomShip();
        ship_arr.addBack(random_ship);
    }

    Cannon light_cannon{0, 50, r.getRand(0, 5)};
    Cannon medium_cannon{1, 200, r.getRand(0, 3)};
    Cannon heavy_cannon{2, 1000, r.getRand(0, 2)};
    cannon_arr.addBack(light_cannon);
    cannon_arr.addBack(medium_cannon);
    cannon_arr.addBack(heavy_cannon);

    //Assumed is that both files have the same first_row indicating all possible goods
    _fr.Open("goederen_prijzen.csv");
    nostd::String* first_row {_fr.GetSpecificLine(nostd::String{""})};
    nostd::String* raw_prices_line {_fr.GetSpecificLine(port_name)};

    //TODO make some exception handling here.
    _fr.Close();
    _fr.Open("goederen_hoeveelheid.csv");
    nostd::String* raw_stock_line {_fr.GetSpecificLine(port_name)};

    if(first_row == nullptr || raw_prices_line == nullptr || raw_stock_line == nullptr) {
        throw exceptions::PortNotFoundException("Port name could not be found in file");
    } else {
        nostd::Array<nostd::String> price_tokens = raw_prices_line->Tokenize(';');
        nostd::Array<nostd::String> stock_tokens = raw_stock_line->Tokenize(';');
        nostd::Array<nostd::String> first_row_tokens = first_row->Tokenize(';');
        //skip the first column
        for (int i = 1; i < first_row_tokens.size(); ++i) {
            nostd::String cargo_name {first_row_tokens[i]};
            nostd::String* split_price_ptr = price_tokens[i].Split('-');
            nostd::String* split_stock_ptr = stock_tokens[i].Split('-');
            nostd::Range price_range{atoi(split_price_ptr[0].c_str()), atoi(split_price_ptr[1].c_str())};
            nostd::Range stock_range{atoi(split_stock_ptr[0].c_str()), atoi(split_stock_ptr[1].c_str())};
            cargo_arr.addBack(Cargo{cargo_name, price_range.GetRandom(), stock_range.GetRandom()});
            delete[] split_price_ptr;
            delete[] split_stock_ptr;
        }
    }

    delete first_row;
    delete raw_prices_line;
    delete raw_stock_line;

    return Port(port_name, cargo_arr, cannon_arr, ship_arr);
}
