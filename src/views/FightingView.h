//
// Created by nomen on 24-10-19.
//

#ifndef EINDOPDRACHT_DOCKVIEW_H
#define EINDOPDRACHT_DOCKVIEW_H

#include "../nostd/IOHandler.h"
#include "../models/Port.h"

namespace views {

    class FightingView {
    public:
        FightingView();

        ~FightingView() = default;


    private:
        nostd::IOHandler io;
    };

}
#endif //EINDOPDRACHT_FIGHTINGVIEW_H
