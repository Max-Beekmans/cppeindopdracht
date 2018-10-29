//
// Created by Martijn Coomans on 28-10-2018.
//

#ifndef EINDOPDRACHT_GAME_H
#define EINDOPDRACHT_GAME_H

#include "Dungeon.h"
#include "Hero.h"
#include "nostd/Array.h"
#include "nostd/String.h"

class Game {
public:
    Game();
    ~Game();
    void PrintMap();
    void PrintHeroStats();

    void Update();
    void Start();
    void Stop();

private:
    //TODO move user input to IO class
    int GetInt();
    nostd::String GetString();

    //TODO move prints to IO class
    void ClearConsole();
    void PrintDivider();
    Dungeon _dungeon_layers[5];
    int _current_layer = 0;
    Hero _hero;

};


#endif //EINDOPDRACHT_GAME_H
