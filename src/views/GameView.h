//
// Created by nomen on 24-10-19.
//

#ifndef EINDOPDRACHT_DOCKVIEW_H
#define EINDOPDRACHT_DOCKVIEW_H

#include "nostd/IOHandler.h"

namespace views {

    class GameView {
    public:
        ~GameView() = default;
    private:
        void PrintIntroduction();
        nostd::IOHandler io;
    };

}
#endif //EINDOPDRACHT_DOCKVIEW_H
