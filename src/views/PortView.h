//
// Created by nomen on 24-10-19.
//

#ifndef EINDOPDRACHT_PORTVIEW_H
#define EINDOPDRACHT_PORTVIEW_H

#include "nostd/IOHandler.h"
#include "Port.h"
#include "Player.h"

namespace views {

    class PortView {
    public:
        GameController();

        ~GameController() = default;

        void StartGame();

    private:
        void PrintIntroduction();

        nostd::IOHandler io;
    };

}
#endif //EINDOPDRACHT_PORTVIEW_H
