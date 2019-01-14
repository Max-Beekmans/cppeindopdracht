//
// Created by MaxBe on 11-Jan-19.
//

#include "ShipFactory.h"
#include "../nostd/Random.h"

Ship factory::ShipFactory::CreateRandomShip() {
    fileReader.Open("schepen.csv");
    nostd::Random rand;
    nostd::String ship_line = fileReader.GetNthLine(static_cast<size_t> (rand.getRand(1, 13)));
    nostd::Array<nostd::String> ship_tokens = ship_line.Tokenize(';');

    bool nospecials = true;
    nostd::String specials;
    try {
        specials = ship_tokens.at(5);
        if(!specials.isEmpty()) {
            nospecials = false;
        }
    } catch (...) {
        //ship_tokens.at(5) threw out of range error
        nospecials = true;
    }

    bool isSmall = false;
    int weight = 1;
    if(!nospecials) {
        nostd::String* s = specials.Split(',');
        nostd::String log{"log"};
        nostd::String licht{"licht"};
        nostd::String klein{"klein"};
        //',' can't be found so only one param
        if(s == nullptr) {
            if(specials == log) {
                weight = 2;
            } else if(specials == licht) {
                weight = 0;
            } else if(specials == klein) {
                isSmall = true;
            }
        } else {
            isSmall = true;
            if(s[1] == log) {
                weight = 2;
            } else if(s[1] == licht) {
                weight = 0;
            }
        }
        delete[] s;
    }

    return Ship(
            ship_tokens[0],
            atoi(ship_tokens[1].c_str()),
            atoi(ship_tokens[2].c_str()),
            atoi(ship_tokens[3].c_str()),
            atoi(ship_tokens[4].c_str()),
            weight,
            isSmall
            );
}
