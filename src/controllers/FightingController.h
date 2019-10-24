#ifndef EINDOPDRACHT_FIGHTINGCONTROLLER_H
#define EINDOPDRACHT_FIGHTINGCONTROLLER_H

#include "../models/Ship.h"
#include "GameController.h"

namespace controllers {
    class FightingController {
    public:
        FightingController(GameController& game);

        ~FightingController() = default;

        bool Update();

    private:
        models::Ship _enemy;
        int _fleeLookupTable[3][3];

        bool fight();

        void shoot_player();

        void shoot_enemy();

        void shoot(models::Ship originShip, models::Ship targetShip);

        void flee();

        void surrender();

        void generate_enemy();

        int get_flee_chance(models::Ship &playerShip, models::Ship &enemyShip);

        void init_options();

        void init_flee_lookup_table();
    };
}

#endif //EINDOPDRACHT_FIGHTINGCONTROLLER_H
