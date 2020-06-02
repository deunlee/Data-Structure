#ifndef __DEUN_ADJACENCY_LIST_GRAPH_HPP__
#define __DEUN_ADJACENCY_LIST_GRAPH_HPP__

#include "AdjacencyList.h"

namespace Deun {
    AdjacencyList::AdjacencyList(int vSize) {
        if (vSize <= 0) {
            this->vSize = 0;
            throw GraphError::MEMORY_ALLOCATION_FAILED;
        }

        this->vSize = vSize;
        vCount = 0;
        list = new (std::nothrow) ALNode*[vSize]; // 포인터 배열

        if (!list) {
            this->vSize = 0;
            throw GraphError::MEMORY_ALLOCATION_FAILED;
        }

        for (int i = 0; i < vSize; i++) {
            list[i] = nullptr;
        }
    }

    AdjacencyList::~AdjacencyList() {
        clear();
        delete[] list;
    }

    int AdjacencyList::insertVertex() {
        if (vCount < vSize) {
            return vCount++;
        }
        throw GraphError::TOO_MANY_VERTICES;
    }

    bool AdjacencyList::insertEdge(int from, int to, bool undirected) {
        if (from < 0 || from >= vCount || to < 0 || to >= vCount) {
            return false;
        }

        if (from == to && undirected) { // 두 번 삽입되는 현상 방지
            undirected = false;
        }

        ALNode* newNode = new (std::nothrow) ALNode[(undirected ? 2 : 1)];
        if (!newNode) {
            return false;
        }

        newNode[0].vertex = to;
        newNode[0].next = list[from];
        list[from] = &newNode[0];

        if (undirected) { // 무방향 그래프 (from -> to와 to -> from 모두 삽입)
            newNode[1].vertex = from;
            newNode[1].next = list[to];
            list[to] = &newNode[1];
        }

        return true;
    }

    bool AdjacencyList::hasVertex(int v) {
        if (v >= 0 && v < vCount) {
            return true;
        }
        return false;
    }

    bool AdjacencyList::hasEdge(int from, int to) {
        if (from < 0 || from >= vCount || to < 0 || to >= vCount) {
            return false;
        }

        ALNode* p = list[from];
        while (p) {
            if (p->vertex == to) {
                return true;
            }
            p = p->next;
        }
        return false;
    }

    void AdjacencyList::clear() {
        vCount = 0;
        for (int i = 0; i < vSize; i++) {
            ALNode* p = list[i];
            ALNode* removed;
            while (p) { // 연결된 노드 전부 삭제
                removed = p;
                p = p->next;
                delete removed;
            }
            list[i] = nullptr;
        }
    }

    void AdjacencyList::print() {
        using namespace std;

        cout << "AdjacencyList(vSize=" << vSize << ", vCount=" << vCount << ")" << endl;

        if (vCount) {
            for (int i = 0; i < vCount; i++) {
                ALNode* p = list[i];
                cout << i << " -> ";
                while (p) {
                    cout << p->vertex << " -> ";
                    p = p->next;
                }
                cout << "null" << endl;
            }
        }
        else {
            cout << "(empty)" << endl;
        }
    }
}

#endif
