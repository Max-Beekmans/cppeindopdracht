//
// Created by Max on 9/13/2018.
//

#include "Array.h"

namespace nostd {
    template<typename T>
    T* Array<T>::expand(const T* ptr, int n) {
        T* temp = new T[n];
        memcpy(temp, ptr);
        return temp;
    }
}


