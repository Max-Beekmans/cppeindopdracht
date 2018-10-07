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
    private:
        //short-string optimization for array
        static const int short_max = 15;
        int length;
        T* ptr;
        // discriminated union (count <= short_max)
        union {
            // unused space;
            int space;
            // +1 for terminating char
            T ss[short_max + 1];
        };

        T* expand(const T* ptr, int n);
    };
}



#endif //EINDOPDRACHT_ARRAY_H
