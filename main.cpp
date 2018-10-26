#include <iostream>

#include "nostd/String.h"
#include "nostd/Array.h"
#include "nostd/Random.h"
#include "Dungeon.h"

int main() {
    Dungeon dungeon = Dungeon(5, 5);

    std::cout << "Generated Dungeon" << std::endl;
    dungeon.GenerateDungeon();
    dungeon.PrintDungeon();
    return 0;
}