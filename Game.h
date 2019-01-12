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
    Game();
    ~Game();
    void StartGame();
private:
    void PrintIntroduction();
    nostd::IOHandler io;
    //union { wind, port } either have wind object or port object?
    Port* _current_port;
    Player _player;
};


#endif //EINDOPDRACHT_GAME_H
