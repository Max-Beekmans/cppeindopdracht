//
// Created by MaxBe on 9/11/2018.
//

#ifndef EINDOPDRACHT_STRING_H
#define EINDOPDRACHT_STRING_H

#include <ostream>

namespace nostd {
    //Think of this class as merely a wrapper for the annoying char literal or char* stuff
    //The pointer you pass is rai to String so will clean it up when you clean String up.
    class String {
    public:
        //Construct
        // Yes it is immutable cause we want to edit and also don't want char literals
        String(char* val);
        String(const String &str);

        //Operators
        friend std::ostream &operator<<(std::ostream &os, String &string);
        // Assign string to left hand string.
        String &operator=(String &string);
        // Adds 2nd string to left hand string.
        String &operator+(String &string);
        // Executes cstring function strcmp on val returns 1 or 0
        int operator==(String &string);

        //Methods
        char* getValue() const;
        const int getLength() const;
        void setValue(char* val);

    private:
        char* val;
    };
}



#endif //EINDOPDRACHT_STRING_H
