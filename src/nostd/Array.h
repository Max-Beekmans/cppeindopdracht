//
// Created by Max on 9/13/2018.
//

#ifndef EINDOPDRACHT_ARRAY_H
#define EINDOPDRACHT_ARRAY_H

#define DEFAULT_SIZE 10

#include <stdexcept>
#include <cstring>

namespace nostd {
    //Generic array object using pointer semantics and providing short string optimization
    //Header only cause templatized classes cause some nasty linker errors when
    //implementatation is seperated into .cxx file
    template <typename T>
    class Array {
    public:
        //default construct
        //array is 10 by default
        Array() : count(0), space(DEFAULT_SIZE), ptr(new T[DEFAULT_SIZE]) {}

        explicit Array(int length) {
            count = 0;
            ptr = new T[length];
            space = length;
        }

        Array(const Array& arr) : count(0), space(0), ptr(nullptr) {
            copy_from(arr);
        }

        Array(Array&& arr) noexcept : count(0), space(0), ptr(nullptr) {
            move_from(arr);
        }

        ~Array() { delete[] ptr; }

        //Operators
        T& operator[](int n) { return ptr[n]; }
        T operator[](int n) const { return ptr[n]; }

        Array<T>& operator=(const Array<T>& arr) {
            if (this == &arr) return *this;
            copy_from(arr);
            return *this;
        }

        Array<T>& operator=(Array<T>&& arr) noexcept {
            if (this == &arr) return *this;
            delete[] ptr;
            move_from(arr);
            return *this;
        }

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
                int n = count + count;
                expand(ptr, n);
                space = n - count;
            } else {
                --space;
            }
            ptr[count++] = obj;
        }

        void removeN(const int n) {
            //I don't know how to override the last element and shift
            //So I just copy everything - 1 and overwrite
            T* temp = new T[count - 1];
            for (int i = n; i < count - 1; ++i) {
                temp[i] = ptr[i + 1];
            }
            delete[] ptr;
            ptr = temp;
            count = count - 1;
            space++;

//            for (size_t i = n; i < count - 1; ++i) {
//                ptr[i] = ptr[i + 1];
//            }
        }

        const int find(const T& obj) const{
            for(int i = 0; i < count; ++i) {
                if(ptr[i] == obj) {
                    return i;
                }
            }
            return -1;
        }

        //helper nonmember functions
        T* begin() {
            return ptr;
        }

        T* end() {
            return ptr + count;
        }

        const T* begin() const {
            return ptr;
        }

        const T* end() const {
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

        void expand(const T* p, int n) {
            T* temp = new T[n];
            //memcpy(temp, ptr, sizeof(temp));
            for (int i = 0; i < this->size(); ++i) {
                temp[i] = p[i];
            }
            delete[] ptr;
            this->ptr = temp;
        }

        void copy_from(const Array<T>& arr) {
            count = arr.count;
            this->expand(arr.ptr, arr.count);
            space = 0;
        }

        void move_from(Array<T>& arr) {
            ptr = arr.ptr;
            space = arr.space;
            count = arr.count;
            arr.ptr = 0;
            //delete[] arr.ptr;
            arr.count = 0;
            arr.space = 0;
        }
    };
}


#endif //EINDOPDRACHT_ARRAY_H
