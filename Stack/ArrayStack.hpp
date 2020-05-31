#ifndef __DEUN_ARRAY_STACK_HPP__
#define __DEUN_ARRAY_STACK_HPP__

#include "ArrayStack.h"

namespace Deun {
    template <typename T>
    ArrayStack<T>::ArrayStack(int size) : Stack(0), size(size) {
        if (size <= 0) {
            throw StackError::SIZE_IS_TOO_SMALL;
        }

        array = new (std::nothrow) T[size];
        if (!array) {
            throw StackError::MEMORY_ALLOCATION_FAILED;
        }
    }

    template <typename T>
    ArrayStack<T>::~ArrayStack() {
        delete[] array;
    }

    template <typename T>
    int ArrayStack<T>::getSize() {
        return size;
    }

    template <typename T>
    int ArrayStack<T>::getCount() {
        return count;
    }

    template <typename T>
    bool ArrayStack<T>::isEmpty() {
        return (count == 0); // count는 top 용도로 쓰임.
    }
    
    template <typename T>
    bool ArrayStack<T>::isFull() {
        return (count == size);
    }

    template <typename T>
    bool ArrayStack<T>::push(const T& element) {
        if (isFull()) {
            return false;
        }

        array[count++] = element;
        return true;
    }

    template <typename T>
    T ArrayStack<T>::pop() {
        if (isEmpty()) {
            throw StackError::ELEMENT_NOT_FOUND;
        }

        return array[--count];
    }

    template <typename T>
    const T& ArrayStack<T>::peek() {
        if (isEmpty()) {
            throw StackError::ELEMENT_NOT_FOUND;
        }

        return array[count - 1];
    }

    template <typename T>
    void ArrayStack<T>::print() {
        using namespace std;
        cout << "ArrayStack(size=" << size << ", count=" << count << ")" << endl;
        if (!count) {
            cout << "(empty)" << endl;
            return;
        }
        cout << "(top) ";
        for (int i = count - 1; i >= 0; i--) {
            cout << array[i];
            if (i) {
                cout << " / ";
            }
        }
        cout << endl;
    }

    template <typename T>
    void ArrayStack<T>::clear() {
        count = 0;
    }
}

#endif
