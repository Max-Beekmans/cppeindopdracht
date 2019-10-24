//
// Created by MaxBe on 9/11/2018.
//
#include "String.h"
#include <iostream>

namespace nostd {

    int strlen(char *ptr) {
        int len = 0;
        char *p = ptr;
        while (*p != '\0') {
            len++;
            p++;
        }
        return len;
    }

    void strncpy(char *ptr_dest, char *ptr_src, int n) {
        for (int i = 0; i < n; i++)
            ptr_dest[i] = ptr_src[i];
    }

    String::String() : length(0), buff(NULL) {}

    String::String(char *init_val) : length(strlen(init_val)), buff(new char[length]) {
        strncpy(buff, init_val, length);
    }

    String::String(const String &other) : length(other.length), buff(new char[length]) {
        strncpy(buff, other.buff, length);
    }

    String::~String() {
        delete[] buff;
    }


    char *String::c_str() {
        return buff;
    }

    const char *String::c_str() const {
        return buff;
    }

    char &String::at(const int n) {
        check(n);
        return buff[n];
    }

    char String::at(int n) const {
        check(n);
        return buff[n];
    }

    const int String::Find(const char c) {
        char *pch = strchr(this->buff, c);
        if (pch == nullptr) {
            return -1;
        }
        int found = pch - this->buff;
        return found;
    }

    String *String::Split(const char delim) {
        const int index = this->Find(delim);
        if (index < 0) {
            return nullptr;
        }
        auto *res = new std::string[2];
        res[0] = std::string{};
        res[1] = std::string{};
        for (int i = 0; i <= index - 1; ++i) {
            res[0] += this->at(i);
        }

        for (int j = index + 1; j < this->size(); ++j) {
            res[1] += this->at(j);
        }

        return res;
    }

    Array<String> String::Split(std::string str, const char delim) {
        nostd::Array<std::string> array{};
        const int index = str.Find(delim);
        if (index < 0) {
            return array;
        }
        std::string before{};
        std::string after{};
        for (int i = 0; i <= index - 1; ++i) {
            before += str.at(i);
        }

        for (int j = index + 1; j < str.size(); ++j) {
            after += str.at(j);
        }
        array.addBack(before);
        array.addBack(after);
        return array;
    }

    Array<String> String::Tokenize(const char delim) {
        std::string *arr = this->Split(delim);
        nostd::Array<std::string> token_arr{};
        while (arr != nullptr) {
            token_arr.addBack(arr[0]);
            *this = arr[1];
            delete[] arr;
            arr = this->Split(delim);
        }

        delete[] arr;
        return token_arr;
    };

    int String::size() { return length; }

    void String::check(int n) const {
        if (n < 0 || length <= n)
            throw std::out_of_range("String::at()");
    }

    String &String::operator+=(char c) {
        String res;
        res.length = length + 1;
        res.buff = new char[res.length];
        strncpy(res.buff, buff, length);
        res.buff[length] = c;
        res.buff[res.length] = ' \0';

    }

    String &String::operator=(const String &other) {
        if (this != &other) {          // guard against  a = a;
            delete[] buff;              // release old memory & then
            length = other.length;       // allocate new memory
            buff = new char[length];
            strncpy(buff, other.buff, length);
        }
        return *this;                  // return a reference to itself
    }                                // to allow a = b = c;

    String operator+(const String &s1, const String &s2) {
        String res;
        res.length = s1.length + s2.length;
        res.buff = new char[res.length];
        strncpy(res.buff, s1.buff, s1.length);
        strncpy(res.buff + s1.length,            // pointer arithmetic!
                s2.buff,
                s2.length);
        return res;
    }

    std::ostream &operator<<(std::ostream &os, const String &s) {
        // print char after char from buff
        for (int i = 0; i < s.length; i++) os.put(s.buff[i]);
        return os;         // this is to allow multiple <<, as in  cout << a << b;

    }
}
