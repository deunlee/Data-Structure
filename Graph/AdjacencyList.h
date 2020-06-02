#ifndef __DEUN_GRAPH_ADJ_LIST_H__
#define __DEUN_GRAPH_ADJ_LIST_H__

#include "Graph.h"

namespace Deun {
    typedef struct AdjacencyListNode {
        int vertex;
        struct AdjacencyListNode* next;
    } ALNode;

    /**
     * 인접 리스트 그래프 (연결 리스트 기반)
     */
    class AdjacencyList : public Graph {
    protected:
        int      vSize;  // 정점의 최대 개수 (메모리 할당량)
        int      vCount; // 정점의 개수
        ALNode** list;   // 연결 리스트 (포인터 배열)

    public:
        /**
         * 인접 리스트 생성자
         *
         * @param {int} vSize: 정점의 최대 개수
         * @throw {GraphError} 메모리 할당 오류
         */
        AdjacencyList(int vSize = 1000);

        /**
         * 인접 리스트 소멸자
         */
        ~AdjacencyList();
        
        /**
         * 정점을 삽입하고 삽입된 정점의 인덱스를 반환합니다.
         * 
         * @return {int} 삽입된 정점의 인덱스(0-based)
         * @throw  {GraphError} 정점 개수 초과 오류
         */
        int insertVertex();

        /**
         * 간선을 삽입하고 성공 여부를 반환합니다.
         * 간선은 from과 to를 연결하며 방향성이 있습니다.
         * undirected가 true인 경우에는 to와 from을 잇는 간선도 삽입합니다.
         * 
         * @param  {int}  from: 시작 정점 인덱스(0-based)
         * @param  {int}  to: 끝 정점 인덱스(0-based)
         * @param  {bool} undirected: 무방향 그래프 여부
         * @return {bool} 성공 여부
         */
        bool insertEdge(int from, int to, bool undirected = false);

        /**
         * 정점의 존재 여부를 반환합니다.
         * 
         * @param  {int}  v: 정점 인덱스(0-based)
         * @return {bool} 존재 여부
         */
        bool hasVertex(int v);

        /**
         * 간선의 존재 여부를 반환합니다.
         * 
         * @param  {int}  from: 시작 정점 인덱스(0-based)
         * @param  {int}  to: 끝 정점 인덱스(0-based)
         * @return {bool} 존재 여부
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
