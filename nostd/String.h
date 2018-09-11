//
// Created by MaxBe on 9/11/2018.
//

#ifndef EINDOPDRACHT_STRING_H
#define EINDOPDRACHT_STRING_H

#include <ostream>

namespace nostd {
    class String {
    public:
        //Construct
        // Yes it is immutable cause we want to edit and also don't want char literals
        String(char* val);

        //Operators
        friend std::ostream &operator<<(std::ostream &os, const String &string);
    private:
        char* val;
    };
}



#endif //EINDOPDRACHT_STRING_H
