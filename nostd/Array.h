//
// Created by Max on 9/13/2018.
//

#ifndef EINDOPDRACHT_ARRAY_H
#define EINDOPDRACHT_ARRAY_H

#include <stdexcept>
#include <cstring>
#include <iostream>

namespace nostd {
    //Generic array object using pointer semantics and providing short string optimization
    //Header only cause templatized classes cause some nasty linker errors when
    //implementatation is seperated into .cxx file
    template <typename T>
    class Array {
    public:
        //default construct
        Array() : count{0}, ptr{new T[count]}, space{0} { }

        explicit Array(int length) {
            count = length;
            ptr = new T[count + 1];
            space = count;
        }

        Array(const Array& arr) {
            copy_from(arr);
        }

        Array(Array&& arr) noexcept {
            move_from(arr);
        }

        ~Array() { delete[] ptr; }

        //Operators
        T& operator[](int n) { return ptr[n]; }
        T operator[](int n) const { return ptr[n]; }

        Array<T>& operator=(const Array<T>& arr) {
            if (this == &arr) return *this;
            T* p = ptr;
            copy_from(arr);
            delete[] p;
            return *this;
        }

        Array<T>& operator=(Array<T>&& arr) noexcept {
            if (this == &arr) return *this;
            delete[] ptr;
            move_from(arr);
            return *this;
        }
        //TODO make concat? (only if cases arise)
        //TODO make compare? (very expensive operation and we don't know if our generic has == operators)

        T& at(const int n) {
            check(n);
            return ptr[n];
        }

        T at(int n) const {
            check(n);
            return ptr[n];
        }

        int capacity() const {
            return count + space;
        }

        T* getPtr() const {
            return ptr;
        }

        int size() const {
            return count;
        }

        //regular/fastest add operation
        void addBack(T obj) {
            if (space == 0) {
                int n = count + count + 1;
                ptr = expand(ptr, n);
                space = n - count - 1;
            } else {
                --space;
            }
            ptr[count++] = obj;
        }

        //helper nonmember functions
        T* begin() {
            return ptr;
        }

        T* end() {
            return ptr + count;
        }

    private:
        int count;
        T* ptr;
        int space;

        void check(int n) const {
            if (n < 0 || count <= n)
                throw std::out_of_range("nostd::Array::at()");
        }

        T* expand(const T* ptr, int n) {
            T* temp = new T[n];
            for (int i = 0; i < this->size(); ++i) {
                temp[i] = ptr[i];
            }
            delete[] ptr;
            return temp;
        }

        void copy_from(const Array<T>& arr) {
            ptr = this->expand(arr.ptr, arr.count);
            count = arr.count;
        }

        void move_from(Array<T>& arr) {
            ptr = arr.ptr;
            space = arr.space;
            count = arr.count;
            delete[] arr.ptr;
            arr.count = 0;
            arr.space = 0;
        }
    };
}


#endif //EINDOPDRACHT_ARRAY_H
