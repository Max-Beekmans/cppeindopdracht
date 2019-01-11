//#define CATCH_CONFIG_RUNNER
//#include "test/catch2/catch.hpp"

#include <iostream>

#include "nostd/String.h"
#include "nostd/Array.h"
#include "nostd/Random.h"
#include "nostd/Range.h"
#include "Ship.h"
#include "nostd/IOHandler.h"
#include "Game.h"
#include "StateManager.h"
#include "DockedState.h"
#include "SailingState.h"
#include "FightingState.h"
#include "nostd/Stack.h"
#include "BaseState.h"
//#include "FileReader.h"

int main(int argc, char* argv[]) {
//    Catch::Session session;
//
//    auto exitCode = session.applyCommandLine(argc, argv);
//    if(exitCode != 0) {
//        return exitCode;
//    }

    Game g{};
    g.StartGame();

    return 0;
    //return session.run();
}