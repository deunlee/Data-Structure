#include <iostream>
using namespace std;

#include "Stack.h"
using namespace Deun;

int main() {
	Stack s(3);

	cout << boolalpha;

	cout << "isEmpty(): " << s.isEmpty() << endl;
	cout << endl;
	cout << "push(1): " << s.push(1) << endl;
	cout << "push(2): " << s.push(2) << endl;
	cout << "push(3): " << s.push(3) << endl;
	cout << "isFull(): " << s.isFull() << endl;
	cout << "push(4): " << s.push(4) << endl;
	cout << endl;
	cout << "pop(): " << s.pop() << endl;
	cout << "pop(): " << s.pop() << endl;
	cout << "pop(): " << s.pop() << endl;

	try {
		cout << "pop(): " << s.pop() << endl;
	}
	catch (StackError err) {
		cout << "pop(): ErrorCode " << (int)err << endl;
	}
	
	cout << "isEmpty(): " << s.isEmpty() << endl;

	return 0;
}
