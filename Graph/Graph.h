#ifndef __DEUN_GRAPH_H__
#define __DEUN_GRAPH_H__

#include <iostream>
#include <new>

namespace Deun {
    /**
     * 그래프 인터페이스
     */
    class Graph {
    private:
        void __dfs(int vertex, bool* visited);

    protected:
        int vSize; // 정점 개수 (메모리 할당량)

    public:
        virtual int insertVertex() = 0;
        virtual bool insertEdge(int from, int to, bool undirected = false) = 0;

        virtual bool hasVertex(int v) = 0;
        virtual bool hasEdge(int from, int to) = 0;

        virtual void clear() = 0;
        virtual void print() = 0;

        bool dfs(int vertex);
    };

    /**
     * 그래프 오류
     */
    enum class GraphError {
        MEMORY_ALLOCATION_FAILED = 1000,
        TOO_MANY_VERTICES,
    };
}

#endif
