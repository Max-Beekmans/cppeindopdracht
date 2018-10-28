//
// Created by Martijn Coomans on 28-10-2018.
//

#ifndef EINDOPDRACHT_GAME_H
#define EINDOPDRACHT_GAME_H

#include "Dungeon.h"

class Game {
public:
    Game();
    ~Game();
    void Update();
    void Start();
    void Stop();
    void CreateDungeon(const int width, const int height);
private:
    bool _running;
    Dungeon* _dungeon;
};


#endif //EINDOPDRACHT_GAME_H
