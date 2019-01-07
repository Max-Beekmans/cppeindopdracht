#include <iostream>

#include "nostd/String.h"
#include "nostd/Array.h"
#include "nostd/Random.h"
#include "nostd/IOHandler.h"
#include "FileReader.h"

int main() {
    nostd::IOHandler io {};
    io.PrintLine("I like trains");
    nostd::String input = io.GetString();
    io.PrintLine(input);
    FileReader fr{};
    nostd::String s = fr.GetLine();
    io.PrintLine(s);
    return 0;
}