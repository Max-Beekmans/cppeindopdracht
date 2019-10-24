#include "FightingState.h"
#include "nostd/Random.h"
#include "factory/ShipFactory.h"

FightingState::FightingState(Player& player, StateManager& stateManager) : BaseState(player, stateManager) {
    init_options();
    init_flee_lookup_table();
    generate_enemy();
}

bool FightingState::Update() {

    int op = io.HandleOptions(options);
    while(op < 0 || op > options.size() - 1) {
        io.Print("Invalid option. Select one of these options.");
        op = io.HandleOptions(options);
    }

    switch(op) {
        case 0:
            return fight();
        case 1:
            return flee();
        case 2:
            surrender();
            break;
        default:
            io.PrintLine("Please select a viable option.");
            break;
    }
    return true;
}

void FightingState::init_options() {
    options.addBack(nostd::String{"Attack"});
    options.addBack(nostd::String{"Flee"});
    options.addBack(nostd::String{"Surrender"});
}

void FightingState::init_flee_lookup_table() {
    _fleeLookupTable[0][0] = 50;
    _fleeLookupTable[1][0] = 30;
    _fleeLookupTable[2][0] = 5;
    _fleeLookupTable[0][1] = 60;
    _fleeLookupTable[1][1] = 40;
    _fleeLookupTable[2][1] = 15;
    _fleeLookupTable[0][2] = 75;
    _fleeLookupTable[1][2] = 55;
    _fleeLookupTable[2][2] = 30;
}

bool FightingState::fight() {
    shoot_enemy();
    if(_enemy.GetCurrentHp() > 0) {
        shoot_player();
        if(player.GetShip().GetCurrentHp() <= 0) {
            //gameover
            io.PrintLine("You died fighting!");
            return false;
        }
    } else {
        //won fight
        io.PrintLine("You have defeated the pirates!");
        stateManager.PopState();
    }
    return true;
}

void FightingState::shoot_player() {
    for(auto cannon : _enemy.GetCannons()) {
        for(int i = 0; i < cannon.GetAmount(); i++) {
            int damage = cannon.GetDamage();
            player.GetShip().ReceiveDamage(damage);
            io.Print("You got: ");
            io.Print(damage);
            io.PrintLine(" damage.");
            io.Print("Your ship health: ");
            io.PrintLine(player.GetShip().GetCurrentHp());
        }
    }
}

void FightingState::shoot_enemy() {
    for(auto cannon : player.GetShip().GetCannons()) {
        for(int i = 0; i < cannon.GetAmount(); i++) {
            int damage = cannon.GetDamage();
            _enemy.ReceiveDamage(damage);
            io.Print("You did: ");
            io.Print(damage);
            io.PrintLine(" damage.");
            io.Print("Enemy ship health: ");
            io.PrintLine(_enemy.GetCurrentHp());
        }
    }
}

bool FightingState::flee() {
    shoot_player();
    if(player.GetShip().GetCurrentHp() <= 0) {
        io.PrintLine(" You died like a coward.");
        return false;
    }

    nostd::Random r;

    if(r.getRand(0, 100) <= get_flee_chance(player.GetShip(), _enemy)) {
        io.PrintLine("You succesfully escaped the pirates!");
        stateManager.PopState();
    } else {
        io.PrintLine("Sadly you weren't fast enough, you are still in battle!");
    }
    return true;
}

void FightingState::surrender() {
    player.GetShip().LoseAllCargo();
    io.PrintLine("You surrender to the pirates, they steal everything they can fit on their ship and throw everything else in the sea. That's just how pirates are.");
    stateManager.PopState();
}

int FightingState::get_flee_chance(Ship& playerShip, Ship& enemyShip) {
    return _fleeLookupTable[playerShip.GetWeight()][enemyShip.GetWeight()];
}

void FightingState::generate_enemy() {
    factory::ShipFactory factory;
    _enemy = factory.CreateEnemyShip();
}