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

//    nostd::String string1 {"Hallo ik ben een string van super veel characters"};
//    const nostd::String string2 {string1};
//    const nostd::String string3 = string2;
//    nostd::String string4 {"hoeft niet; please no; I hate my lyfe; this is epic;"};
//    nostd::String* lul = string4.Split(';');
//    delete[] lul;
//    nostd::Array<int> kk{25};
//    for(int i = 0; i < kk.size(); ++i) {
//        kk.addBack(i);
//    }
//    nostd::Array<int> neus = kk;

    return 0;
    //return session.run();
}