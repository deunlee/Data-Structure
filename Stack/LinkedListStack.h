#ifndef __DEUN_LINKED_LIST_STACK_H__
#define __DEUN_LINKED_LIST_STACK_H__

#include "Stack.hpp"

namespace Deun {
    /**
     * 스택 노드
     */
    template <typename T>
    struct StackNode {
        T data;
        StackNode* next;
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
         * @return {int}
         */
        int getCount();

        /**
         * 스택이 비어있는지의 여부를 반환합니다.
         * @return {bool}
         */
        bool isEmpty();

        /**
         * 스택이 가득 차있는지의 여부를 반환합니다.
         * 연결 리스트로 구현된 스택에서는 항상 false를 반환합니다.
         * @return {bool}
         */
        bool isFull();
        
        /**
         * 스택에 원소를 삽입하고 성공 여부를 반환합니다.
         * @param  {T} element 원소
         * @return {bool}
         */
        bool push(const T& element);

        /**
         * 스택에서 마지막 원소를 반환하고 삭제합니다.
         * @return {T}
         * @throw  {StackError}
         */
        T pop();

        /**
         * 스택에서 마지막 원소를 반환합니다.
         * pop()과 다르게 원소를 삭제하지 않습니다.
         * @return {T}
         * @throw  {StackError}
         */
        const T& peek();

        /**
         * 스택을 초기화합니다.
         * 모든 원소가 삭제됩니다.
         */
        void clear();
    };
}

#endif
