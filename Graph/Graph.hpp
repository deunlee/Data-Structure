#ifndef __DEUN_GRAPH_HPP__
#define __DEUN_GRAPH_HPP__

#include <iostream>
#include <new>

namespace Deun {
    /**
     * 그래프 인터페이스
     */
    class Graph {
    protected:
        int vertices; // 정점의 최대 개수 (메모리 할당량)

        Graph(int vertices) : vertices(vertices) { }

    public:
        virtual ~Graph() { }

        virtual bool insertEdge(int from, int to, bool undirected = false) = 0;
        virtual bool hasEdge(int from, int to) = 0;

        virtual void clear() = 0;
        virtual void print() = 0;

        virtual bool dfs(int vertex) {
            return false;
        }
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
