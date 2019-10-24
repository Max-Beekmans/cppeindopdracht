#ifndef EINDOPDRACHT_FIGHTINGCONTROLLER_H
#define EINDOPDRACHT_FIGHTINGCONTROLLER_H

#include "Player.h"
#include "Ship.h"
#include "GameController.h"

class FightingController {
public:
    FightingController(Player& player, GameController& game);
    ~FightingController() = default;
    bool Update() override;
private:
    Ship _enemy;
    int _fleeLookupTable[3][3];
    bool fight();
    void shoot_player();
    void shoot_enemy();
    void shoot(Ship originShip, Ship targetShip);
    void flee();
    void surrender();
    void generate_enemy();
    int get_flee_chance(Ship& playerShip, Ship& enemyShip);
    void init_options();
    void init_flee_lookup_table();
};

#endif //EINDOPDRACHT_FIGHTINGCONTROLLER_H
