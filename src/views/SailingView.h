//
// Created by nomen on 24-10-19.
//

#ifndef EINDOPDRACHT_SAILINGVIEW_H
#define EINDOPDRACHT_SAILINGVIEW_H

#include "nostd/IOHandler.h"
#include "Player.h"

namespace views{

    class SailingView {
    public:
        GameController();

        ~GameController() = default;

        void StartGame();

    private:
        void PrintIntroduction();

        nostd::IOHandler io;
    };

}
#endif //EINDOPDRACHT_SAILINGVIEW_H
