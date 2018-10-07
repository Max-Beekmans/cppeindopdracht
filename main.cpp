#include <iostream>
#include "nostd/String.h"
#include "nostd/Array.h"

int main() {
    nostd::String s("Hello World");
    std::cout << s << std::endl;

    //= support
    nostd::String d = s;
    //<< support
    std::cout << d << std::endl;
    //[] support
    std::cout << d[6] << std::endl;
    //+= support
    s + d;
    std::cout << s << std::endl;

//    char c1 = 'C';
//    char c2 = 'D';
//    nostd::Array<char> string_array;
//    string_array.AddElement(c1);
//    string_array.AddElement(c2);
    return 0;
}