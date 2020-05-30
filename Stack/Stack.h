#ifndef __DEUN_STACK_H__
#define __DEUN_STACK_H__

#include <new>

namespace Deun {
    enum class StackError {
        MEMORY_ALLOCATION_FAILED = 1000,
        ELEMENT_NOT_FOUND,
    };

    // 배열 기반 스택
    class Stack {
    private:
        int* elements;
        unsigned int size; // 스택의 크기 (배열 원소의 개수)
        unsigned int top;  // 원소를 삽입/삭제할 자리

    public:
        Stack(unsigned int size = 1000);
        ~Stack();

        bool isEmpty();
        bool isFull();
        
        unsigned int getSize();  // 전체 크기 반환
        unsigned int getCount(); // 채워진 원소의 개수 반환

        bool push(int element);  // 맨 뒤에 원소 삽입 (성공 = true, 실패 = false)
        int pop();               // 맨 뒤 원소 반환 및 삭제 (실패 = throw)
        int peek();              // 맨 뒤 원소 반환 (실패 = throw)       
    };
}

#endif
