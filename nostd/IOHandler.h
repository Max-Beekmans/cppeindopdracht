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

        int HandleOptions(const nostd::Array<nostd::String>& options) {
            //left to print
            auto op = static_cast<size_t>(options.size());
            //index left off
            size_t in = 0;

            while(in != op) {
                if(op > 10) {
                    this->PrintN(10, in, options);
                    op -= 10;
                    in += 10;
                    int x = GetInt();
                    if(x <= 10) {
                        //user selects number between 1 and 10
                        //the index is actually -1
                        return x - 1;
                    }
                } else {
                    this->PrintN(op, in, options);
                    int x = GetInt();
                    if(x <= op) {
                        return static_cast<int>((x + in) - 1);
                    } else {
                        op = static_cast<size_t>(options.size());
                        in = 0;
                    }
                }
            }
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
    private:
        void PrintN(const size_t n, const size_t start, const nostd::Array<nostd::String>& options) {
            for (size_t i = start; i < start + n; ++i) {
                std::cout << '[' << (i - start) + 1 << ']' << options[i] << std::endl;
            }
        }
    };
}
#endif //PLANET_EXPRESS_IOHANDLER_H
