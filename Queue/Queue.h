#ifndef __DEUN_QUEUE_H__
#define __DEUN_QUEUE_H__

#include <new>

namespace Deun {
    enum class QueueError {
        MEMORY_ALLOCATION_FAILED = 1000,
        ELEMENT_NOT_FOUND,
    };

    // 배열 기반 원형 큐
    class Queue {
    private:
        int* elements;
        unsigned int size;  // 큐의 크기 (배열 원소의 개수)
        unsigned int count; // 채워진 원소의 개수
        // (count 변수를 사용하지 않아도 큐의 공백/포화 상태를
        //  검출할 수 있지만, 배열의 원소 중 하나를 비워두어야 함)
        // (비워두는 것이 마음에 들지 않아 count 변수를 사용하기로 함)
        unsigned int front; // 원소를 삭제할 자리
        unsigned int rear;  // 원소를 삽입할 자리

    public:
        Queue(unsigned int size = 1000);
        ~Queue();

        bool isEmpty();
        bool isFull();

        unsigned int getSize();    // 전체 크기 반환
        unsigned int getCount();   // 채워진 원소의 개수 반환

        bool enqueue(int element); // 맨 뒤에 원소 삽입       (성공 = true, 실패 = false)
        int dequeue();             // 맨 앞 원소 반환 및 삭제 (실패 = throw)
        int peek();                // 맨 앞 원소 반환         (실패 = throw)
    };
}

#endif
