#ifndef __DEUN_DISJOINT_SET_HPP__
#define __DEUN_DISJOINT_SET_HPP__

#include "DisjointSet.h"

namespace Deun {
    DisjointSet::DisjointSet(int size) : size(size) {
        parents = new(std::nothrow) int[size];
        ranks   = new(std::nothrow) int[size];
        if (!parents || !ranks) {
            if (parents) delete[] parents;
            if (ranks)   delete[] ranks;
            throw DisjointSetError::MEMORY_ALLOCATION_FAILED;
        }
        clear();
    }

    DisjointSet::~DisjointSet() {
        delete[] parents;
        delete[] ranks;
    }
    
    inline bool DisjointSet::isInRange(int node) {
        return (node >= 0 && node < size);
    }

    inline void DisjointSet::swap(int& a, int& b) {
        int t = a;
        a = b;
        b = t;
    }

    int DisjointSet::find(int node) {
        if (!isInRange(node)) {
            throw DisjointSetError::OUT_OF_RANGE;
        }

        // 음수이면 서브 트리의 루트 노드이고, 값은 그 트리에 속한 총 노드의 개수이다.
        // (음수가 아니면 루트 노드의 인덱스를 가리킨다.)
        if (parents[node] < 0) return node; 

        // 루트 노드가 아닐 경우 재귀적으로 루트 노드를 찾고 업데이트한다.
        // 현재 노드도 업데이트해서 트리의 높이를 낮출 수 있다.
        return parents[node] = find(parents[node]); // 경로 압축 (path compression)
    }

    bool DisjointSet::merge(int nodeA, int nodeB) {
        if (!isInRange(nodeA) || !isInRange(nodeB)) return false;

        // 각 노드의 루트 노드를 찾는다.
        nodeA = find(nodeA);
        nodeB = find(nodeB);

        // 이미 같은 집합에 속하면 합칠 필요가 없다.
        if (nodeA == nodeB) return true; 

        // nodeA가 높이가 낮은 트리가 되도록 한다.
        if (ranks[nodeA] > ranks[nodeB]) swap(nodeA, nodeB); 

        // nodeB(높은 트리) 아래에 nodeA(낮은 트리)를 삽입한다.
        // 높은 트리에 낮은 트리를 넣으면 높이가 증가하지 않는다. (union-by-rank)
        // (단, nodeA와 nodeB의 높이가 같으면 1 증가)
        parents[nodeB] += parents[nodeA]; // 노드 개수 업데이트
        parents[nodeA] = nodeB; // 트리 삽입

        // 높이가 같으면 nodeB의 높이가 1 증가한다.
        if (ranks[nodeA] == ranks[nodeB]) ranks[nodeB]++;
        return true;
    }

    int DisjointSet::count(int node) {
        if (!isInRange(node)) {
            throw DisjointSetError::OUT_OF_RANGE;
        }

        // 서브 트리의 루트 노드에는 그 트리의 노드 개수가 음수로 저장되어 있다.
        return -parents[find(node)];
    }

    void DisjointSet::print() {
        using namespace std;
        cout << "DisjointSet(size=" << size << ")" << endl;
        for (int i = 0; i < size; i++) {
            cout << "  " << i;
            if (parents[i] < 0) {
                cout << " (root, count=" << -parents[i] << ")" << endl;
            }
            else {
                cout << " (parent=" << parents[i] << ")" << endl;
            }
        }
    }

    void DisjointSet::clear() {
        for (int i = 0; i < size; i++) {
            // 처음에는 모든 노드가 루트 노드이고, 각 서브 트리의 노드는 1개이다.
            parents[i] = -1;

            // 또한, 처음에는 모든 노드가 자식이 없으므로 랭크가 1이다.
            ranks[i] = 1;
        }
    }
}

#endif
