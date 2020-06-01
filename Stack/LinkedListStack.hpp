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
        // 스택의 맨 앞에 노드를 삽입한다.
        StackNode<T>* front = new (std::nothrow) StackNode<T>;
        if (!front) {
            return false;
        }
        front->data = element; // 클래스 내부 값만 복사 (얕은 복사)
        front->next = head;
        head = front;
        count++;
        return true;
    }

    template <typename T>
    bool LinkedListStack<T>::pop() {
        // 스택의 마지막 원소를 삭제한다.
        if (isEmpty()) {
            return false;
        }
        StackNode<T>* front = head;
        head = front->next;
        delete front;
        count--;
        return true;
    }

    template <typename T>
    T& LinkedListStack<T>::peek() {
        if (isEmpty()) {
            throw StackError::ELEMENT_NOT_FOUND;
        }
        return head->data;
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
            cout << " -> " << current->data;
            current = current->next;
        }
        cout << endl;
    }

    template <typename T>
    void LinkedListStack<T>::clear() {
        StackNode<T>* current = head;
        StackNode<T>* next;
        while (current) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        count = 0;
    }
}

#endif
