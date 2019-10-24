//
// Created by MaxBe on 11-Jan-19.
//

#include "ShipFactory.h"
#include "../nostd/Random.h"

models::Ship factories::ShipFactory::CreateRandomShip() {
    fileReader.Open("schepen.csv");
    nostd::Random rand;
    std::string ship_line = fileReader.GetNthLine(static_cast<size_t> (rand.getRand(1, 13)));
    nostd::Array<std::string> ship_tokens = ship_line.Tokenize(';');

    bool nospecials = true;
    std::string specials;
    try {
        specials = ship_tokens.at(5);
        if(specials.size() != 0) {
            nospecials = false;
        }
    } catch (...) {
        //ship_tokens.at(5) threw out of range error
        nospecials = true;
    }

    bool isSmall = false;
    int weight = 1;
    if(!nospecials) {
        std::string* s = specials.Split(',');
        std::string log{"log"};
        std::string licht{"licht"};
        std::string klein{"klein"};
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

    return models::Ship(
            ship_tokens[0],
            atoi(ship_tokens[1].c_str()),
            atoi(ship_tokens[2].c_str()),
            atoi(ship_tokens[3].c_str()),
            atoi(ship_tokens[4].c_str()),
            weight,
            isSmall
            );
}

models::Ship factories::ShipFactory::CreateEnemyShip() {
    models::Ship s = CreateRandomShip();
    nostd::Random rand;
    int cannons = rand.getRand(0, s.GetMaxCannons());

    for (int i = 0; i < cannons; ++i) {
        models::Cannon c;
        int weight = 0;
        if(s.IsSmall()){
            //only light or heavy cannons
            weight = rand.getRand(0, 1);
        } else {
            //all cannons
            weight = rand.getRand(0, 2);
        }

        switch (weight) {
            case 0:
                c = models::Cannon{weight, 50, 1};
                break;
            case 1:
                c = models::Cannon{weight, 200, 1};
                break;
            case 2:
                c = models::Cannon{weight, 1000, 1};
                break;
        }
        int x = s.GetCannons().find(c);
        if(x < 0) {
            s.AddCannon(c);
        } else {
            s.GetCannons()[x].IncreaseAmount(1);
        }
    }
    return s;
}
