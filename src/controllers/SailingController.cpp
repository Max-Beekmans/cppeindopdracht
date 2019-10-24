#include "nostd/Random.h"
#include "controllers/SailingController.h"

SailingController::SailingController(Player& player, GameController& game) {}

bool SailingController::Sail(const int turns) {
    nostd::Random r;

    int _turns = turns;

    while(_turns > 0) {
        if(r.getRand(1, 100) <= 20) {
            stateManager.PushState(new FightingState(player, stateManager));
            return true;
        }

        switch(r.getRand(1, 20)) {
            case 1 ... 2:
                io.Print("[None] ");
                io.PrintLine("There is no wind. The ship didn't move.");
                break;
            case 3 ... 4:
                io.Print("[Breeze] ");
                if (player.GetShip().GetWeight() == 0) {
                    _turns--;
                    io.PrintLine("You sailed, you are now 1 turn closer to the target port.");
                } else {
                    io.PrintLine("The ship didn't move.");
                }
                break;
            case 5 ... 7:
                io.Print("[Weak] ");
                if (player.GetShip().GetWeight() != 2) {
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

                int damage = percentage * player.GetShip().GetMaxHp() / 100;

                player.GetShip().ReceiveDamage(damage);
                io.Print("The storm has damaged your ship and you received ");
                io.Print(damage);
                io.PrintLine(" damage.");
                io.Print("You have ");
                io.Print(player.GetShip().GetCurrentHp());
                io.PrintLine(" health points left.");
                if(player.GetShip().GetCurrentHp() <= 0) {
                    io.PrintLine("Your ship has sunk, the game is over.");
                    _turns = 0;
                    return false;
                }
                break;
        }
    }
    stateManager.PushAndReplace(new DockedState(player, stateManager));
    return true;
}
