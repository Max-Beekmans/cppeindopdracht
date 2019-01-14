#include "SailingState.h"
#include "FightingState.h"
#include "nostd/Random.h"

SailingState::SailingState(Player& player, StateManager& stateManager, const int turns) : BaseState(player, stateManager), _turns(turns) {
    //_turns = CalculateTurns(_player.GetCurrentPort(), _player.GetDestinationPort());
}

bool SailingState::Update() {
    nostd::Random r;

    while(_turns > 0) {
        if(r.getRand(1, 100) <= 20) {
            _stateManager.PushState(new FightingState(_player, _stateManager));
            return true;
        }

        switch(r.getRand(1, 20)) {
            case 1 ... 2:
                io.Print("[None] ");
                io.PrintLine("There is no wind. The ship didn't move.");
                break;
            case 3 ... 4:
                io.Print("[Breeze] ");
                if (_player.GetShip().GetWeight() == 0) {
                    _turns--;
                    io.PrintLine("You sailed, you are now 1 turn closer to the target port.");
                } else {
                    io.PrintLine("The ship didn't move.");
                }
                break;
            case 5 ... 7:
                io.Print("[Weak] ");
                if (_player.GetShip().GetWeight() != 2) {
                    _turns--;
                    io.PrintLine("You sailed, you are now 1 turn closer to the target port.");
                } else {
                    io.PrintLine("The ship didn't move.");
                }
                break;
            case 8 ... 17:
                io.Print("[Normal] ");
                _turns--;
                io.PrintLine("You sailed, you are now 1 turn closer to the target port.");
                break;
            case 18 ... 19:
                io.Print("[Strong] ");
                _turns -= 2;
                io.PrintLine("There is a lot of wind, you are now 2 turns closer to the target port.");
                break;
            case 20:
                io.Print("[Storm] ");
                int rand = r.getRand(0, 100);
                if(rand <= 40) {
                    _turns++;
                    io.PrintLine("You have been blown of course, it takes 1 turn more to get to your destination.");
                } else if(rand > 40 && rand <= 80) {
                    io.PrintLine("The ship didn't move.");
                } else {
                    _turns--;
                    io.PrintLine("You sailed, you are now 1 turn closer to the target port.");
                }
                int percentage = r.getRand(1, 100);

                int damage = percentage * _player.GetShip().GetMaxHp() / 100;

                _player.GetShip().ReceiveDamage(damage);
                io.Print("The storm has damaged your ship and you received ");
                io.Print(damage);
                io.PrintLine(" damage.");
                io.Print("You have ");
                io.Print(_player.GetShip().GetCurrentHp());
                io.PrintLine(" health points left.");
                if(_player.GetShip().GetCurrentHp() <= 0) {
                    io.PrintLine("Your ship has sunk, the game is over.");
                    _turns = 0;
                    //TODO: actually quit the game here
                    return false;
                }
                break;
        }
    }
    //_statemanager.PushandReplace(new DockingState(_player, _statemanager));
    return true;
}

SailingState::~SailingState() {

}
