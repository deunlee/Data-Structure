#ifndef __DEUN_LINKED_LIST_H__
#define __DEUN_LINKED_LIST_H__

#include <iostream>
#include <new>

namespace Deun {
    enum class LinkedListError {
        MEMORY_ALLOCATION_FAILED = 1000,
        NODE_NOT_FOUND,
    };

    typedef struct Node {
        int data;
        struct Node* link;
    } Node;

    // 단순 연결 리스트
    class LinkedList {
    private:
        Node* head;
        Node* tail;
        unsigned int count;

        bool isValid(unsigned int index);
        Node* getNode(unsigned int index); // O(n)

    public:
        LinkedList();
        ~LinkedList();

        bool isEmpty();
        unsigned int getCount();

        // index: 0-based

        bool insert(unsigned int index, int data); // 특정 위치에 노드 삽입 (성공 = true, 실패 = false)
        bool insertFront(int data);                // 맨 앞에 노드 삽입     (성공 = true, 실패 = false)
        bool insertRear(int data);                 // 맨 뒤에 노드 삽입     (성공 = true, 실패 = false)

        bool remove(unsigned int index);           // 특정 위치 노드 제거   (성공 = true, 실패 = false)
        bool removeFront();                        // 맨 앞 노드 제거       (성공 = true, 실패 = false)
        bool removeRear();                         // 맨 뒤 노드 제거       (성공 = true, 실패 = false)

        int get(unsigned int index);               // 특정 위치 노드 반환   (실패 = throw)
        int getFront();                            // 맨 앞 노드 반환       (실패 = throw)
        int getRear();                             // 맨 뒤 노드 반환       (실패 = throw)

        bool update(unsigned int index, int data); // 특정 위치 노드 수정   (성공 = true, 실패 = false)
        bool updateFront(int data);                // 맨 앞 노드 수정       (성공 = true, 실패 = false)
        bool updateRear(int data);                 // 맨 뒤 노드 수정       (성공 = true, 실패 = false)

        unsigned int find(int data); // 주어진 값과 일치하는 첫 번째 노드의 인덱스 반환 (실패 = throw)
        void print();                // 현재 상태 출력

        // 시간 복잡도

        // insert()  insertFront()  insertRear()
        // O(n)      O(1)           O(1)

        // remove()  removeFront()  removeRear()
        // O(n)      O(1)           O(n)

        // get()     getFront()     getRear()
        // O(n)      O(1)           O(1)

        // update()  updateFront()  updateRear()
        // O(n)      O(1)           O(1)

        // find()
        // O(n)

        // removeRear()가 O(n)인 이유는 tail의 앞 노드를 알 수 없기 때문임
        // tail의 link는 사용하지 않으므로, link를 tail의 앞 노드로 설정하면
        // O(1)에 삭제가 가능하게 바꿀 수 있을 것 같음 (TODO?)
    };
}

#endif
