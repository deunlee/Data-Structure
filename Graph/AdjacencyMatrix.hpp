#ifndef __DEUN_ADJACENCY_MATRIX_GRAPH_HPP__
#define __DEUN_ADJACENCY_MATRIX_GRAPH_HPP__

#include "AdjacencyMatrix.h"

namespace Deun {
    AdjacencyMatrix::AdjacencyMatrix(int vertices) : Graph(vertices) {
        if (vertices <= 0) {
            throw GraphError::MEMORY_ALLOCATION_FAILED;
        }
        matrix = new(std::nothrow) bool[(unsigned int)vertices * (unsigned int)vertices];
        if (!matrix) {
            throw GraphError::MEMORY_ALLOCATION_FAILED;
        }
        clear();
    }

    AdjacencyMatrix::~AdjacencyMatrix() {
        delete[] matrix;
    }

    inline bool AdjacencyMatrix::getRaw(int from, int to) {
        return matrix[from * vertices + to];
    }

    inline void AdjacencyMatrix::setRaw(int from, int to, bool value) {
        matrix[from * vertices + to] = value;
    }

    bool AdjacencyMatrix::insertEdge(int from, int to, bool undirected) {
        if (from < 0 || from >= vertices || to < 0 || to >= vertices) {
            return false;
        }
        setRaw(from, to, true);
        if (undirected) { // 무방향 그래프 (from -> to와 to -> from 모두 삽입)
            setRaw(to, from, true);
        }
        return true;
    }

    bool AdjacencyMatrix::hasEdge(int from, int to) {
        if (from < 0 || from >= vertices || to < 0 || to >= vertices) {
            return false;
        }
        return getRaw(from, to);
    }

    void AdjacencyMatrix::clear() {
        for (unsigned int i = 0; i < (unsigned int)vertices * (unsigned int)vertices; i++) {
            matrix[i] = 0;
        }
    }

    void AdjacencyMatrix::print() {
        using namespace std;
        cout << "AdjacencyMatrix(vertices=" << vertices << ")" << endl;
        if (!vertices) {
            cout << "(empty)" << endl;
            return;
        }
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << (int)getRaw(i, j) << " ";
            }
            cout << endl;
        }
    }

    void AdjacencyMatrix::__dfs(int vertex, bool* visited) {
        using namespace std;
        visited[vertex] = true; // 방문
        cout << vertex << " -> ";
        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && getRaw(vertex, i)) {
                __dfs(i, visited);
            }
        }
    }

    bool AdjacencyMatrix::dfs(int vertex) {
        if (vertex < 0 || vertex >= vertices) {
            return false;
        }
        bool* visited = new(std::nothrow) bool[vertices];
        if (!visited) {
            return false;
        }
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }
        __dfs(vertex, visited);
        std::cout << "(end)" << endl;
        delete[] visited;
        return true;
    }
}

#endif
