//
// Created by MaxBe on 9/11/2018.
//
#ifndef EINDOPDRACHT_STRING_H
#define EINDOPDRACHT_STRING_H

#include <ostream>
#include "Array.h"

namespace nostd {
    //Think of this class as merely a wrapper for the annoying char literal or char* stuff
    //Char* wrapping pointer semantics and providing short string optimization
    class String {
    public:
        //Construct ro5
        //default constructor
        String() noexcept;
        //constructor for c-style strings
        explicit String(const char* val);
        //copy
        String(const String&);
        String& operator=(const String& copy);
        //move
        String(String&&) noexcept;
        String& operator=(String&& move) noexcept;
        //destructor
        ~String();

        //Operators
        //unchecked element access
        char& operator[](int n) { return ptr[n]; }
        char operator[](int n) const { return ptr[n]; }
        //ostream
        friend std::ostream &operator<<(std::ostream &os, String &string);
        friend std::ostream &operator<<(std::ostream &os, const String &string);
        //add another string and return new
        //String& operator+(String& add);
        //add char to the end of the string
        String& operator+=(char c);

        //Methods
        int size() const;
        int capacity() const;
        bool isEmpty() const;
        char* c_str();
        const char* c_str() const;
        char& at(const int n);
        char at(int n) const;
        //find character and return it's index.
        //If the character can't be found returns -1
        const int Find(const char c);
        nostd::String* Split(const char delim);
        nostd::Array<nostd::String> Split(nostd::String str, const char delim);
        nostd::Array<nostd::String> Tokenize(const char delim);
    private:
        static const int short_max = 15;
        int count;
        char* ptr;
        // discriminated union (count <= short_max)
        union {
            // unused space;
            int space;
            // +1 for terminating char
            char ss[short_max + 1];
        };

        void check(int n) const;
        static char* expand(const char* ptr, int n);
        void copy_from(const String& copy);
        void move_from(String& move);
    };
    //nonmember functions
    char* begin(String& x);
    char* end(String& x);
    const char* begin(const String& x);
    const char* end(const String& x);
    String& operator+=(String& a, const String& b);
    String operator+(const String& a, const String& b);
    bool operator==(const String& a, const String& b);
    bool operator!=(const String& a, const String& b);
    String operator""_s(const char* p, size_t);
}



#endif //EINDOPDRACHT_STRING_H
