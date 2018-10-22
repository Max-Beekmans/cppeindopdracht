#include <iostream>
#include "nostd/String.h"
#include "nostd/Array.h"
#include "nostd/Random.h"
#include "Dungeon.h"

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
    s += d;
    std::cout << s << std::endl;

    nostd::Random r;
    nostd::Array<int> random_array{5};
    const int min = 0;
    const int max = 10;

    int x = random_array.size();
    for (int i = 0; i < x; ++i) {
        int rand = r.getRand(min, max);
        random_array[i] = rand;
    }

    for (int j : random_array) {
        std::cout << j;
    }

    std::cout << std::endl;

    Dungeon dungeon = Dungeon(5, 5);
    dungeon.GenerateDungeon();
    dungeon.PrintDungeon();

//    char c1 = 'C';
//    char c2 = 'D';
//    nostd::Array<char> string_array;
//    string_array.AddElement(c1);
//    string_array.AddElement(c2);
    return 0;
}