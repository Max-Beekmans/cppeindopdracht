//
// Created by Max on 9/13/2018.
//

#ifndef EINDOPDRACHT_ARRAY_H
#define EINDOPDRACHT_ARRAY_H

#include <cstdlib>

namespace nostd {
    template <typename T>
    class Array {
    public:
        void AddElement(T element);
        T& GetElement(const int index);
    private:
        //Scales the array up by 10 more ellements
        void ScaleArray();
        int length_ = 0;
        //start to allocate 10 elements of T
        //whenever length reaches 10 folds execute ScaleArray to scale up 10 more
        T* elements_ = (T) malloc(10 * sizeof(T));
        T elements[10];
    };
}



#endif //EINDOPDRACHT_ARRAY_H
