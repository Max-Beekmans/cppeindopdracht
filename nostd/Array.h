//
// Created by Max on 9/13/2018.
//

#ifndef EINDOPDRACHT_ARRAY_H
#define EINDOPDRACHT_ARRAY_H

#include <stdexcept>
#include <cstring>

namespace nostd {
    //Generic array object using pointer semantics and providing short string optimization
    //Header only cause templatized classes cause some nasty linker errors when
    //implementatation is seperated into .cxx file
    template <typename T>
    class Array {
    private:
        //short-string optimization for array
        static const int short_max = 15;
        int count;
        int elements;
        T* ptr;
        // discriminated union (count <= short_max)
        union {
            // unused space;
            int space;
            // +1 for terminating char
            T ss[short_max + 1];
        };

        void check(int n) const {
            if (n < 0 || count <= n)
                throw std::out_of_range("nostd::Array::at()");
        }

        T* expand(const T* ptr, int n) {
            T* temp = new T[n];
            memcpy(temp, ptr, n);
            return temp;
        }

        void copy_from(const Array<T>& arr) {
            if (arr.count <= short_max) {
                memcpy(this, &arr, sizeof(arr));
                ptr = ss;
            } else {
                ptr = this->expand(arr.ptr, arr.count + 1);
                space = 0;
            }
            count = arr.count;
        }

        void move_from(Array<T>& arr) {
            if (arr.count <= short_max) {
                memcpy(this, &arr, sizeof(arr));
                ptr = ss;
            } else {
                ptr = arr.ptr;
                space = arr.space;
                arr.ptr = arr.ss;
//                arr.ss = [];
            }
            count = arr.count;
            arr.count = 0;
        }

    public:
        //Construct
        Array() : count{0}, ptr{ss}, space{0}, elements{0} {}
        ~Array() { if (short_max < count) delete [] ptr; }

        explicit Array(int length) {
            count = length;
            if (short_max < count) {
                ptr = new T[count + 1];
                space = count;
            } else {
                ptr = ss;
                space = 0;
            }
        }

        Array(const Array& arr) {
            copy_from(arr);
        }

        Array(Array&& arr) noexcept {
            move_from(arr);
        }

        //Operators
        T& operator[](int n) { return ptr[n]; }
        T operator[](int n) const { return ptr[n]; }

        Array<T>& operator=(const Array<T>& arr) {
            if (this == &arr) return *this;
            T* p = (short_max < count) ? ptr : nullptr;
            copy_from(arr);
            delete[] p;
            return *this;
        }

        Array<T>& operator=(Array<T>&& arr) noexcept {
            if (this == &arr) return *this;
            if (count > short_max) delete [] ptr;
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
            if (count <= short_max) {
                return count;
            }
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
            if (count == short_max) {
                //double alloc (+2 for terminating 0)
                int n = count + count + 2;
                ptr = expand(ptr, n);
                space = n - count - 2;
            } else if (short_max < count) {
                if (space == 0) {
                    int n = count + count + 2;
                    T *p = expand(ptr, n);
                    delete[] ptr;
                    ptr = p;
                    space = n - count - 2;
                } else {
                    --space;
                }
            }
            ptr[elements++] = obj;
            //ptr[++count] = '\0';
            //return *this;
        }

        //exceptional add operation (for room shuffle)
        //TODO Shuffle Rooms, Add last element to front! ez extra credit
        void addFront(T obj) {

        }

        //helper nonmember functions
        T* begin() {
            return ptr;
        }

        T* end() {
            return ptr + count;
        }
    };
}


#endif //EINDOPDRACHT_ARRAY_H
