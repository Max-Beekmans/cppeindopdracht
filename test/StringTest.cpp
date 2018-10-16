//
// Created by MaxBe on 10/16/2018.
//

#include "catch2/catch.hpp"
#include "../nostd/String.h"

TEST_CASE("Compare two strings", "[single-file]") {
    nostd::String a("String One");
    nostd::String b("String One");
    REQUIRE(a == b);
}