#ifndef __DEUN_LINKED_LIST_STACK_HPP__
#define __DEUN_LINKED_LIST_STACK_HPP__

#include "LinkedListStack.h"

namespace Deun {
    template <typename T>
    LinkedListStack<T>::LinkedListStack() : Stack(0), head(nullptr) {}

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
        // 스택의 맨 앞에 노드를 삽입한다.
        StackNode<T>* front = new (std::nothrow) StackNode<T>;
        if (!front) {
            return false;
        }
        front->data = element;
        front->next = head;
        head = front;
        count++;
        return true;
    }

    template <typename T>
    T LinkedListStack<T>::pop() {
        // 스택의 맨 앞 노드를 반환하고 삭제한다.
        if (isEmpty()) {
            throw StackError::ELEMENT_NOT_FOUND;
        }

        StackNode<T>* front = head;
        T data = front->data;
        head = front->next;
        delete front;
        count--;
        return data;
    }

    template <typename T>
    const T& LinkedListStack<T>::peek() {
        if (isEmpty()) {
            throw StackError::ELEMENT_NOT_FOUND;
        }

        return head->data;
    }

    template <typename T>
    void LinkedListStack<T>::clear() {
        StackNode<T>* front = head;
        StackNode<T>* next;
        while (front) {
            next = front->next;
            delete front;
            front = next;
        }
        head = nullptr;
        count = 0;
    }
}

#endif
