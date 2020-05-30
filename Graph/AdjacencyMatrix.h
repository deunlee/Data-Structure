#ifndef __DEUN_GRAPH_ADJ_MATRIX_H__
#define __DEUN_GRAPH_ADJ_MATRIX_H__

#include <iostream>
#include <new>

namespace Deun {
    enum class AdjacencyMatrixError {
        MEMORY_ALLOCATION_FAILED = 1000,
        TOO_MANY_VERTICES,
    };

    /**
     * 인접 행렬 그래프 (배열 기반)
     */
    class AdjacencyMatrix {
    protected:
        int   vSize;  // 정점의 최대 개수 (메모리 할당량)
        int   vCount; // 정점의 개수
        char* matrix; // 인접 행렬

        inline bool getRaw(int from, int to);
        inline void setRaw(int from, int to, bool value);

    public:
        /**
         * 인접 행렬 생성자
         *
         * @param {int} vSize: 정점의 최대 개수
         * @throw {AdjacencyMatrixError} 메모리 할당 오류
         */
        AdjacencyMatrix(int vSize = 1000);

        /**
         * 인접 행렬 소멸자
         */
        ~AdjacencyMatrix();
        
        /**
         * 정점을 삽입하고 삽입된 정점의 인덱스를 반환합니다.
         * 
         * @return {int} 삽입된 정점의 인덱스(0-based)
         * @throw  {AdjacencyMatrixError} 정점 개수 초과 오류
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
