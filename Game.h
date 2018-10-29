//
// Created by Martijn Coomans on 28-10-2018.
//

#ifndef EINDOPDRACHT_GAME_H
#define EINDOPDRACHT_GAME_H

#include "Dungeon.h"
#include "nostd/Array.h"
#include "nostd/String.h"

class Game {
public:
    Game();
    ~Game();
    void PrintMap(const int layer);

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
    void PrintLegend();
    Dungeon _dungeon_layers[5];
    int _current_layer = 0;
};


#endif //EINDOPDRACHT_GAME_H
