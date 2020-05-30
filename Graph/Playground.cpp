#include <iostream>
using namespace std;

#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"
#include "Graph.h"
using namespace Deun;

void adjacencyMatrixPG() {
    AdjacencyMatrix adjMatrix(5);
    int menu, value1, value2;

    cout << boolalpha;
    cout << "< AdjacencyMatrix Playground >" << endl << endl;

    while (1) {
        adjMatrix.print();
        cout << ">>> insertVertex=1, insertEdge=2, hasVertex=3, hasEdge=4 : ";
        cin >> menu;

        switch (menu) {
        case 1:
            try {
                cout << ">>> insertVertex(): " << adjMatrix.insertVertex();
            }
            catch (AdjacencyMatrixError err) {
                cout << ">>> insertVertex(): Error Code " << (int)err;
            }
            break;

        case 2:
            cout << ">>> from and to : ";
            cin >> value1 >> value2;
            cout << ">>> insertEdge(" << value1 << ", " << value2 << "): ";
            cout << adjMatrix.insertEdge(value1, value2);
            break;

        case 3:
            cout << ">>> index : ";
            cin >> value1;
            cout << ">>> hasVertex(" << value1 << "): " << adjMatrix.hasVertex(value1);
            break;

        case 4:
            cout << ">>> from and to : ";
            cin >> value1 >> value2;
            cout << ">>> hasEdge(" << value1 << ", " << value2 << "): ";
            cout << adjMatrix.hasEdge(value1, value2);
            break;

        default:
            cout << ">>> unknown command";
        }

        cout << endl << "--------------------------------------------------" << endl;
    }
}

void adjacencyListPG() {
    AdjacencyList adjList(5);
    int menu, value1, value2;

    cout << boolalpha;
    cout << "< AdjacencyList Playground >" << endl << endl;

    while (1) {
        adjList.print();
        cout << ">>> insertVertex=1, insertEdge=2, hasVertex=3, hasEdge=4 : ";
        cin >> menu;

        switch (menu) {
        case 1:
            try {
                cout << ">>> insertVertex(): " << adjList.insertVertex();
            }
            catch (AdjacencyListError err) {
                cout << ">>> insertVertex(): Error Code " << (int)err;
            }
            break;

        case 2:
            cout << ">>> from and to : ";
            cin >> value1 >> value2;
            cout << ">>> insertEdge(" << value1 << ", " << value2 << "): ";
            cout << adjList.insertEdge(value1, value2);
            break;

        case 3:
            cout << ">>> index : ";
            cin >> value1;
            cout << ">>> hasVertex(" << value1 << "): " << adjList.hasVertex(value1);
            break;

        case 4:
            cout << ">>> from and to : ";
            cin >> value1 >> value2;
            cout << ">>> hasEdge(" << value1 << ", " << value2 << "): ";
            cout << adjList.hasEdge(value1, value2);
            break;

        default:
            cout << ">>> unknown command";
        }

        cout << endl << "--------------------------------------------------" << endl;
    }
}

int main() {
    //adjacencyMatrixPG();
    adjacencyListPG();

    return 0;
}
