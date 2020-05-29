#include <iostream>
using namespace std;

#include "AdjacencyMatrix.h"
using namespace Deun;

int main() {
    AdjacencyMatrix adjMatrix(5);
    int menu, value1, value2;

    cout << boolalpha;

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
            cout << ">>> insertEdge(" << value1 << ", " <<  value2 << "): ";
            cout << adjMatrix.insertEdge(value1, value2, true);
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
            continue;
        }

        cout << endl << "--------------------------------------------------" << endl;
    }

    return 0;
}
