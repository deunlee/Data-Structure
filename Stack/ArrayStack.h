#ifndef __DEUN_ARRAY_STACK_H__
#define __DEUN_ARRAY_STACK_H__

#include "Stack.hpp"

namespace Deun {
    /**
     * 스택 클래스 (배열 기반)
     */
    template <typename T>
    class ArrayStack : public Stack<T> {
    private:
        int size;  // 스택의 최대 크기 (메모리 할당량)
        T*  array; // 데이터 저장을 위한 배열
        // top은 Stack 인터페이스의 count 변수를 사용함.
        // count라고 명명한 이유는 LinkedListStack에서도 사용하기 위해서임.

    public:
        /**
         * 스택 생성자
         * @param size 스택의 최대 크기
         * @throw StackError (크기 오류 또는 메모리 할당 실패)
         */
        ArrayStack(int size = 1000);

        /**
         * 스택 소멸자
         */
        ~ArrayStack();

        /**
         * 스택의 최대 크기를 반환합니다.
         */
        int getSize();

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
