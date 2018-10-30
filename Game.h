//
// Created by Martijn Coomans on 28-10-2018.
//

#ifndef EINDOPDRACHT_GAME_H
#define EINDOPDRACHT_GAME_H

#include "Dungeon.h"
#include "Hero.h"
#include "nostd/Array.h"
#include "nostd/String.h"
#include "nostd/IOHandler.h"
#include "Room.h"

class Game {
public:
    Game();
    ~Game();
    void PrintMap(const int layer);
    void GetInput(Room room, Monster* m);
    void StartFight(Monster* m);
    void Start();
    void Stop();
    void Run();
    void EnterRoom(Room room);
private:
    //TODO move user input to IO class
    int GetInt();
    nostd::String GetString();
    void GetMonsters();
    Monster* GetMonster(const int layer);

    //TODO move prints to IO class
    void ClearConsole();
    void PrintDivider();
    void PrintLegend();
    Dungeon _dungeon_layers[5];
    nostd::Array<Monster> _monsters;
    int _current_layer = 0;
    Hero _hero;
    nostd::IOHandler _io;
};


#endif //EINDOPDRACHT_GAME_H
