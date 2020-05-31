#include <iostream>
using namespace std;

#include "Stack.h"
using namespace Deun;

int main() {
    Stack<int>* stack = new Deun::LinkedListStack<int>;

    cout << boolalpha;

    cout << "isEmpty(): " << stack->isEmpty() << endl;
    cout << endl;
    cout << "push(1): " << stack->push(1) << endl;
    cout << "push(2): " << stack->push(2) << endl;
    cout << "push(3): " << stack->push(3) << endl;
    cout << "isFull(): " << stack->isFull() << endl;
    cout << "push(4): " << stack->push(4) << endl;
    cout << endl;
    cout << "pop(): " << stack->pop() << endl;
    cout << "pop(): " << stack->pop() << endl;
    cout << "pop(): " << stack->pop() << endl;

    try {
        cout << "pop(): " << stack->pop() << endl;
    }
    catch (StackError err) {
        cout << "pop(): ErrorCode " << (int)err << endl;
    }
	
    cout << "isEmpty(): " << stack->isEmpty() << endl;

    return 0;
}
