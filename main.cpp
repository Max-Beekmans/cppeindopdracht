#include <iostream>

#include "nostd/String.h"
#include "nostd/Array.h"
#include "nostd/Random.h"
#include "Game.h"

int main() {
    Game* game = new Game();

    game->Start();

    return 0;
}