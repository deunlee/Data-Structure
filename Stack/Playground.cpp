#include <iostream>
using namespace std;

#include "Stack.h"
using namespace Deun;

class Point {
private:
    int x, y;

public:
    // Default Constructor
    Point() {
        x = y = 0;
        cout << "<DC-Point(0, 0)@" << this << ">";
    }

    // Parameterized Constructors
    Point(int x, int y) : x(x), y(y) {
        cout << "<PC-Point(" << x << ", " << y << ")@" << this << ">";
    }

    // Copy Constructor
    Point(const Point& ref) : x(ref.x), y(ref.y) {
        x = ref.x;
        y = ref.y;
        cout << "<CC-Point(" << x << ", " << y << ")@" << this << ">";
    }

    // Destructor
    ~Point() {
        //cout << endl;
        cout << "<D-Point(" << x << ", " << y << ")@" << this << ">";
    }

    int getX() { return x; }
    int getY() { return y; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    friend ostream& operator<<(ostream& os, const Point& obj) {
        os << "Point(" << obj.x << ", " << obj.y << ")@" << &obj;
        return os;
    }
};

using MyType = int;

int main() {
    Stack<MyType>* stack = nullptr;
    int menu, data;

    cout << boolalpha;
    cout << "< Stack Playground >" << endl << endl;

    cout << ">>> Select stack type (ArrayStack=1, LinkedListStack=2) : ";
    cin >> menu;

    switch (menu) {
    case 1:
        stack = new ArrayStack<MyType>(5);
        break;

    case 2:
        stack = new LinkedListStack<MyType>;
        break;

    default:
        cout << ">>> Unknown type.";
        return 0;
    }

    cout << endl;

    while (1) {
        stack->print();
        cout << ">>> push=1, pop=2, peek=3, exit=4 : ";
        cin >> menu;

        switch (menu) {
        case 1:
            cout << ">>> data : ";
            cin >> data;
            cout << ">>> push(" << data << "): " << stack->push(1);//Point(data, data*2)
            break;

        case 2:
            cout << ">>> pop(): ";
            try {
                cout << stack->pop();
            }
            catch (StackError err) {
                cout << "Error Code " << (int)err;
            }
            break;

        case 3:
            cout << ">>> peek(): ";
            try {
                cout << stack->peek();
            }
            catch (StackError err) {
                cout << "Error Code " << (int)err;
            }
            break;

        case 4:
            cout << ">>> Exit..." << endl;
            delete stack;
            while (1);
            return 0;

        default:
            cout << ">>> Unknown command.";
        }

        cout << endl << "==================================================" << endl;
    }

    return 0;
}
