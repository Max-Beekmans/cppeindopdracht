//
// Created by MaxBe on 09-Jan-19.
//
#ifndef EINDOPDRACHT_PLAYER_H
#define EINDOPDRACHT_PLAYER_H

#define STARTING_GOLD 1000

#include "Ship.h"
#include "Port.h"

class Player {
public:
    Player(Ship& starting_ship, nostd::String port) : _ship(starting_ship), _gold(STARTING_GOLD), _destinationPort(port) {}
    ~Player() = default;

    void ReceiveGold(int gold) {
        _gold += gold;
    }
    void LoseGold(int gold) {
        _gold -= gold;
    }
    const int GetGold() {
        return _gold;
    }
    Ship& GetShip() {
        return _ship;
    }
    void SetShip(Ship ship) {
        _ship = ship;
    }
    const nostd::String GetDestinationPort() {
        return _destinationPort;
    }
    void SetDestinationPort(const nostd::String port) {
        _destinationPort = port;
    }
private:
    Ship& _ship;
    nostd::String _destinationPort;
    int _gold;
};


#endif //EINDOPDRACHT_PLAYER_H
