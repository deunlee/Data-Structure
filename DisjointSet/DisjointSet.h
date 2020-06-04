#ifndef __DEUN_DISJOINT_SET_H__
#define __DEUN_DISJOINT_SET_H__

namespace Deun {
    /**
     * 서로소 집합 (배열 기반)
     */
    class DisjointSet {
    private:
        int* parents;

    public:
        /**
         * 서로소 집합 생성자
         */
        DisjointSet();

        /**
         * 서로소 집합 소멸자
         */
        ~DisjointSet();

        /**
         * 주어진 노드가 속한 집합을 반환합니다.
         * @param node 노드
         */
        int find(int node);

        /**
         * 주어진 두 노드가 같은 집합에 속하도록 조정합니다.
         * @param nodeA 첫 번째 노드
         * @param nodeA 두 번째 노드
         */
        void merge(int nodeA, int nodeB);

        /**
         * 서로소 집합을 출력합니다.
         */
        void print();

        /**
         * 서로소 집합을 초기화합니다.
         */
        void clear();
    };
}

#include "DisjointSet.hpp"

#endif
