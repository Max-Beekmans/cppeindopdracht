#include <iostream>

#include "nostd/String.h"
#include "nostd/Array.h"
#include "nostd/Random.h"
#include "nostd/Range.h"
#include "Ship.h"

int main() {
    Ship ship(nostd::String{"Hallo"}, 200, 400, 9001, 2, 0, 0);
    nostd::Range range{1, 3};
    int x = range.GetRandom();
    std::cout << x << std::endl;
    return 0;
}