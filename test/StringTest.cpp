//
// Created by MaxBe on 10/16/2018.
//
#include "catch2/catch.hpp"
#include "../src/nostd/String.h"

TEST_CASE("Compare two strings", "[single-file]") {
    nostd::String a("String One");
    nostd::String b("String One");
    REQUIRE(a == b);
}

TEST_CASE("Create string with char[] buffer", "[single-file]") {
    const char *buffer = "Blaze it fgt";
    nostd::String a(buffer);
    std::string b = std::string(a.c_str());
    REQUIRE(b == "Blaze it fgt");
}