#ifndef PLANET_EXPRESS_IOHANDLER_H
#define PLANET_EXPRESS_IOHANDLER_H

#include <iostream>
#include "String.h"
#include "Array.h"

namespace nostd {
    class IOHandler {
    public:
        template<class T>
        void Print(const T obj) {
            std::cout << obj;
        }

        template<class T>
        void PrintLine(const T obj) {
            std::cout << obj << std::endl;
        }

        const std::string GetString() const {
            char str[512];
            std::cin.getline(str, sizeof(str));
            return std::string {str};
        }

        const int GetInt() const {
            int x = 0;
            std::cin >> x;
            return x;
        }

        const int HandleOptions(const nostd::Array<std::string>& options) {
            PrintLine("Enter number for option or 11 for more options");
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
            return -1;
        }

        //not really but just whitespace
        void ClearConsole() const {
            for (int i = 0; i < 10; ++i) {
                std::cout << '\n';
            }
            std::cout << std::endl;
        }

        void PrintDivider() const {
            std::cout << "_____________________________________________" << std::endl;
        }
    private:
        void PrintN(const size_t n, const size_t start, const nostd::Array<std::string>& options) const {
            for (size_t i = start; i < start + n; ++i) {
                std::cout << '[' << (i - start) + 1 << ']' << options[i] << std::endl;
            }
        }
    };
}
#endif //PLANET_EXPRESS_IOHANDLER_H
