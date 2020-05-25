#ifndef __DEUN_DEQUE__
#define __DEUN_DEQUE__

#include <iostream>
#include <new>

namespace Deun {
    enum class DequeError {
        DEQUE_ALLOCATION_FAILED,
        DEQUE_IS_EMPTY,
    };

    // 배열 기반 원형 덱
    class Deque {
    private:
        int* elements;
        unsigned int size;  // 덱의 크기 (배열 원소의 개수)
        unsigned int count; // 채워진 원소의 개수
        unsigned int front; // 원소를 삭제할 자리
        unsigned int rear;  // 원소를 삽입할 자리

    public:
        Deque(unsigned int size = 100);
        ~Deque();

        bool isEmpty();
        bool isFull();

        unsigned int getSize();  // 전체 크기 반환
        unsigned int getCount(); // 채워진 원소의 개수 반환

        bool pushFront(int element); // 맨 앞에 원소 삽입 (성공 = true, 실패 = false)
        bool pushRear(int element);  // 맨 뒤에 원소 삽입 (성공 = true, 실패 = false)
        int popFront();  // 맨 앞 원소 반환 및 삭제 (실패 = throw)
        int popRear();   // 맨 뒤 원소 반환 및 삭제 (실패 = throw)
        int peekFront(); // 맨 앞 원소 반환 (실패 = throw)
        int peekRear();  // 맨 뒤 원소 반환 (실패 = throw)

        // for debug
        void clear();
        void print();
    };
}

#endif
