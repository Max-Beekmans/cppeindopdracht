//
// Created by MaxBe on 09-Jan-19.
//

#ifndef EINDOPDRACHT_GAME_H
#define EINDOPDRACHT_GAME_H

#include "nostd/IOHandler.h"
#include "Port.h"

class Game {
public:
    Game();
    ~Game();
    void StartGame();
private:
    void PrintIntroduction();
    nostd::IOHandler io;
    //union { wind, port } either have wind object or port object?
    Port* current_port;
};


#endif //EINDOPDRACHT_GAME_H
