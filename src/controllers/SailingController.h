//
// Created by nomen on 24-10-19.
//

#ifndef EINDOPDRACHT_SAILINGCONTROLLER_H
#define EINDOPDRACHT_SAILINGCONTROLLER_H

#include "nostd/IOHandler.h"
#include "Player.h"
#include "GameController.h"

namespace controllers {

    class SailingController {
    public:
        SailingController(GameController& game);

        ~SailingController() = default;

        void Sail(const int turns);

}
#endif //EINDOPDRACHT_SAILINGCONTROLLER_H
