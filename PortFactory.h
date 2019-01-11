//
// Created by MaxBe on 09-Jan-19.
//

#ifndef EINDOPDRACHT_PORTBUILDER_H
#define EINDOPDRACHT_PORTBUILDER_H

#include "Port.h"
#include "FileReader.h"

//Parses
class PortFactory {
public:
    //Create port based on port_name.
    //Will look for this name to be in the first column of the file.
    //TODO throw exception or return ptr for error handling
    Port* CreatePort(nostd::String port_name);
private:
    FileReader _fr;
};


#endif //EINDOPDRACHT_PORTBUILDER_H