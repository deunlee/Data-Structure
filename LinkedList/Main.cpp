#include <iostream>
using namespace std;

#include "LinkedList.h"
using namespace Deun;

int main() {
    LinkedList ll;
    int menu, menu2, value;
    unsigned int index;

    cout << boolalpha;

    while (1) {
        // MENU
        ll.print();
        cout << "insert=1, remove=2, get=3, update=4, find=5 >>> ";
        cin >> menu;
        switch (menu) {
        case 1:
            cout << "insertIndex=1, insertFront=2, insertRear=3 >>> ";
            break;
        case 2:
            cout << "removeIndex=1, removeFront=2, removeRear=3 >>> ";
            break;
        case 3:
            cout << "getIndex=1, getFront=2, getRear=3 >>> ";
            break;
        case 4:
            cout << "updateIndex=1, updateFront=2, updateRear=3 >>> ";
            break;
        case 5:
            break;
        }

        // INPUT
        switch (menu) {
        case 1: // insert
        case 4: // update
            cin >> menu2;
            switch (menu2) {
            case 1:
                cout << "index and value >>> ";
                cin >> index >> value;
                break;
            case 2:
            case 3:
                cout << "value >>> ";
                cin >> value;
                break;
            }
            break;

        case 2: // remove
        case 3: // get
            cin >> menu2;
            switch (menu2) {
            case 1:
                cout << "index >>> ";
                cin >> index;
                break;
            }
            break;

        case 5: // find
            cout << "value >>> ";
            cin >> value;
            break;
        }

        // EXECUTE
        try {
            switch (menu) {
            case 1: // insert
                switch (menu2) {
                case 1:
                    cout << "insert(" << index << ", " << value << "): " << ll.insert(index, value);
                    break;
                case 2:
                    cout << "insertFront(" << value << "): " << ll.insertFront(value);
                    break;
                case 3:
                    cout << "insertRear(" << value << "): " << ll.insertRear(value);
                    break;
                }
                break;

            case 2: // remove
                switch (menu2) {
                case 1:
                    cout << "remove(" << index << "): " << ll.remove(index);
                    break;
                case 2:
                    cout << "removeFront(): " << ll.removeFront();
                    break;
                case 3:
                    cout << "removeRear(): " << ll.removeRear();
                    break;
                }
                break;

            case 3: // get
                switch (menu2) {
                case 1:
                    cout << "get(" << index << "): ";
                    cout << ll.get(index);
                    break;
                case 2:
                    cout << "getFront(): ";
                    cout << ll.getFront();
                    break;
                case 3:
                    cout << "getRear(): ";
                    cout << ll.getRear();
                    break;
                }
                break;

            case 4: // update
                switch (menu2) {
                case 1:
                    cout << "update(" << index << ", " << value << "): " << ll.update(index, value);
                    break;
                case 2:
                    cout << "updateFront(" << value << "): " << ll.updateFront(value);
                    break;
                case 3:
                    cout << "updateRear(" << value << "): " << ll.updateRear(value);
                    break;
                }
                break;

            case 5: // find
                cout << "find(" << value << "): ";
                cout << ll.find(value);
                break;
            }
        }
        catch (LinkedListError err) {
            cout << "Error Code " << (int)err;
        }

        cout << endl << endl;
    }

    return 0;
}
