#ifndef __DEUN_ARRAY_STACK_HPP__
#define __DEUN_ARRAY_STACK_HPP__

#include "ArrayStack.h"

namespace Deun {
    template <typename T>
    ArrayStack<T>::ArrayStack(int size) : Stack(0), size(size) {
        if (size <= 0) {
            throw StackError::SIZE_IS_TOO_SMALL;
        }
        array = static_cast<T*>(operator new(sizeof(T) * size, std::nothrow));
        // new는 메모리 할당 후 생성자를 호출하지만, operator new는 메모리만 할당한다.
        // (C의 malloc()와 동일하게 생성자를 호출하지 않는다.)
        // new를 사용하는 경우 기본 생성자가 없는 클래스는 컴파일 오류가 발생한다.
        if (!array) {
            throw StackError::MEMORY_ALLOCATION_FAILED;
        }
    }

    template <typename T>
    ArrayStack<T>::~ArrayStack() {
        clear(); // 명시적 소멸자 호출
        operator delete(array); // 모든 메모리를 반환한다.
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
        return (count == 0); // count는 top 용도로 쓰인다.
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
        new(&array[count++]) T(element); // placement new
        // 스택 생성자에서 미리 할당해 놓은 메모리에 T의 복사 생성자로 생성한다.
        // placement new는 new와 다르게 메모리를 할당하지 않고 기존 메모리에 생성한다.
        // 깊은 복사가 필요한 클래스를 사용할 경우 직접 복사 생성자를 구현해야 한다.
        return true;
    }

    template <typename T>
    bool ArrayStack<T>::pop() {
        if (isEmpty()) {
            return false;
        }
        array[--count].~T(); // 명시적 소멸자 호출
        return true;
    }

    template <typename T>
    T& ArrayStack<T>::peek() {
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
        for (int i = count - 1; i >= 0; i--) { // top 부터 삭제
            array[i].~T(); // 명시적 소멸자 호출
        }
        count = 0;
    }
}

#endif
