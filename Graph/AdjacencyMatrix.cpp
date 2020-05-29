#ifndef __DEUN_GRAPH_ADJ_MATRIX_CPP__
#define __DEUN_GRAPH_ADJ_MATRIX_CPP__

#include "AdjacencyMatrix.h"

namespace Deun {
    AdjacencyMatrix::AdjacencyMatrix(int vSize) {
        if (vSize <= 0) {
            this->vSize = 0;
            throw AdjacencyMatrixError::MEMORY_ALLOCATION_FAILED;
        }

        this->vSize = vSize;
        vCount = 0;
        matrix = new (std::nothrow) char[vSize * vSize];

        if (!matrix) {
            this->vSize = 0;
            throw AdjacencyMatrixError::MEMORY_ALLOCATION_FAILED;
        }
        
        clear();
    }

    AdjacencyMatrix::~AdjacencyMatrix() {
        delete[] matrix;
    }

    inline char AdjacencyMatrix::getRaw(int from, int to) {
        return matrix[from * vSize + to];
    }

    inline void AdjacencyMatrix::setRaw(int from, int to, char value) {
        matrix[from * vSize + to] = value;
    }

    int AdjacencyMatrix::insertVertex() {
        if (vCount < vSize) {
            return vCount++;
        }
        throw AdjacencyMatrixError::TOO_MANY_VERTICES;
    }

    bool AdjacencyMatrix::insertEdge(int from, int to, bool undirected) {
        if (from < 0 || from >= vCount || to < 0 || to >= vCount) {
            return false;
        }

        setRaw(from, to, 1);
        if (undirected) {
            setRaw(to, from, 1);
        }
        return true;
    }

    bool AdjacencyMatrix::hasVertex(int v) {
        if (v >= 0 && v < vCount) {
            return true;
        }
        return false;
    }

    bool AdjacencyMatrix::hasEdge(int from, int to) {
        if (from < 0 || from >= vCount || to < 0 || to >= vCount) {
            return false;
        }
        return getRaw(from, to);
    }

    void AdjacencyMatrix::clear() {
        for (unsigned int i = 0; i < (unsigned int)vSize * (unsigned int)vSize; i++) {
            matrix[i] = 0;
        }
    }

    void AdjacencyMatrix::print() {
        using namespace std;

        cout << "AdjacencyMatrix(vSize=" << vSize << ", vCount=" << vCount << ")" << endl;

        if (vCount) {
            for (int i = 0; i < vCount; i++) {
                for (int j = 0; j < vCount; j++) {
                    cout << (int)getRaw(i, j) << " ";
                }
                cout << endl;
            }
        }
        else {
            cout << "(empty)" << endl;
        }
    }
}

#endif
