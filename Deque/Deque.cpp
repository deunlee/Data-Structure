#include "Deque.h"

namespace Deun {
    Deque::Deque(unsigned int size) {
        this->size = size;
        count = front = rear = 0;
        elements = new (std::nothrow) int[size];

        if (!elements) {
            this->size = 0;
            throw DequeError::DEQUE_ALLOCATION_FAILED;
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

    inline unsigned int safeMove(unsigned int basis, int diff) {
        return basis;
    }

    // front : 채워진 상태   (단, count가 0이면 비워져 있음)
    // rear  : 비어있는 상태 (단, count가 size면 채워져 있음)

    bool Deque::pushFront(int element) {
        if (isFull()) {
            return false;
        }

        count++;
        front = (size - 1 + front) % size; // 사실 안전한 방법은 아님
        //front = (front - 1 + size) % size; // 이건 더 위험함 (front는 unsigned)
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
            throw DequeError::DEQUE_IS_EMPTY;
        }

        // 큐의 dequeue()와 동일
        count--;
        int result = elements[front];
        front = (front + 1) % size;
        return result;
    }

    int Deque::popRear() {
        if (isEmpty()) {
            throw DequeError::DEQUE_IS_EMPTY;
        }

        count--;
        rear = (size - 1 + rear) % size;
        return elements[rear];
    }

    int Deque::peekFront() {
        if (isEmpty()) {
            throw DequeError::DEQUE_IS_EMPTY;
        }

        return elements[front];
    }

    int Deque::peekRear() {
        if (isEmpty()) {
            throw DequeError::DEQUE_IS_EMPTY;
        }

        return elements[(size - 1 + rear) % size];
    }

    // for debug
    void Deque::clear() {
        for (unsigned int i = 0; i < size; i++) {
            elements[i] = 0;
        }
    }

    // for debug
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
