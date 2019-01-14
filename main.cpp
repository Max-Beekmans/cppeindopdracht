//#define CATCH_CONFIG_RUNNER
//#include "test/catch2/catch.hpp"

#include "Game.h"

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