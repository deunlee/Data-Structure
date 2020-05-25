#include "Queue.h"

namespace Deun {
    Queue::Queue(unsigned int size) {
        this->size = size;
        count = front = rear = 0;
        elements = new (std::nothrow) int[size];
        
        if (!elements) {
            this->size = 0;
            throw QueueError::QUEUE_ALLOCATION_FAILED;
        }
    }

    Queue::~Queue() {
        delete[] elements;
    }

    bool Queue::isEmpty() {
        return (count == 0);
    }

    bool Queue::isFull() {
        return (count == size);
    }

    unsigned int Queue::getSize() {
        return size;
    }

    unsigned int Queue::getCount() {
        return count;
    }

    // front : 원소를 삭제할 자리 (채워진 상태)   (단, count가 0이면 비워져 있음)
    // rear  : 원소를 삽입할 자리 (비어있는 상태) (단, count가 size면 채워져 있음)

    bool Queue::enqueue(int element) {
        if (isFull()) {
            return false;
        }

        count++;
        elements[rear] = element;
        rear = (rear + 1) % size;
        return true;
    }

    int Queue::dequeue() {
        if (isEmpty()) {
            throw QueueError::QUEUE_IS_EMPTY;
        }

        count--;
        int result = elements[front];
        front = (front + 1) % size;
        return result;
    }

    int Queue::peek() {
        if (isEmpty()) {
            throw QueueError::QUEUE_IS_EMPTY;
        }

        return elements[front];
    }
}
