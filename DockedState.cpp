#include "DockedState.h"
#include "FileReader.h"
#include "SailingState.h"
#include "Factory/PortFactory.h"
#include "exceptions/PortNotFoundException.h"

DockedState::DockedState(Player& player, StateManager& stateManager) : BaseState(player, stateManager), _player_ship(player.GetShip()) {
    factory::PortFactory pf{};
    try {
        _current_port = pf.CreatePort(player.GetDestinationPort());
    } catch(exceptions::PortNotFoundException &e) {
        io.PrintLine(e.what());
    }
    options.addBack(nostd::String{"Buy cargo"});
    options.addBack(nostd::String{"Sell cargo"});
    options.addBack(nostd::String{"Buy cannons"});
    options.addBack(nostd::String{"Sell cannons"});
    options.addBack(nostd::String{"Buy/sell ship"});
    options.addBack(nostd::String{"Set sail"});
    options.addBack(nostd::String{"Repair Ship"});
    options.addBack(nostd::String{"Quit Game"});
}

bool DockedState::Update() {
    _current_port.PrintPortHeader();
    int op = io.HandleOptions(options);
    switch (op) {
        case 0:
            BuyCargo();
            break;
        case 1:
            SellCargo();
            break;
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
            SailTo();
            break;
        case 6:
            RepairShip();
            break;
        case 7:
            //QuitLife();
            return false;
        case -1:
            io.Print(op);
            io.PrintLine("Invalid choice");
            return false;
        default:
            io.Print(op);
            io.PrintLine("Invalid choice");
            return false;
    }
    return true;
}
//pick cargo you want to sell
//enter how much you want to sell. Can't be more than what you have or a negative value
//decrease space used on your ship
//find how much the port will buy it for
//receive gold
void DockedState::SellCargo() {
    //get all cargo names aboard
    nostd::Array<nostd::String> arr{};
    for(const auto &i : player.GetShip().GetCargo()) {
        arr.addBack(i.GetCargoName());
    }
    //we print in order of arr so we know op is the index of the cargo to be sold from the player ship
    int op = io.HandleOptions(arr);
    if(op < 0){
        return;
    }
    io.Print("How many: ");
    io.Print(_player_ship.GetCargo()[op].GetCargoName());
    io.PrintLine(" would you like to sell?");
    int amount = io.GetInt();
    int x = _player_ship.GetCargo()[op].DeductAmount(amount);
    while(x < 0) {
        io.Print("Invalid amount. You can only sell a max of: ");
        io.PrintLine(_player_ship.GetCargo()[op].GetAmount());
        amount = io.GetInt();
        x = _player_ship.GetCargo()[op].DeductAmount(amount);
    }
    _player_ship.DecreaseSpace(amount);
    //find what the port will buy the selected cargo for
    int f = _current_port.GetCargoInventory().find(_player_ship.GetCargo()[op]);
    //cargo wasn't found in the cargo inventory
    if(f < 0) {
        return;
    }
    //remove selected cargo from array if amount == 0
    if(x == 0) {
        player.GetShip().RemoveCargo(op);
    }
    //Notify player of his gold and what he just sold for.
    io.Print("Sold for: ");
    io.PrintLine(_current_port.GetCargoInventory()[f].GetCost() * amount);
    player.ReceiveGold(_current_port.GetCargoInventory()[f].GetCost() * amount);

    this->ShowGoldBalance();
}
//pick cargo you want to buy
//specify how much you want to buy, can't be more than what you can afford or what the shop has in stock
//check if you have enough ship space
//
void DockedState::BuyCargo() {
    _current_port.PrintCargo();
    nostd::Array<nostd::String> arr;
    for(const auto &i : _current_port.GetCargoInventory()) {
        arr.addBack(i.GetCargoName());
    }
    int op = io.HandleOptions(arr);
    if(op < 0) {
        return;
    }
    io.Print("How many: ");
    io.Print(_current_port.GetCargoInventory()[op].GetCargoName());
    io.PrintLine(" would you like to buy?");
    int amount = io.GetInt();
    //check if you can afford the specified cargo.cost * amount
    while((_current_port.GetCargoInventory()[op].GetCost() * amount) > player.GetGold()) {
        io.PrintLine("You can't afford this. Enter different amount or -1 to cancel");
        amount = io.GetInt();
        if(amount < 0) {
            return;
        }
    }
    //deduct the shop amount and check if you didn't go over.
    int x = _current_port.GetCargoInventory()[op].DeductAmount(amount);
    while(x == -1) {
        io.Print("Invalid amount. You can only buy a max of: ");
        io.PrintLine(_current_port.GetCargoInventory()[op].GetAmount());
        amount = io.GetInt();
        x = _current_port.GetCargoInventory()[op].DeductAmount(amount);
    }
    //check if you have enough space on your ship
    if(amount > _player_ship.CargoSpaceLeft()) {
        io.PrintLine("You don't have enough space left");
        return;
    }
    //increase space used on your ship
    _player_ship.IncreaseSpace(amount);
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
    io.PrintLine(_current_port.GetCargoInventory()[op].GetCost() * amount);
    player.LoseGold(_current_port.GetCargoInventory()[op].GetCost() * amount);
    this->ShowGoldBalance();
}

