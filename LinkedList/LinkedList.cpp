#ifndef __DEUN_LINKED_LIST_CPP__
#define __DEUN_LINKED_LIST_CPP__

#include "LinkedList.h"

namespace Deun {
    LinkedList::LinkedList() {
        head = tail = NULL;
        count = 0;
    }

    LinkedList::~LinkedList() {
        Node* current = head;
        Node* next;
        while (current) { // 모두 삭제
            next = current->link;
            delete current;
            current = next;
        }
    }

    // 인덱스 유효성 검증
    bool LinkedList::isValid(unsigned int index) {
        // index는 0부터 시작하므로, count보다 작아야 함
        return (index < count);
    }
    
    Node* LinkedList::getNode(unsigned int index) {
        if (!isValid(index)) {
            return NULL;
        }
        if (index + 1 == count) {
            return tail;
        }

        // index가 유효하다면, current는 항상 NULL이 아님
        Node* current = head;
        for (unsigned int i = 0; i < index; i++) {
            current = current->link;
        }
        return current;
    }

    bool LinkedList::isEmpty() {
        return (count == 0);
    }

    unsigned int LinkedList::getCount() {
        return count;
    }

    // 삽입
    bool LinkedList::insert(unsigned int index, int data) {
        if (index == 0) { // 맨 앞에 삽입
            return insertFront(data);
        }
        else if (index == count) { // 맨 뒤에 삽입
            return insertRear(data);
        }
        else if (!isValid(index)) {
            return false;
        }

        // 여기부터는 index가 1 이상임이 보장됨
        Node* preNode = getNode(index - 1);
        Node* newNode = new (std::nothrow) Node;
        if (!newNode) {
            return false; // 메모리 할당 실패
        }
        
        // head와 tail 포인터는 수정할 필요가 없음
        // 수정이 필요한 경우는 insertFront()와 insertRear()에서 따로 처리함
        newNode->data = data;
        newNode->link = preNode->link;
        preNode->link = newNode;
        count++;
        return true;
    }

    bool LinkedList::insertFront(int data) {
        Node* newNode = new (std::nothrow) Node;
        if (!newNode) {
            return false; // 메모리 할당 실패
        }

        newNode->data = data;
        newNode->link = head;
        head = newNode;
        tail = (tail ? tail : newNode); // 노드가 하나인 경우 tail도 같게 함
        count++;
        return true;
    }

    bool LinkedList::insertRear(int data) {
        Node* newNode = new (std::nothrow) Node;
        if (!newNode) {
            return false; // 메모리 할당 실패
        }

        newNode->data = data;
        newNode->link = NULL;
        tail->link = newNode;
        tail = newNode;
        head = (head ? head : newNode); // 노드가 하나인 경우 head도 같게 함
        count++;
        return true;
    }

    // 삭제
    bool LinkedList::remove(unsigned int index) {
        if (index == 0) { // 맨 앞 노드 삭제
            return removeFront();
        }
        else if (!isValid(index)) {
            return false;
        }

        // 여기부터는 index가 1 이상임이 보장됨
        Node* preNode = getNode(index - 1);
        Node* curNode = preNode->link;
        preNode->link = curNode->link;
        delete curNode;
        count--;
        if (!preNode->link) { // 삭제된 노드가 마지막 노드이면 tail 변경
            tail = preNode;
        }
        return true;
    }

    bool LinkedList::removeFront() {
        if (!head) {
            return false;
        }

        Node* next = head->link;
        delete head;
        head = next;
        tail = (head ? tail : NULL); // 노드가 하나도 없는 경우 tail도 NULL로 변경
        count--;
        return true;
    }

    bool LinkedList::removeRear() {
        // tail의 앞 노드를 저장해두지 않았기 때문에 O(1)로 삭제할 수 없음
        return remove(count - 1);
    }

    // 조회
    int LinkedList::get(unsigned int index) {
        Node* current = getNode(index);
        if (!current) {
            throw LinkedListError::NODE_NOT_FOUND;
        }
        return current->data;
    }

    int LinkedList::getFront() {
        if (!head) {
            throw LinkedListError::NODE_NOT_FOUND;
        }
        return head->data;
    }

    int LinkedList::getRear() {
        if (!tail) {
            throw LinkedListError::NODE_NOT_FOUND;
        }
        return tail->data;
    }

    // 수정
    bool LinkedList::update(unsigned int index, int data) {
        Node* current = getNode(index);
        if (!current) {
            return false;
        }
        current->data = data;
        return true;
    }

    bool LinkedList::updateFront(int data) {
        if (!head) {
            return false;
        }
        head->data = data;
        return true;
    }

    bool LinkedList::updateRear(int data) {
        if (!tail) {
            return false;
        }
        tail->data = data;
        return true;
    }

    // 검색
    unsigned int LinkedList::find(int data) {
        if (!head) {
            throw LinkedListError::NODE_NOT_FOUND;
        }

        Node* current = head;
        for (unsigned int i = 0; i < count; i++) {
            if (current->data == data) {
                return i;
            }
            current = current->link;
        }
        throw LinkedListError::NODE_NOT_FOUND;
    }

    // 출력
    void LinkedList::print() {
        using namespace std;

        cout << "LinkedList(count=" << count;
        cout << ", head=0x" << head << ", tail=0x" << tail << ")" << endl;

        cout << "head -> ";
        Node* current = head;
        for (unsigned int i = 0; i < count; i++) {
            cout << i << "=" << current->data << "(0x" << current << ") -> ";
            current = current->link;
        }
        cout << "NULL" << endl;
    }
}

#endif
