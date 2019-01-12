#ifndef EINDOPDRACHT_FIGHTINGSTATE_H
#define EINDOPDRACHT_FIGHTINGSTATE_H

#include "BaseState.h"
#include "Player.h"
#include "Ship.h"
#include "StateManager.h"

class FightingState : public BaseState {
public:
    FightingState(Player* player, StateManager* stateManager);
    ~FightingState();
    void Update() override;
    StateEnum GetName() override {
        return Fighting;
    };
private:
    Ship _enemy;
    int _fleeLookupTable[3][3];
    void print_options();
    void fight();
    void shoot(Ship originShip, Ship targetShip);
    void flee();
    void surrender();
    void generate_enemy();
    int get_flee_chance(Ship playerShip, Ship enemyShip);
    void init_options();
    void init_flee_lookup_table();
};

#endif //EINDOPDRACHT_FIGHTINGSTATE_H
