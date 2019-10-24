//
// Created by MaxBe on 09-Jan-19.
//

#ifndef EINDOPDRACHT_PORTBUILDER_H
#define EINDOPDRACHT_PORTBUILDER_H

#include "Factory.h"
#include "../models/Port.h"

namespace factories {
    class PortFactory : public Factory {
    public:
        //Create port based on port_name.
        //Will look for this name to be in the first column of the file.
        models::Port CreatePort(std::string port_name);
    };
}

#endif //EINDOPDRACHT_PORTBUILDER_H
