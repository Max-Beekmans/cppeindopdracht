//
// Created by MaxBe on 9/11/2018.
//

#include <cstring>
#include "String.h"

namespace nostd {

    String::String() : count(0), ptr(ss) {
        ss[0] = '\0';
        space = 0;
    }

    String::~String() {
        if (short_max < count) {
            delete[] ptr;
        }
    }

    String::String(const char* val)
            :count{static_cast<int>(strlen(val))},
             ptr{(count <= short_max) ? ss : new char[count + 1]},
             space{0} {
        strcpy(ptr, val);
    }

    String::String(const String& copy) {
        copy_from(copy);
    }

    String::String(String&& move) noexcept {
        move_from(move);
    }

    //operator overloading methods
    std::ostream &operator<<(std::ostream &os, String &string) {
        return os << string.c_str();
    }

    String& String::operator=(const String& copy) {
        if (this == &copy) return *this;
        char* p = (short_max < count) ? ptr : 0;
        copy_from(copy);
        delete[] p;
        return *this;
    }

    String& String::operator=(String&& move) noexcept{
        if (this == &move) return *this;
        //only release memory when there is any
        if (short_max < count) delete [] ptr;
        move_from(move);
        return *this;
    }

    String& String::operator+=(char c) {
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
        ptr[count] = c;
        ptr[++count] = 0;
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

    char* String::expand(const char *ptr, int n) {
        char* p = new char[n];
        strcpy(p, ptr);
        return p;
    }

    void String::copy_from(const String& copy) {
        if (copy.count <= short_max) {
            memcpy(this, &copy, sizeof(copy));
            ptr = ss;
        } else {
            ptr = this->expand(copy.ptr, copy.count + 1);
            count = copy.count;
            space = 0;
        }
    }

    void String::move_from(String &move) {
        if (move.count <= short_max) {
            memcpy(this, &move, sizeof(move));
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

    String operator""_s(const char* p, size_t) {
        return String{p};
    }
}
