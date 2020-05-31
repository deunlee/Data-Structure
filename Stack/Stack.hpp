#ifndef __DEUN_STACK_HPP__
#define __DEUN_STACK_HPP__

#include <iostream>
#include <new>

namespace Deun {
    /**
     * 스택 인터페이스
     */
    template <typename T>
    class Stack {
    protected:
        int count; // 현재 원소의 개수 (ArrayStack에서는 top으로 사용됨)

        Stack(int count) : count(count) {}

    public:
        virtual int getCount() = 0;
        virtual bool isEmpty() = 0;
        virtual bool isFull() = 0;

        virtual bool push(const T& element) = 0;
        virtual T pop() = 0;
        virtual const T& peek() = 0;

        virtual void print() = 0;
        virtual void clear() = 0;
    };

    /**
     * 스택 오류
     */
    enum class StackError {
        MEMORY_ALLOCATION_FAILED = 1000,
        SIZE_IS_TOO_SMALL,
        ELEMENT_NOT_FOUND,
    };
}

#endif
