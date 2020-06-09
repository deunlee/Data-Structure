#ifndef __DEUN_DISJOINT_SET_H__
#define __DEUN_DISJOINT_SET_H__

#include <iostream>
#include <new>

namespace Deun {
    /**
     * 서로소 집합 (배열 기반)
     */
    class DisjointSet {
    private:
        int  size;
        int* parents;
        int* ranks;

        inline bool isInRange(int node);
        inline void swap(int& a, int& b);
        
    public:
        /**
         * 서로소 집합 생성자
         * @param size 서로소 집합의 최대 크기
         * @throw 메모리 할당 오류
         */
        DisjointSet(int size = 1000);

        /**
         * 서로소 집합 소멸자
         */
        ~DisjointSet();

        /**
         * 주어진 노드가 속한 집합을 반환합니다.
         * @param node 노드
         * @throw 범위 오류
         */
        int find(int node);

        /**
         * 주어진 두 노드가 같은 집합에 속하도록 조정하고 성공 여부를 반환합니다.
         * @param nodeA 첫 번째 노드
         * @param nodeA 두 번째 노드
         */
        bool merge(int nodeA, int nodeB);

        /**
         * 주어진 노드가 속한 집합의 노드 개수를 반환합니다.
         * @param node 노드
         * @throw 범위 오류
         */
        int count(int node);

        /**
         * 서로소 집합을 출력합니다.
         */
        void print();

        /**
         * 서로소 집합을 초기화합니다.
         */
        void clear();
    };

    /**
     * 서로소 집합 오류
     */
    enum class DisjointSetError {
        MEMORY_ALLOCATION_FAILED = 1000,
        OUT_OF_RANGE,
    };
}

#include "DisjointSet.hpp"

#endif
