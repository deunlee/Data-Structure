#ifndef __DEUN_STACK__
#define __DEUN_STACK__

#include <new>

namespace Deun {
    enum class StackError {
        STACK_ALLOCATION_FAILED,
        STACK_IS_EMPTY,
    };

    // 배열 기반 스택
    class Stack {
    private:
        int* elements;
        unsigned int size;
        unsigned int top;

    public:
        Stack(unsigned int size = 100);
        ~Stack();

        bool isEmpty();
        bool isFull();
        
        unsigned int getSize();
        unsigned int getCount();

        bool push(int element);
        int pop();
        int peek();
    };
}

#endif
