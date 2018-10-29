#include <iostream>

#include "nostd/String.h"
#include "nostd/Array.h"
#include "nostd/Random.h"
#include "Game.h"

int main() {
    Game g {};
    g.Start();
    g.Stop();
    char c[65];
    std::cin >> c;
    return 0;
}