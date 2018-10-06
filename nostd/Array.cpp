//
// Created by Max on 9/13/2018.
//

#include "Array.h"

namespace nostd {
    template <typename T>
    void Array<T>::AddElement(T element) {
        if (this->elements[length_] != nullptr) {
            this->ScaleArray();
        }
        this->elements[length_ + 1] = element;
        //this->elements_[length_ + 1];
        this->length_++;
    }

    template<typename T>
    T& Array<T>::GetElement(int index) {
        return this->elements_[index];
    }

    template<typename T>
    void Array<T>::ScaleArray() {
        //allocate more memory and copy current
    }
}


