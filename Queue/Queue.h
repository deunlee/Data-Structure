#ifndef __DEUN_QUEUE__
#define __DEUN_QUEUE__

#include <new>

namespace Deun {
    enum class QueueError {
        QUEUE_ALLOCATION_FAILED,
        QUEUE_IS_EMPTY,
    };

    // 배열 기반 원형 큐
    class Queue {
    private:
        int* elements;
        unsigned int size;  // 큐의 크기 (배열 원소의 개수)
        unsigned int count; // 채워진 데이터의 개수
        // (count 변수를 사용하지 않아도 큐의 공백/포화 상태를
        //  검출할 수 있지만, 배열의 원소 중 하나를 비워두어야 한다.
        //  이것이 별로 마음에 들지 않아 count 변수를 사용하기로 하였다.)
        unsigned int front; // 원소를 삭제할 자리
        unsigned int rear;  // 원소를 삽입할 자리

    public:
        Queue(unsigned int size = 100);
        ~Queue();

        bool isEmpty();
        bool isFull();

        unsigned int getSize();
        unsigned int getCount();

        bool enqueue(int element); // 맨 뒤에 삽입 (성공시 true, 실패시 false)
        int dequeue();             // 맨 앞 원소 반환 및 삭제 (실패시 throw)
        int peek();                // 맨 앞 원소 반환 (실패시 throw)
    };
}

#endif
