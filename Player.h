//
// Created by MaxBe on 09-Jan-19.
//

#ifndef EINDOPDRACHT_PLAYER_H
#define EINDOPDRACHT_PLAYER_H

#include "Ship.h"
#include "Port.h"

class Player {
public:
    Player() = default;
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
    const Port GetCurrentPort() {
        return _currentPort;
    }
    const Port GetDestinationPort() {
        return _destinationPort;
    }
    void SetCurrentPort(const Port& port) {
        _currentPort = port;
    }
    void SetDestinationPort(const Port& port) {
        _destinationPort = port;
    }
    void ArriveOnDestination() {
        _currentPort = _destinationPort;
    }
private:
    Ship _ship;
    Port _currentPort;
    Port _destinationPort;
    int _gold;
};


#endif //EINDOPDRACHT_PLAYER_H
