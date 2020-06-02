#ifndef __DEUN_GRAPH_ALGORITHM_HPP__
#define __DEUN_GRAPH_ALGORITHM_HPP__

#include "Graph.hpp"

namespace Deun {
    void Graph::__dfs(int vertex, bool* visited) {
        visited[vertex] = true; // 방문
        std::cout << vertex << " -> ";
        for (int i = 0; i < vSize; i++) {

        }
    }

    bool Graph::dfs(int vertex) {
        bool* visited = new (std::nothrow) bool[vSize];
        if (!visited) {
            return false;
        }
        for (int i = 0; i < vSize; i++) {
            visited[i] = false;
        }

        __dfs(vertex, visited);

        delete[] visited;
        return true;
    }
}

#endif
