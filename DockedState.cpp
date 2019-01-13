#include "DockedState.h"

DockedState::DockedState(Player& player, StateManager& stateManager) : BaseState(player, stateManager), _player_ship(player.GetShip()), _current_port(player.GetCurrentPort()) {
    _options.addBack(nostd::String{"Buy cargo"});
    _options.addBack(nostd::String{"Sell cargo"});
    _options.addBack(nostd::String{"Buy cannons"});
    _options.addBack(nostd::String{"Sell cannons"});
    _options.addBack(nostd::String{"Buy/sell ship"});
    _options.addBack(nostd::String{"Set sail"});
    _options.addBack(nostd::String{"Repair Ship"});
    _options.addBack(nostd::String{"Quit Game"});
}

DockedState::~DockedState() {}

void DockedState::Update() {
    int op = io.HandleOptions(_options);
    switch (op) {
        case 0:
            BuyCargo();
            break;
        case 1:
            SellCargo();
        case 2:
            BuyCannons();
            break;
        case 3:
            //SellCannons();
            break;
        case 4:
            BuyShip();
            break;
        case 5:
            //SailTo(port_name);
            break;
        case 6:
            //RepairShip();
            break;
        case 7:
            //QuitLife();
            break;
        case -1:
            io.Print(op);
            io.PrintLine("Invalid choice");
            break;
        default:
            io.Print(op);
            io.PrintLine("Invalid choice");
    }
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
    //we print in order of arr so we know op is the index of the cargo to be sold from the player ship
    int op = io.HandleOptions(arr);
    if(op == -1){
        return;
    }
    io.Print("How many: ");
    io.Print(_player_ship.GetCargo()[op].GetCargoName());
    io.PrintLine(" Would you like to sell: ");
    int amount = io.GetInt();
    int x = _player_ship.GetCargo()[op].DeductAmount(amount);
    while(x == -1) {
        io.Print("Invalid amount. You can only sell a max of: ");
        io.PrintLine(_player_ship.GetCargo()[op].GetAmount());
        amount = io.GetInt();
        x = _player_ship.GetCargo()[op].DeductAmount(amount);
    }

    _player_ship.DecreaseSpace(amount);

    //find what the port will buy the selected cargo for
    int f = _current_port.GetCargoInventory().find(_player_ship.GetCargo()[op]);

    //remove selected cargo from array if amount == 0
    if(x == 0) {
        _player.GetShip().RemoveCargo(static_cast<size_t>(op));
    }

    //Notify player of his gold and what he just sold for.
    io.Print("Sold for: ");
    io.PrintLine(_current_port.GetCargoInventory()[f].GetCost() * amount);
    _player.ReceiveGold(_current_port.GetCargoInventory()[f].GetCost() * amount);

    this->ShowGoldBalance();
}

void DockedState::BuyCargo() {
    _current_port.PrintCargo();
    nostd::Array<nostd::String> arr;
    for(const auto &i : _current_port.GetCargoInventory()) {
        arr.addBack(i.GetCargoName());
    }
    int op = io.HandleOptions(arr);
    if(op == -1) {
        return;
    }
    io.Print("How many: ");
    io.Print(_current_port.GetCargoInventory()[op].GetCargoName());
    io.PrintLine(" Would you like to buy: ");

    int amount = io.GetInt();

    while((_current_port.GetCargoInventory()[op].GetCost() * amount) > _player.GetGold()) {
        io.PrintLine("You can't afford this. Enter different amount or -1 to cancel");
        amount = io.GetInt();
        if(amount == -1) {
            return;
        }
    }

    if(amount > _player_ship.CargoSpaceLeft()) {
        io.PrintLine("You don't have enough space left");
        return;
    }

    _player_ship.IncreaseSpace(amount);

    int x = _current_port.GetCargoInventory()[op].DeductAmount(amount);
    while(x == -1) {
        io.Print("Invalid amount. You can only buy a max of: ");
        io.PrintLine(_current_port.GetCargoInventory()[op].GetAmount());
        amount = io.GetInt();
        x = _current_port.GetCargoInventory()[op].DeductAmount(amount);
    }

    int f = _player_ship.GetCargo().find(_current_port.GetCargoInventory()[op]);
    //Player doesn't have this cargo yet so add new object to it's ship
    if(f == -1) {
        Cargo c {_current_port.GetCargoInventory()[op].GetCargoName(), _current_port.GetCargoInventory()[op].GetCost(), amount};
        _player_ship.AddCargo(c);
    } else {
        _player_ship.GetCargo()[f].IncreaseAmount(amount);
    }

    //Notify player of his gold and what he just sold for.
    io.Print("Bought for: ");
    io.PrintLine(_current_port.GetCargoInventory()[f].GetCost() * amount);
    _player.LoseGold(_current_port.GetCargoInventory()[f].GetCost() * amount);

    this->ShowGoldBalance();
}

void DockedState::ShowGoldBalance() {
    io.Print("Current gold: ");
    io.PrintLine(_player.GetGold());
}

void DockedState::BuyCannons() {
    nostd::Array<nostd::String> arr;
    for(const auto &i : _current_port.GetCannonInventory()) {
        arr.addBack(i.GetStringWeight());
    }

    int op = io.HandleOptions(arr);

    if(_current_port.GetCannonInventory()[op].GetAmount() <= 0) {
        io.PrintLine("not enough stock");
        return;
    }

    //if(_player_ship.GetMaxCannons())
}

void DockedState::BuyShip() {
    nostd::Array<nostd::String> arr;
    for(const auto &i : _current_port.GetShipInventory()) {
        arr.addBack(i.GetType());
    }

    int op = io.HandleOptions(arr);
    if(_current_port.GetShipInventory()[op].GetCost() - (_player_ship.GetCost() / 2) > _player.GetGold()) {
        io.PrintLine("You can't afford this ship");
        return;
    }
    _player_ship = _current_port.GetShipInventory()[op];
}
