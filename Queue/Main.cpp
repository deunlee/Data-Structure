#include <iostream>
using namespace std;

#include "Queue.h"
using namespace Deun;

int main() {
    Queue q(3);

    cout << boolalpha;

    cout << "isEmpty(): " << q.isEmpty() << endl;
    cout << endl;
    cout << "enqueue(1): " << q.enqueue(1) << endl;
    cout << "enqueue(2): " << q.enqueue(2) << endl;
    cout << "enqueue(3): " << q.enqueue(3) << endl;
    cout << "isFull(): " << q.isFull() << endl;
    cout << "enqueue(4): " << q.enqueue(4) << endl;
    cout << endl;
    cout << "dequeue(): " << q.dequeue() << endl;
    cout << "dequeue(): " << q.dequeue() << endl;
    cout << "dequeue(): " << q.dequeue() << endl;

    try {
        cout << "dequeue(): " << q.dequeue() << endl;
    }
    catch (QueueError err) {
        cout << "dequeue(): ErrorCode " << (int)err << endl;
    }

    cout << "isEmpty(): " << q.isEmpty() << endl;
    cout << endl;

    cout << "enqueue(1): " << q.enqueue(1) << endl;
    cout << "enqueue(2): " << q.enqueue(2) << endl;
    cout << "dequeue(): " << q.dequeue() << endl;
    cout << "enqueue(3): " << q.enqueue(3) << endl;
    cout << "dequeue(): " << q.dequeue() << endl;
    cout << "enqueue(4): " << q.enqueue(4) << endl;
    cout << "enqueue(5): " << q.enqueue(5) << endl;
    cout << "dequeue(): " << q.dequeue() << endl;
    cout << "dequeue(): " << q.dequeue() << endl;
    cout << "enqueue(6): " << q.enqueue(6) << endl;
    cout << "dequeue(): " << q.dequeue() << endl;
    cout << "dequeue(): " << q.dequeue() << endl;
    cout << "isEmpty(): " << q.isEmpty() << endl;

    return 0;
}
