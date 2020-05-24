#ifndef __DEUN_STACK__
#define __DEUN_STACK__

#include <new>

namespace Deun {
	enum class StackError {
		STACK_ALLOCATE_FAILED,
		STACK_IS_FULL,
		STACK_IS_EMPTY,
	};

	class Stack {
	private:
		int* elements;
		unsigned long size;
		unsigned long top;

	public:
		Stack(unsigned long size = 100);
		~Stack();

		bool isFull();
		bool isEmpty();

		unsigned long getSize();
		unsigned long getCount();

		bool push(int element);
		int pop();
		int peek();
	};
}

#endif
