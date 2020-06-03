#ifndef __DEUN_ADJACENCY_LIST_GRAPH_H__
#define __DEUN_ADJACENCY_LIST_GRAPH_H__

#include "Graph.hpp"

namespace Deun {
    /**
     * 인접 리스트 노드
     */
    class AdjacencyListNode {
    public:
        int                vertex;
        AdjacencyListNode* next;
    };
    using ALNode = AdjacencyListNode;

    /**
     * 인접 리스트 그래프 (연결 리스트 기반)
     */
    class AdjacencyList : public Graph {
    protected:
        ALNode** list; // 연결 리스트 (포인터 배열)

    public:
        /**
         * 인접 리스트 생성자
         * @param vertices   정점의 최대 개수
         * @throw GraphError 메모리 할당 오류
         */
        AdjacencyList(int vertices = 100);

        /**
         * 인접 리스트 소멸자
         */
        ~AdjacencyList();

        /**
         * 간선을 삽입하고 성공 여부를 반환합니다.
         * 간선은 from과 to를 연결하며 방향성이 있습니다.
         * 단, undirected가 true인 경우에는 to와 from을 잇는 간선도 삽입합니다.
         * @param  from       시작 정점 인덱스
         * @param  to         끝 정점 인덱스
         * @param  undirected 무방향 그래프 여부
         */
        bool insertEdge(int from, int to, bool undirected = false);

        /**
         * 간선의 존재 여부를 반환합니다.
         * @param from 시작 정점 인덱스
         * @param to   끝 정점 인덱스
         */
        bool hasEdge(int from, int to);

        /**
         * 인접 행렬을 초기화합니다.
         */
        void clear();

        /**
         * 인접 행렬을 출력합니다.
         */
        void print();
    };
}

#endif
