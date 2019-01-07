#include <iostream>

#include "nostd/String.h"
#include "nostd/Array.h"
#include "nostd/Random.h"
#include "nostd/Range.h"
#include "Ship.h"
#include "nostd/IOHandler.h"
#include "FileReader.h"

int main() {
    Ship ship(nostd::String{"Hallo"}, 200, 400, 9001, 2, 0, 0);
    nostd::Range range{1, 3};
    int x = range.GetRandom();
    std::cout << x << std::endl;
    nostd::IOHandler io {};
    io.PrintLine("I like trains");
    nostd::String input = io.GetString();
    io.PrintLine(input);
    FileReader fr{};
    nostd::String s = fr.GetLine();
    io.PrintLine(s);
    return 0;
}