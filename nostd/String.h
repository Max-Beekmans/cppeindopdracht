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
        String();
        String(const char* val);
        String(const String &str);

        String(String&& move);

        ~String() {
            if (short_max < count) {
                delete[] ptr;
            }
        }

        //Operators
        //unchecked element access
        char& operator[](int n) { return ptr[n]; }
        char operator[](int n) const { return ptr[n]; }
        //ostream
        friend std::ostream &operator<<(std::ostream &os, String &string);
        //copy
        String& operator=(const String& copy);
        //move
        String& operator=(String&& move) noexcept;
        //add another string and return new
        //String& operator+(String& add);
        //add char to the end of the string
        String& operator+=(char c);
        int operator==(String& compare);

        //Methods
        char* c_str();
        const char* c_str() const;
        char& at(const int n);
        char at(int n) const;

    private:
        static const int short_max = 15;
        size_t count;
        char* ptr;
        // discriminated union (count <= short_max)
        union {
            // unused space;
            int space;
            // +1 for terminating char
            char ss[short_max + 1];
        };

        void check(int n) const;
        char* expand(const char* ptr, size_t n);
        void copy_from(const String& copy);
        void move_from(String& move);
    };
}



#endif //EINDOPDRACHT_STRING_H
