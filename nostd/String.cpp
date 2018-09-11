//
// Created by MaxBe on 9/11/2018.
//

#include <cstring>
#include "String.h"

namespace nostd {
    String::String(char* val) : val(val) {}
    String::String(const String &str) : val(str.val) {}

    std::ostream &operator<<(std::ostream &os, String &string) {
        os << string.getValue();
        return os;
    }

    String &String::operator=(String &string) {
        this->val = string.getValue();
        return *this;
    }

    String& String::operator+(nostd::String &string) {
        int total_length = this->getLength() + string.getLength();
        char newstr[total_length];
        //TODO make into heap mem
        strcpy(newstr, this->val);
        strcat(newstr, string.getValue());
        this->setValue(newstr);
        return *this;
    }

    int String::operator==(String &string) {
        if(strcmp(string.getValue(), this->getValue()) == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    char *String::getValue() const {
        return this->val;
    }

    const int String::getLength() const{
        int count = 0;
        char * value = this->val;
        while(value[count] != '\0') {
            count++;
        }
        return count;
    }

    void String::setValue(char *val) {
        this->val = val;
    }
}
