//
// Created by MaxBe on 09-Jan-19.
//

#ifndef EINDOPDRACHT_GAME_H
#define EINDOPDRACHT_GAME_H

#include "nostd/IOHandler.h"
#include "Port.h"
#include "Player.h"

class Game {
public:
    Game() = default;
    ~Game() = default;
    void StartGame();
private:
    void PrintIntroduction();
    nostd::IOHandler io;
};


#endif //EINDOPDRACHT_GAME_H
