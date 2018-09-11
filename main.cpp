#include <iostream>
#include "nostd/String.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    char string[] = "Hello World";
    for (int i = 0; i < 11; ++i) {
        std::cout << string[i];
    }
    char str[] = "Hello World";
    char str2[] = "Hello World!";
    nostd::String s(str);
    nostd::String s2(str2);
    std::cout << s << std::endl;

    nostd::String c(s);
    nostd::String d = str2;

    std::cout << c << std::endl;
    std::cout << d << std::endl;

    std::cout << c.getLength() << std::endl;

    s = c + d;

    std::cout << s << std::endl;

    if(c == d) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}