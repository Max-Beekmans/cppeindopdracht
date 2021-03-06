//
// Created by MaxBe on 9/11/2018.
//
#include "String.h"
#include <cstring>
#include <iostream>

namespace nostd {

    String::String() noexcept : count{0}, ptr{ss} { ss[0] = '\0'; }

    String::String(const char* val):
        count{static_cast<int>(strlen(val))},
        ptr{ss},
        space{0} {
        //scuffed replacement for strlen() since it kept erroring
        //performance wise it's equally fast.
        this->count = 0;
        while (val[this->count] != '\0') this->count++;
        this->ptr = (count <= short_max) ? ss : new char[this->count + 1];
        strcpy(this->ptr, val);
    }

    String::String(const String& copy) {
        copy_from(copy);
    }

    String& String::operator=(const String& copy) {
        if (this == &copy) return *this;
        char* p = (short_max < count) ? ptr : nullptr;
        copy_from(copy);
        delete[] p;
        return *this;
    }

    String::String(String&& move) noexcept {
        move_from(move);
    }

    String& String::operator=(String&& move) noexcept{
        if (this == &move) return *this;
        //only release memory when there is any
        if (short_max < count) delete [] ptr;
        move_from(move);
        return *this;
    }

    String::~String() {
        if (short_max < count) {
            delete[] ptr;
        }
    }

    //operator overloading methods
    std::ostream &operator<<(std::ostream &os, String &string) {
        return os << string.c_str();
    }

    std::ostream& operator<<(std::ostream& os, const String& string) {
        return os << string.c_str();
    }

    String& String::operator+=(char c) {
        if(ptr == nullptr) ptr = ss;
        if (count == short_max) {
            //double the alloc (+2 for terminating 0)
            int n = count + count + 2;
            ptr = expand(ptr, n);
            //assert space left
            space = n - count - 2;
        } else if (short_max < count) {
            //there is no more space
            if (space == 0) {
                //double the alloc (+2 for terminating 0)
                int n = count + count + 2;
                char* p = expand(ptr, n);
                delete[] ptr;
                ptr = p;
                space = n - count - 2;
            } else {
                //there is still space
                --space;
            }
        }
        this->ptr[count] = c;
        this->ptr[++count] = 0;
        return *this;
    }

    //public methods
    int String::size() const {
        return count;
    };

    int String::capacity() const {
        if (count <= short_max) {
            return count;
        }
        return count + space;
    }

    char *String::c_str() {
        return ptr;
    }

    const char *String::c_str() const {
        return ptr;
    }

    char &String::at(const int n) {
        check(n);
        return ptr[n];
    }

    char String::at(int n) const {
        check(n);
        return ptr[n];
    }

    //private methods
    void String::check(int n) const {
        if (n < 0 || count <= n)
            throw std::out_of_range("String::at()");
    }

    char* String::expand(const char* p, int n) {
        char* temp = new char[n];
        strcpy(temp, p);
        return temp;
    }

    void String::copy_from(const String& copy) {
        if (copy.count <= short_max) {
            memcpy(this, &copy, sizeof(copy));
            ptr = ss;
        } else {
            ptr = expand(copy.ptr, copy.count + 1);
            count = copy.count;
            space = 0;
        }
    }

    void String::move_from(String &move) {
        if (move.count <= short_max) {
            memcpy(this, &move, sizeof(move));
            count = move.count;
            ptr = ss;
        } else {
            ptr = move.ptr;
            count = move.count;
            space = move.space;
            move.ptr = move.ss;
            move.ss[0] = 0;
            move.count = 0;
        }
    }

    const int String::Find(const char c) {
        char* pch = strchr(this->ptr, c);
        if(pch == nullptr) {
            return -1;
        }
        int found = pch-this->ptr;
        return found;
    }

    //return value is heap memory that needs to be cleaned up outside of this class!
    //returns nullptr if delim can't be found
    nostd::String* String::Split(const char delim) {
        const int index = this->Find(delim);
        if (index < 0) {
            return nullptr;
        }
        auto* res = new nostd::String[2];
        res[0] = nostd::String{};
        res[1] = nostd::String{};
        for (int i = 0; i <= index - 1; ++i) {
            res[0] += this->at(i);
        }

        for (int j = index + 1; j < this->size(); ++j) {
            res[1] += this->at(j);
        }

        return res;
    }

    nostd::Array<nostd::String> String::Split(nostd::String str, const char delim) {
        nostd::Array<nostd::String> array{};
        const int index = str.Find(delim);
        if (index < 0) {
            return array;
        }
        nostd::String before{};
        nostd::String after{};
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

    //can't call this function on a const string cause:
    //a. function is not const
    //b. assigning new value to the *this ptr
    nostd::Array<nostd::String> String::Tokenize(const char delim) {
        nostd::String* arr = this->Split(delim);
        nostd::Array<nostd::String> token_arr{};
        while(arr != nullptr) {
            token_arr.addBack(arr[0]);
            *this = arr[1];
            delete[] arr;
            arr = this->Split(delim);
        }

        delete[] arr;
        return token_arr;
    }

    bool String::isEmpty() const {
        return size() <= 0;
    }

    //helper nonmember functions
    char* begin(String& x) {
        return x.c_str();
    }

    char* end(String& x) {
        return x.c_str() + x.size();
    }

    const char* begin(const String& x) {
        return x.c_str();
    }

    const char* end(const String& x) {
        return x.c_str() + x.size();
    }

    String& operator+=(String& a, const String& b) {
        for (auto x : b) {
            a += x;
        }
        return a;
    }

    String operator+(const String& a, const String& b) {
        nostd::String res {a};
        res += b;
        return res;
    }

    bool operator==(const String& a, const String& b) {
        if (a.size() != b.size()) {
            return false;
        }
        for (int i = 0; i != a.size(); ++i) {
            if(a[i] != b[i])
                return false;
        }
        return true;
    }

    bool operator!=(const String& a, const String& b) {
        return !(a==b);
    }

    //string is trivial
    String operator"" _s(const char* p, size_t) {
        return String{p};
    }
}
