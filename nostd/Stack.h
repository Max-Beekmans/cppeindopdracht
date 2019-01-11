#ifndef EINDOPDRACHT_STACK_H
#define EINDOPDRACHT_STACK_H

#include <iostream>

#define MAX 10

namespace nostd {

    template <typename T>
    class Stack {
    public:
        Stack() {
            top = -1;
        }

        void Push(T obj) {
            if(top == MAX-1) {
                return;
            }
            top++;
            arr[top] = obj;
        }

        T Pop() {
            if(top == -1) {
                return NULL;
            }

            T obj = arr[top];
            top--;

            return obj;
        }

        T Top() {
            return arr[top];
        }

        bool IsEmpty() const {
            return top < 0;
        }

    private:
        T arr[MAX];
        int top;
    };
} //nostd

#endif //EINDOPDRACHT_STACK_H
