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
            SellCannons();
            break;
        case 4:
            BuyShip();
            break;
        case 5:
            //SailTo(port_name);
            break;
        case 6:
            RepairShip();
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
        if(amount < 0) {
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

void DockedState::ShowShipHealth() {
    io.Print("Your ships health: ");
    io.Print(_player_ship.GetCurrentHp());
    io.Print("/");
    io.PrintLine(_player_ship.GetMaxHp());
}

void::DockedState::SellCannons() {
    if(_player.GetShip().GetCannons().size() < 1) {
        io.PrintLine("You don't have any cannons to sell.");
        return;
    }

    //get all cannon weights aboard
    nostd::Array<nostd::String> arr;
    for(const auto &i : _player.GetShip().GetCannons()) {
        arr.addBack(i.GetStringWeight());
    }

    //we print in order of arr so we know op is the index of the cannon to be sold from the player ship
    int op = io.HandleOptions(arr);

    //0 or smaller returns you to the options
    if(op < 0) {
        return;
    }

    io.Print("How many: ");
    io.Print(_player_ship.GetCannons()[op].GetStringWeight());
    io.PrintLine(" Would you like to sell: ");
    int amount = io.GetInt();
    int x = _player_ship.GetCannons()[op].DeductAmount(amount);
    while(x == -1) {
        io.Print("Invalid amount. You can only sell a max of: ");
        io.PrintLine(_player_ship.GetCannons()[op].GetAmount());
        amount = io.GetInt();
        x = _player_ship.GetCannons()[op].DeductAmount(amount);
    }

    //find what the port will buy the selected cannon for
    int f = _current_port.GetCannonInventory().find(_player_ship.GetCannons()[op]);

    //remove selected cargo from array if amount == 0
    if(x == 0) {
        _player.GetShip().RemoveCannon(static_cast<size_t>(op));
    }

    //Notify player of his gold and what he just sold for.
    io.Print("Sold for: ");
    io.PrintLine(_current_port.GetCannonInventory()[f].GetCost() * amount);
    _player.ReceiveGold(_current_port.GetCannonInventory()[f].GetCost() * amount);

    this->ShowGoldBalance();
}

void DockedState::BuyCannons() {
    nostd::Array<nostd::String> arr;
    for(const auto &i : _current_port.GetCannonInventory()) {
        arr.addBack(i.GetStringWeight());
    }

    int op = io.HandleOptions(arr);

    //0 or smaller returns you to the options
    if(op < 0) {
        return;
    }

    if(_current_port.GetCannonInventory()[op].GetWeight() == 2 && _player_ship.IsSmall()) {
        io.PrintLine("You can't use heavy cannons on a small ship.");
        return;
    }

    io.Print("How many: ");
    io.Print(_current_port.GetCannonInventory()[op].GetStringWeight());
    io.PrintLine("s Would you like to buy: ");

    int amount = io.GetInt();

    while((_current_port.GetCannonInventory()[op].GetCost() * amount) > _player.GetGold()) {
        io.PrintLine("You can't afford this. Enter different amount or -1 to cancel");
        amount = io.GetInt();
        if(amount < 0) {
            return;
        }
    }

    if(_current_port.GetCannonInventory()[op].GetAmount() < amount) {
        io.Print("Not enough stock, we only have ");
        io.Print(_current_port.GetCannonInventory()[op].GetAmount());
        io.Print(_current_port.GetCannonInventory()[op].GetStringWeight());
        io.PrintLine("s in stock.");
        return;
    }

    if(_player_ship.GetCannonAmount() + amount > _player_ship.GetMaxCannons()) {
        io.PrintLine("You don't have room for that much cannons.");
        io.Print("You have ");
        io.Print(_player_ship.GetMaxCannons() - _player_ship.GetCannonAmount());
        io.PrintLine("free spots for cannons.");
        return;
    }

    int f = _player_ship.GetCannons().find(_current_port.GetCannonInventory()[op]);
    //Player doesn't have this cannon yet so add new object to it's ship
    if(f == -1) {
        Cannon c {_current_port.GetCannonInventory()[op].GetWeight(), _current_port.GetCannonInventory()[op].GetCost(), amount};
        _player_ship.AddCannon(c);
    } else {
        _player_ship.GetCannons()[f].IncreaseAmount(amount);
    }

    //Notify player of his gold and what he just sold for.
    io.Print("Bought for: ");
    io.PrintLine(_current_port.GetCannonInventory()[f].GetCost() * amount);
    _player.LoseGold(_current_port.GetCannonInventory()[f].GetCost() * amount);

    this->ShowGoldBalance();
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

void DockedState::RepairShip() {
    _player_ship.ReceiveDamage(93);
    if(_player_ship.GetCurrentHp() == _player_ship.GetMaxHp()) {
        io.PrintLine("Your ship is in perfect condition. You don't need to repair your ship.");
        return;
    }
    io.PrintLine("Repairing your ship will cost 1 gold per 10 health points.");
    ShowShipHealth();
    ShowGoldBalance();
    io.Print("How much gold would you like to spend to restore your ship?");
    io.Print(" (max: ");
    int maxRepair = (_player_ship.GetMaxHp() - _player_ship.GetCurrentHp()) / 10 + ((_player_ship.GetMaxHp() - _player_ship.GetCurrentHp()) % 10 != 0);
    io.Print(maxRepair);
    io.PrintLine(")");
    int gold = io.GetInt();
    if(gold > _player.GetGold()) {
        io.PrintLine("You can't afford these repairments. Choose for a cheaper repairment.");
        ShowGoldBalance();
        return;
    } else if(gold < 0 || gold > maxRepair) {
        io.Print("Invalid amount. You can only use a max of: ");
        io.Print(maxRepair);
        io.PrintLine(" gold.");
        return;
    }
    _player_ship.RestoreHp(gold * 10);
    _player.LoseGold(gold);
    io.Print("Your ship has been repaired for ");
    io.Print(gold);
    io.PrintLine(" gold.");
    ShowShipHealth();
}
