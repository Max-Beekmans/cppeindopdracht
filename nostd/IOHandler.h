#ifndef PLANET_EXPRESS_IOHANDLER_H
#define PLANET_EXPRESS_IOHANDLER_H

#include <iostream>
#include "String.h"

namespace nostd {
    class IOHandler {
    public:
//        template<class T>
////        friend std::ostream &operator<<(std::ostream &os, T &obj) {
////            return os << obj;
////        }
//
//        template<class T>
//        friend std::ostream &operator<<(std::ostream &os, const T &obj) {
//            return os << obj;
//        }

        template<class T>
        void Print(T obj) {
            std::cout << obj;
        }

        template<class T>
        void PrintLine(T obj) {
            std::cout << obj << std::endl;
        }

        nostd::String GetString() {
            char str[512];
            std::cin.getline(str, sizeof(str));
            return nostd::String {str};
        }

        int GetInt() {
            int x = 0;
            std::cin >> x;
            return x;
        }

        //not really but just whitespace
        void ClearConsole() {
            for (int i = 0; i < 10; ++i) {
                std::cout << '\n';
            }
            std::cout << std::endl;
        }

        void PrintDivider() {
            std::cout << "_____________________________________________" << std::endl;
        }
    };
}
#endif //PLANET_EXPRESS_IOHANDLER_H
