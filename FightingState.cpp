#include "FightingState.h"
#include "nostd/Random.h"

FightingState::FightingState(Player* player, StateManager* stateManager) {
    _player = player;
    _stateManager = stateManager;
    init_options();
    init_flee_lookup_table();
    generate_enemy();
}

void FightingState::Update() {

}

FightingState::~FightingState() {

}

void FightingState::init_options() {
    _options.addBack(nostd::String{"Attack"});
    _options.addBack(nostd::String{"Flee"});
    _options.addBack(nostd::String{"Surrender"});
}

void FightingState::init_flee_lookup_table() {
    _fleeLookupTable[0][0] = 50;
    _fleeLookupTable[1][0] = 30;
    _fleeLookupTable[2][0] = 5;
    _fleeLookupTable[0][1] = 60;
    _fleeLookupTable[1][1] = 40;
    _fleeLookupTable[2][1] = 15;
    _fleeLookupTable[0][1] = 75;
    _fleeLookupTable[1][1] = 55;
    _fleeLookupTable[2][1] = 30;
}

void FightingState::print_options() {
    int i = 1;
    for(auto option : _options) {
        io.Print("[");
        io.Print(i);
        io.Print("] ");
        io.PrintLine(option);
        i++;
    }
}

void FightingState::fight() {
    shoot(_player->GetShip(), _enemy);
    if(_enemy.GetCurrentHp() > 0) {
        shoot(_enemy, _player->GetShip());
        if(_player->GetShip().GetCurrentHp() <= 0) {
            //gameover
            io.PrintLine("Your ship has sunk, the game is over.");
            //TODO: actually quit the game here
        }
    } else {
        //won fight
        io.PrintLine("You have defeated the pirates!");
        _stateManager->PopState();
    }
}

void FightingState::shoot(Ship originShip, Ship targetShip) {
    //targetShip.ReceiveDamage(originShip);
}

void FightingState::flee() {
    shoot(_enemy, _player->GetShip());

    nostd::Random r;

    //TODO: player needs a ship getter
    if(r.getRand(0, 100) <= get_flee_chance(_player->GetShip(), _enemy)) {
        io.PrintLine("You succesfully escaped the pirates!");
        _stateManager->PopState();
    } else {
        io.PrintLine("Sadly you weren't fast enough, you are still in battle!");
    }
}

void FightingState::surrender() {

}

int FightingState::get_flee_chance(Ship playerShip, Ship enemyShip) {
    return _fleeLookupTable[playerShip.GetWeight()][enemyShip.GetWeight()];
}

void FightingState::generate_enemy() {
    //TODO: we need a ShipFactory where you can get a random ship (as an enemy)
    _enemy = Ship(nostd::String{"Hallo"}, 200, 400, 9001, 2, 0, 0);
}