//
// Created by MaxBe on 9/11/2018.
//
#ifndef EINDOPDRACHT_STRING_H
#define EINDOPDRACHT_STRING_H

#include <ostream>
#include "Array.h"

// Helper functions:
//
// my_strlen : count the length of a string until a null char
//
// my_strncpy : copy n chars from source to destination
namespace nostd {



    class String {
        int length;
        char *buff;
    private:
        void check(int n) const;
    public:
        String();
        String(char *init_val);
        String(const String &other);
        ~String();

        char* c_str();

        const char* c_str() const;

        char& at(const int n);

        char at(int n) const;

        const int Find(const char c);

        String* Split(const char delim);

        Array<String> Split(std::string str, const char delim);

        Array<String> Tokenize(const char delim);

        int size();

        // operator= returns  myString&  to allow multiple assignments
        String& operator+=(char c);

        String &operator=(const String &other);

        friend String operator+(const String &s1, const String &s2);

        friend String operator+(const String &s, char c);

        friend String operator+(char c, const String &s);

        friend std::ostream &operator<<(std::ostream &, const String &);

        char &operator[](int index) {
            if (index < 0 || index > length) {
                exit(-1);
            }
            return buff[index];
        }
    };

    bool operator==(const String& a, const String& b);

    String operator+(const String &s1, const String &s2);

    String& operator +=(const String &s1, const String &s2);

    std::ostream &operator<<(std::ostream &os, const String &s);
}
#endif //EINDOPDRACHT_STRING_H
