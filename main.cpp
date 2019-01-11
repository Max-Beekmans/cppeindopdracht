//#define CATCH_CONFIG_RUNNER
//#include "test/catch2/catch.hpp"

#include <iostream>

#include "nostd/String.h"
#include "nostd/Array.h"
#include "nostd/Random.h"
#include "nostd/Range.h"
#include "Ship.h"
#include "nostd/IOHandler.h"
#include "Game.h"
#include "StateManager.h"
#include "DockedState.h"
#include "SailingState.h"
#include "FightingState.h"
#include "nostd/Stack.h"
#include "BaseState.h"
//#include "FileReader.h"

int main(int argc, char* argv[]) {
//    Catch::Session session;
//
//    auto exitCode = session.applyCommandLine(argc, argv);
//    if(exitCode != 0) {
//        return exitCode;
//    }

    Ship ship(nostd::String{"Hallo"}, 200, 400, 9001, 2, 0, 0);
    nostd::Range range{1, 3};
    int x = range.GetRandom();
    std::cout << x << std::endl;
    nostd::IOHandler io {};

    Cargo cargo_one{nostd::String{"Cargo one"}, 100, 10};
    Cargo cargo_two{nostd::String{"Cargo two"}, 150, 20};
    Cargo cargo_three{nostd::String{"Cargo three"}, 100, 10};
    Cargo cargo_four{nostd::String{"Cargo four"}, 150, 20};
    Cargo cargo_five{nostd::String{"Cargo five"}, 100, 10};
    Cargo cargo_six{nostd::String{"Cargo six"}, 150, 20};
    Cargo cargo_seven{nostd::String{"Cargo seven"}, 100, 10};
    Cargo cargo_eight{nostd::String{"Cargo eight"}, 150, 20};
    Cargo cargo_nine{nostd::String{"Cargo nine"}, 100, 10};
    Cargo cargo_ten{nostd::String{"Cargo ten"}, 150, 20};
    Cargo cargo_eleven{nostd::String{"Cargo eleven"}, 100, 10};
    Cargo cargo_twelve{nostd::String{"Cargo twelve"}, 150, 20};

    nostd::Array<Cargo> cargo_arr;
    cargo_arr.addBack(cargo_one);
    cargo_arr.addBack(cargo_two);
    cargo_arr.addBack(cargo_three);
    cargo_arr.addBack(cargo_four);
    cargo_arr.addBack(cargo_five);
    cargo_arr.addBack(cargo_six);
    cargo_arr.addBack(cargo_seven);
    cargo_arr.addBack(cargo_eight);
    cargo_arr.addBack(cargo_nine);
    cargo_arr.addBack(cargo_ten);
    cargo_arr.addBack(cargo_eleven);
    cargo_arr.addBack(cargo_twelve);


    for(const auto &i : cargo_arr) {
        io.PrintLine(i);
    }

    nostd::Array<Cargo> cargo_arr_cpy{cargo_arr};

    for(const auto &j : cargo_arr_cpy) {
        io.PrintLine(j);
    }

    const nostd::Array<Cargo> cargo_arr_cpy2{cargo_arr_cpy};

    for(const auto &j : cargo_arr_cpy2) {
        io.PrintLine(j);
    }

    io.PrintLine(cargo_arr.size());
    io.PrintLine(cargo_arr_cpy.size());

////    nostd::String port_name{"Roatan"};
////    nostd::Array<Cargo> cargo_arr{10};
////    nostd::Array<Cannon> cannon_arr{10};
////    nostd::Array<Ship> ship_arr{10};
////
////    Port* current_port = new Port(port_name, cargo_arr, cannon_arr, ship_arr);
////    current_port->PrintValues();
//    Game g = Game{};
//    g.StartGame();
//    FileReader fr{"goederen_hoeveelheid.csv"};
//    while(!fr.EndOfFile()) {
//        nostd::String s = fr.GetLine();
//        if(s[0] != '#') {
//            io.PrintLine(s);
//            nostd::Array<nostd::String> token_arr{s.Tokenize(';')};
//            for(int i = 0; i <= token_arr.size(); i++) {
//                io.PrintLine(token_arr[i]);
//            }
//        }
//    }


    //io.GetString();
    return 0;
    //return session.run();
}