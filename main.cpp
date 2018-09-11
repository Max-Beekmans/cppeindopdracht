#include <iostream>
#include "nostd/String.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    char string[] = "Hello World";
    for (int i = 0; i < 11; ++i) {
        std::cout << string[i];
    }
    char str[] = "Hello World";
    nostd::String s(str);
    std::cout << s;

    return 0;
}