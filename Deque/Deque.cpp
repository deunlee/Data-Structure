#ifndef __DEUN_DEQUE_CPP__
#define __DEUN_DEQUE_CPP__

#include "Deque.h"

namespace Deun {
    Deque::Deque(unsigned int size) {
        this->size = size;
        count = front = rear = 0;
        elements = new (std::nothrow) int[size];

        if (!elements) {
            this->size = 0;
            throw DequeError::MEMORY_ALLOCATION_FAILED;
        }
    }

    Deque::~Deque() {
        delete[] elements;
    }

    bool Deque::isEmpty() {
        return (count == 0);
    }

    bool Deque::isFull() {
        return (count == size);
    }

    unsigned int Deque::getSize() {
        return size;
    }

    unsigned int Deque::getCount() {
        return count;
    }

    // front : 채워진 상태   (단, count가 0이면 비워져 있음)
    // rear  : 비어있는 상태 (단, count가 size면 채워져 있음)

    // front와 rear 중 하나는 채워진 상태가, 나머지 하나는 비어있는 상태가 되도록 해야 함
    // Deque을 Stack으로 사용하는 경우에는 둘 다 채워져 있거나 둘 다 비어있어도 되지만,
    // Deque을 Queue로 사용하는 경우 맨 처음에 들어간 원소가 맨 처음으로 나오지 않게 됨

    bool Deque::pushFront(int element) {
        if (isFull()) {
            return false;
        }

        count++;
        front = (size - 1 + front) % size; // 안전한 방법은 아님
        //front = (front - 1 + size) % size; // 이건 더 위험함 (front는 unsigned임)
        elements[front] = element;
        return true;
    }

    bool Deque::pushRear(int element) {
        if (isFull()) {
            return false;
        }

        // 큐의 enqueue()와 동일
        count++;
        elements[rear] = element;
        rear = (rear + 1) % size;
        return true;
    }

    int Deque::popFront() {
        if (isEmpty()) {
            throw DequeError::ELEMENT_NOT_FOUND;
        }

        // 큐의 dequeue()와 동일
        count--;
        int result = elements[front];
        front = (front + 1) % size;
        return result;
    }

    int Deque::popRear() {
        if (isEmpty()) {
            throw DequeError::ELEMENT_NOT_FOUND;
        }

        count--;
        rear = (size - 1 + rear) % size;
        return elements[rear];
    }

    int Deque::peekFront() {
        if (isEmpty()) {
            throw DequeError::ELEMENT_NOT_FOUND;
        }

        return elements[front];
    }

    int Deque::peekRear() {
        if (isEmpty()) {
            throw DequeError::ELEMENT_NOT_FOUND;
        }

        return elements[(size - 1 + rear) % size];
    }

    void Deque::clear() {
        count = front = rear = 0;

        for (unsigned int i = 0; i < size; i++) {
            elements[i] = 0;
        }
    }

    void Deque::print() {
        using namespace std;

        cout << "Deque(size=" << size << ", count=" << count;
        cout << ", front=" << front << ", rear=" << rear << ")" << endl;

        for (unsigned int i = 0; i < size; i++) {
            cout << elements[i];
            if (i == front) cout << "F";
            if (i == rear)  cout << "R";
            cout << "\t";
        }

        cout << endl;
    }
}

#endif
