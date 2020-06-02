#include <iostream>
using namespace std;

#include "Graph.h"
using namespace Deun;

int main() {
    Graph* graph = nullptr;
    int menu, value1, value2;

    cout << boolalpha;
    cout << "< Graph Playground >" << endl << endl;

    cout << ">>> Select graph type (AdjacencyMatrix=1, AdjacencyList=2) : ";
    cin >> menu;

    switch (menu) {
    case 1:
        graph = new AdjacencyMatrix(5);
        break;

    case 2:
        graph = new AdjacencyList(5);
        break;

    default:
        cout << ">>> Unknown type.";
        return 0;
    }

    cout << endl;

    while (1) {
        graph->print();
        cout << ">>> insertVertex=1, insertEdge=2, hasVertex=3, hasEdge=4, exit=5 : ";
        cin >> menu;

        switch (menu) {
        case 1:
            try {
                cout << ">>> insertVertex(): " << graph->insertVertex();
            }
            catch (GraphError err) {
                cout << ">>> insertVertex(): Error Code " << (int)err;
            }
            break;

        case 2:
            cout << ">>> from and to : ";
            cin >> value1 >> value2;
            cout << ">>> insertEdge(" << value1 << ", " << value2 << "): ";
            cout << graph->insertEdge(value1, value2);
            break;

        case 3:
            cout << ">>> index : ";
            cin >> value1;
            cout << ">>> hasVertex(" << value1 << "): " << graph->hasVertex(value1);
            break;

        case 4:
            cout << ">>> from and to : ";
            cin >> value1 >> value2;
            cout << ">>> hasEdge(" << value1 << ", " << value2 << "): ";
            cout << graph->hasEdge(value1, value2);
            break;

        case 5:
            cout << ">>> Exit..." << endl;
            delete graph;
            return 0;

        default:
            cout << ">>> Unknown command.";
        }

        cout << endl << "==================================================" << endl;
    }

    return 0;
}