void::DockedState::SellCannons() {
    if(player.GetShip().GetCannons().size() < 1) {
        io.PrintLine("You don't have any cannons to sell.");
        return;
    }

    //get all cannon weights aboard
    nostd::Array<nostd::String> arr;
    for(const auto &i : player.GetShip().GetCannons()) {
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
    //port doesn't have the cannon
    if(f < 0){
        return;
    }

    _current_port.GetCannonInventory().at(f).DeductAmount(amount);

    //remove selected cargo from array if amount == 0
    if(x == 0) {
        player.GetShip().RemoveCannon(op);
    }

    //Notify player of his gold and what he just sold for.
    io.Print("Sold for: ");
    io.PrintLine(_current_port.GetCannonInventory()[f].GetCost() * amount);
    player.ReceiveGold(_current_port.GetCannonInventory()[f].GetCost() * amount);

    this->ShowGoldBalance();
}

void DockedState::BuyCannons() {
    _current_port.PrintCannons();
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

    while((_current_port.GetCannonInventory()[op].GetCost() * amount) > player.GetGold()) {
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
    io.PrintLine(_current_port.GetCannonInventory()[op].GetCost() * amount);
    player.LoseGold(_current_port.GetCannonInventory()[op].GetCost() * amount);

    this->ShowGoldBalance();
}

void DockedState::BuyShip() {
    _current_port.PrintShips();
    nostd::Array<nostd::String> arr;
    for(const auto &i : _current_port.GetShipInventory()) {
        arr.addBack(i.GetType());
    }

    int op = io.HandleOptions(arr);
    if(_current_port.GetShipInventory()[op].GetCost() - (_player_ship.GetCost() / 2) > player.GetGold()) {
        io.PrintLine("You can't afford this ship");
        return;
    }
    Ship temp_ship = _current_port.GetShipInventory()[op];
    temp_ship.SetCannons(_player_ship.GetCannons());
    temp_ship.SetCannonAmount(_player_ship.GetCannonAmount());
    temp_ship.SetCargo(_player_ship.GetCargo());
    temp_ship.SetSpace(_player_ship.GetSpace());
    _player_ship = temp_ship;
}

void DockedState::RepairShip() {
    if (_player_ship.GetCurrentHp() == _player_ship.GetMaxHp()) {
        io.PrintLine("Your ship is in perfect condition. You don't need to repair your ship.");
        return;
    }
    io.PrintLine("Repairing your ship will cost 1 gold per 10 health points.");
    ShowShipHealth();
    ShowGoldBalance();
    io.Print("How much gold would you like to spend to restore your ship?");
    io.Print(" (max: ");
    int maxRepair = (_player_ship.GetMaxHp() - _player_ship.GetCurrentHp()) / 10 +
                    ((_player_ship.GetMaxHp() - _player_ship.GetCurrentHp()) % 10 != 0);
    io.Print(maxRepair);
    io.PrintLine(")");
    int gold = io.GetInt();
    if (gold > player.GetGold()) {
        io.PrintLine("You can't afford these repairments. Choose for a cheaper repairment.");
        ShowGoldBalance();
        return;
    } else if (gold < 0 || gold > maxRepair) {
        io.Print("Invalid amount. You can only use a max of: ");
        io.Print(maxRepair);
        io.PrintLine(" gold.");
        return;
    }
    _player_ship.RestoreHp(gold * 10);
    player.LoseGold(gold);
    io.Print("Your ship has been repaired for ");
    io.Print(gold);
    io.PrintLine(" gold.");
    ShowShipHealth();
}
//pick city to sail to.
//find the nth token in the line starting with the current port name
//print turns and go to sailing state.
void DockedState::SailTo() {
    FileReader fr{"afstanden_tussen_steden.csv"};
    nostd::String* first_row {fr.GetSpecificLine(nostd::String{""})};
    nostd::Array<nostd::String> token_arr = first_row->Tokenize(';');
    //first token is empty string
    token_arr.removeN(0);
    int op = io.HandleOptions(token_arr);
    if(op < 0) {
        return;
    }
    nostd::String* city_row {fr.GetSpecificLine(_current_port.GetPortName())};
    nostd::Array<nostd::String> city_token_arr = city_row->Tokenize(';');
    nostd::String str = city_token_arr.at(op + 1);
    io.Print("Sailing to: ");
    io.PrintLine(token_arr[op]);
    io.Print("Turns: ");
    io.PrintLine(str);
    int turns = atoi(str.c_str());
    //set destination port string to retrieve object on arrival.
    player.SetDestinationPort(token_arr[op]);
    //switch to SailingState
    stateManager.PushState(new SailingState(player, stateManager, turns));
    //cleanup of heap ptrs returned by fr.GetSpecificLine()
    delete city_row;
    delete first_row;
}

void DockedState::ShowGoldBalance() {
    io.Print("Current gold: ");
    io.PrintLine(player.GetGold());
}

void DockedState::ShowShipHealth() {
    io.Print("Your ships health: ");
    io.Print(_player_ship.GetCurrentHp());
    io.Print("/");
    io.PrintLine(_player_ship.GetMaxHp());
}
