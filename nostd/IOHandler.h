#ifndef PLANET_EXPRESS_IOHANDLER_H
#define PLANET_EXPRESS_IOHANDLER_H

#include <iostream>
#include "String.h"

namespace nostd {
    class IOHandler {
    public:
        template<class T>
        void Print(T obj);

        template<class T>
        void PrintLine(T obj);

        String GetString();

        int GetInt();

        //not really but just whitespace
        void ClearConsole();

        void PrintDivider();
    };

    template<class T>
    void IOHandler::Print(T obj) {
        std::cout << obj;
    }

    template<class T>
    void IOHandler::PrintLine(T obj) {
        std::cout << obj << std::endl;
    }
}
#endif //PLANET_EXPRESS_IOHANDLER_H
