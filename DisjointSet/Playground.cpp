#include <iostream>
using namespace std;

#include "DisjointSet.h"
using namespace Deun;

int main() {
    DisjointSet dset(5);
    int menu, value1, value2;

    cout << boolalpha;
    cout << "< DisjointSet Playground >" << endl << endl;

    while (1) {
        dset.print();
        cout << ">>> find=1, union=2, count=3, exit=4 : ";
        cin >> menu;

        switch (menu) {
        case 1:
            cout << ">>> node : ";
            cin >> value1;
            cout << ">>> find(" << value1 << "): ";
            try {
                cout << dset.find(value1);
            }
            catch (DisjointSetError err) {
                cout << "Error Code " << (int)err;
            }
            break;

        case 2:
            cout << ">>> nodeA and nodeB : ";
            cin >> value1 >> value2;
            cout << ">>> merge(" << value1 << ", " << value2 << "): ";
            cout << dset.merge(value1, value2);
            break;

        case 3:
            cout << ">>> node : ";
            cin >> value1;
            cout << ">>> count(" << value1 << "): ";
            try {
                cout << dset.count(value1);
            }
            catch (DisjointSetError err) {
                cout << "Error Code " << (int)err;
            }
            break;

        case 4:
            cout << ">>> Exit..." << endl;
            return 0;

        default:
            cout << ">>> Unknown command.";
        }

        cout << endl << "==================================================" << endl;
    }

    return 0;
}
