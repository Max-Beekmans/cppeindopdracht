#include "SailingState.h"
#include "nostd/Random.h"

SailingState::SailingState(Player& player, StateManager& stateManager) : BaseState(player, stateManager) {
    _turns = CalculateTurns(_player.GetCurrentPort(), _player.GetDestinationPort());
}

void SailingState::Update() {
    nostd::Random r;
    while(_turns > 0) {
        switch(r.getRand(1, 20)) {
            case 1 ... 2:
                io.PrintLine("The ship didn't move.");
                break;
            case 3 ... 4:
                if (_player.GetShip().GetWeight() == 0) {
                    _turns--;
                    io.PrintLine("You sailed, you are now 1 turn closer to the target port.");
                } else {
                    io.PrintLine("The ship didn't move.");
                }
                break;
            case 5 ... 7:
                if (_player.GetShip().GetWeight() != 2) {
                    _turns--;
                    io.PrintLine("You sailed, you are now 1 turn closer to the target port.");
                } else {
                    io.PrintLine("The ship didn't move.");
                }
                break;
            case 8 ... 17:
                _turns--;
                io.PrintLine("You sailed, you are now 1 turn closer to the target port.");
                break;
            case 18 ... 19:
                _turns -= 2;
                io.PrintLine("There is alot of wind, you are now 2 turns closer to the target port.");
                break;
            case 20:
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
                _player.GetShip().ReceiveDamage(r.getRand(1, 100));
                if(_player.GetShip().GetCurrentHp() <= 0) {
                    io.PrintLine("Your ship has sunk, the game is over.");
                    //TODO: actually quit the game here
                }
                break;
        }
    }
    _player.ArriveOnDestination();
}

int SailingState::CalculateTurns(const Port& currentPort, const Port& destinationPort) {
    //TODO: implementation
    return 20;
}

SailingState::~SailingState() {

}

void SailingState::print_options() {

}
