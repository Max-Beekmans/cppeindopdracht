#include <iostream>

#include "nostd/String.h"
#include "nostd/Array.h"
#include "nostd/Random.h"
#include "nostd/IOHandler.h"

int main() {
    nostd::IOHandler io {};
    io.Print("I like trains");
    nostd::String input = io.GetString();
    io.Print(input);
    return 0;
}