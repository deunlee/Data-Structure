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

    graph->insertEdge(0, 2, true);
    graph->insertEdge(0, 4, true);
    graph->insertEdge(1, 2, true);
    graph->insertEdge(2, 3, true);
    graph->dfs(0);
    cout << endl;

    while (1) {
        graph->print();
        cout << ">>> insertEdge=1, hasEdge=2, exit=3 : ";
        cin >> menu;

        switch (menu) {
        case 1:
            cout << ">>> from and to : ";
            cin >> value1 >> value2;
            cout << ">>> insertEdge(" << value1 << ", " << value2 << "): ";
            cout << graph->insertEdge(value1, value2);
            break;

        case 2:
            cout << ">>> from and to : ";
            cin >> value1 >> value2;
            cout << ">>> hasEdge(" << value1 << ", " << value2 << "): ";
            cout << graph->hasEdge(value1, value2);
            break;

        case 3:
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
