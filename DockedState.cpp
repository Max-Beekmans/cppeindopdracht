#include "DockedState.h"

DockedState::DockedState(Player& player, StateManager& stateManager) : BaseState(player, stateManager), _player_ship(player.GetShip()), _current_port(player.GetCurrentPort()) {
    _options.addBack(nostd::String{"Buy/Sell Cargo"});
    _options.addBack(nostd::String{"Buy/Sell Cannons"});
    _options.addBack(nostd::String{"Buy/Sell Ship"});
    _options.addBack(nostd::String{"Set Sail"});
    _options.addBack(nostd::String{"Repair Ship"});
    _options.addBack(nostd::String{"Quit Game"});
}

DockedState::~DockedState() {}

void DockedState::Update() {
    SellCargo();
//    nostd::Array<nostd::String> arr;
//    for(const auto &i : _player.GetCurrentPort().GetCargoInventory()) {
//        arr.addBack(i.GetCargoName());
//    }
//    int op = io.HandleOptions(arr);
//    io.PrintLine(op);

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

void DockedState::SellCargo() {
    //get all cargo names aboard
    nostd::Array<nostd::String> arr;
    for(const auto &i : _player.GetShip().GetCargo()) {
        arr.addBack(i.GetCargoName());
    }
    int op = io.HandleOptions(arr);

    int f = _current_port.GetCargoInventory().find(_player_ship.GetCargo()[op]);

    _player.ReceiveGold(_current_port.GetCargoInventory()[f].GetCost());
    //remove selected cargo
    //TODO amount-- until 0 then remove
    _player.GetShip().RemoveCargo(static_cast<size_t>(op));

    this->ShowGoldBalance();
    //pick cargo to sell
    //enter amount
    //show gold
}

void DockedState::BuyCargo() {

}

void DockedState::ShowGoldBalance() {
    io.Print("Current gold: ");
    io.PrintLine(_player.GetGold());
}
