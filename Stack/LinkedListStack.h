#ifndef __DEUN_LINKED_LIST_STACK_H__
#define __DEUN_LINKED_LIST_STACK_H__

#include "Stack.hpp"

namespace Deun {
    /**
     * 스택 노드
     */
    template <typename T>
    class StackNode {
    private:
        const T    data;
        StackNode* next;

    public:
        StackNode(const T& data) : data(data) { }
        // data를 복사 생성자로 초기화하기 위해 상수로 선언하고 생성자의 초기화 리스트를 이용해 초기화한다.
        // (data가 기본 생성자로 생성되고 맴버 변수들의 값만 덮어써지는 것을 막기 위함.)
        
        inline T& getData() {
            return const_cast<T&>(data);
        }

        inline StackNode* getNext() {
            return next;
        }

        inline void setNext(StackNode* next) {
            this->next = next;
        }
    };

    /**
     * 스택 클래스 (연결 리스트 기반)
     */
    template <typename T>
    class LinkedListStack : public Stack<T> {
    private:
        StackNode<T>* head; // 첫 번째 노드를 가리키는 포인터

    public:
        /**
         * 스택 생성자
         */
        LinkedListStack();

        /**
         * 스택 소멸자
         */
        ~LinkedListStack();

        /**
         * 현재 스택에 들어있는 원소의 개수를 반환합니다.
         */
        int getCount();

        /**
         * 스택이 비어있는지의 여부를 반환합니다.
         */
        bool isEmpty();

        /**
         * 스택이 가득 차있는지의 여부를 반환합니다.
         * 연결 리스트로 구현된 스택에서는 항상 false를 반환합니다.
         */
        bool isFull();
        
        /**
         * 스택에 원소를 삽입하고 성공 여부를 반환합니다.
         * @param element 원소
         */
        bool push(const T& element);

        /**
         * 스택의 마지막 원소를 삭제하고 성공 여부를 반환합니다.
         */
        bool pop();

        /**
         * 스택의 마지막 원소를 반환합니다.
         * @throw StackError (스택이 빈 경우)
         */
        T& peek();

        /**
         * 스택을 출력합니다.
         */
        void print();

        /**
         * 스택을 초기화합니다. (모든 원소가 삭제됩니다.)
         */
        void clear();
    };
}

#endif
