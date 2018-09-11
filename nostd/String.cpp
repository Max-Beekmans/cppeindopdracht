//
// Created by MaxBe on 9/11/2018.
//

#include "String.h"

namespace nostd {
    String::String(char* val) : val(val) {}

    std::ostream &operator<<(std::ostream &os, const String &string) {
        return os << string.val;
    }
}
