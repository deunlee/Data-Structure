#include <iostream>
using namespace std;

#include "Deque.h"
using namespace Deun;

int main() {
    Deque d(5);
    int menu, value;

    d.clear();
    cout << boolalpha;

    while (1) {
        d.print();
        cout << "pushFront=1, pushRear=2, popFront=3, popRear=4 >>> ";
        cin >> menu;

        switch (menu) {
        case 1:
            cout << "value >>> ";
            cin >> value;
            cout << "pushFront(" << value << "): " << d.pushFront(value) << endl;
            break;

        case 2:
            cout << "value >>> ";
            cin >> value;
            cout << "pushRear(" << value << "): " << d.pushRear(value) << endl;
            break;

        case 3:
            try {
                cout << "popFront(): " << d.popFront() << endl;
            }
            catch (DequeError err) {
                cout << "popFront(): Error Code " << (int)err << endl;
            }
            break;

        case 4:
            try {
                cout << "popRear(): " << d.popRear() << endl;
            }
            catch (DequeError err) {
                cout << "popRear(): Error Code " << (int)err << endl;
            }
            break;
        }

        cout << endl;
    }

    return 0;
}
