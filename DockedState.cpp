#include "DockedState.h"

DockedState::DockedState(Player* player, StateManager* stateManager) {
    _player = player;
    _stateManager = stateManager;
    _options.addBack(nostd::String{"Buy/Sell Cargo"});
    _options.addBack(nostd::String{"Buy/Sell Cannons"});
    _options.addBack(nostd::String{"Buy/Sell Ship"});
    _options.addBack(nostd::String{"Set Sail"});
    _options.addBack(nostd::String{"Repair Ship"});
    _options.addBack(nostd::String{"Quit Game"});
}

void DockedState::Update() {
    print_options();
}

DockedState::~DockedState() {

}

void DockedState::print_options() {
    int i = 1;
    for(auto option : _options) {
        io.Print("[");
        io.Print(i);
        io.Print("] ");
        io.PrintLine(option);
        i++;
    }
}
