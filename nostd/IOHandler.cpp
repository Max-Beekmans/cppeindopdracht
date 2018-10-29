#include "IOHandler.h"

namespace nostd {

    String IOHandler::GetString() {
        char str[64];
        std::cin >> str;
        String mstr = {str};
        return mstr;
    }

    int IOHandler::GetInt() {
        int x = 0;
        std::cin >> x;
        return x;
    }


    void IOHandler::ClearConsole() {
        for (int i = 0; i < 10; ++i) {
            std::cout << '\n';
        }
        std::cout << std::endl;
    }

    void IOHandler::PrintDivider() {
        std::cout << std::endl << "_____________________________________________" << std::endl;
    }

}