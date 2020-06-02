#ifndef __DEUN_LINKED_LIST_STACK_HPP__
#define __DEUN_LINKED_LIST_STACK_HPP__

#include "LinkedListStack.h"

namespace Deun {
    template <typename T>
    LinkedListStack<T>::LinkedListStack() : Stack(0), head(nullptr) { }

    template <typename T>
    LinkedListStack<T>::~LinkedListStack() {
        clear();
    }

    template <typename T>
    int LinkedListStack<T>::getCount() {
        return count;
    }

    template <typename T>
    bool LinkedListStack<T>::isEmpty() {
        return (count == 0);
    }
    
    template <typename T>
    bool LinkedListStack<T>::isFull() {
        return false; // 연결 리스트로 구현한 스택은 한계가 없다고 가정한다.
    }

    template <typename T>
    bool LinkedListStack<T>::push(const T& element) {
        StackNode<T>* front = new(std::nothrow) StackNode<T>(element);
        // element를 복사 생성자로 생성한다.
        // 깊은 복사가 필요한 클래스를 사용할 경우 직접 복사 생성자를 구현해야 한다.
        // 기본 생성자로 생성하고 값만 덮어쓰면 레퍼런스로 받은 element가
        // 삭제된 경우 pop()에서 문제가 될 수 있다. (double free)
        if (!front) {
            return false;
        }
        front->setNext(head);
        head = front;
        count++;
        return true;
    }

    template <typename T>
    bool LinkedListStack<T>::pop() {
        if (isEmpty()) {
            return false;
        }
        StackNode<T>* front = head;
        head = front->getNext();
        delete front; // data도 같이 삭제됨
        count--;
        return true;
    }

    template <typename T>
    T& LinkedListStack<T>::peek() {
        if (isEmpty()) {
            throw StackError::ELEMENT_NOT_FOUND;
        }
        return head->getData();
    }

    template <typename T>
    void LinkedListStack<T>::print() {
        using namespace std;
        cout << "LinkedListStack(size=inf, count=" << count << ")" << endl;
        if (!head) {
            cout << "(empty)" << endl;
            return;
        }
        StackNode<T>* current = head;
        cout << "(head)";
        while (current) {
            cout << " -> " << current->getData();
            current = current->getNext();
        }
        cout << endl;
    }

    template <typename T>
    void LinkedListStack<T>::clear() {
        StackNode<T>* current = head;
        StackNode<T>* next;
        while (current) {
            next = current->getNext();
            delete current;
            current = next;
        }
        head = nullptr;
        count = 0;
    }
}

#endif
