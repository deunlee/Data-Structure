#ifndef __DEUN_STACK_CPP__
#define __DEUN_STACK_CPP__

#include "Stack.h"

namespace Deun {
    Stack::Stack(unsigned int size) {
        this->size = size;
        top = 0;
        elements = new (std::nothrow) int[size];

        if (!elements) {
            this->size = 0;
            throw StackError::MEMORY_ALLOCATION_FAILED;
        }
    }

    Stack::~Stack() {
        delete[] elements;
    }

    bool Stack::isEmpty() {
        return (top == 0);
    }

    bool Stack::isFull() {
        return (top == size);
    }

    unsigned int Stack::getSize() {
        return size;
    }

    unsigned int Stack::getCount() {
        return top;
    }

    bool Stack::push(int element) {
        if (isFull()) {
            return false;
        }

        elements[top++] = element;
        return true;
    }

    int Stack::pop() {
        if (isEmpty()) {
            throw StackError::ELEMENT_NOT_FOUND;
        }

        return elements[--top];
    }

    int Stack::peek() {
        if (isEmpty()) {
            throw StackError::ELEMENT_NOT_FOUND;
        }

        return elements[top - 1];
    }
}

#endif
