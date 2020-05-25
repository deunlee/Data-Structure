#ifndef __DEUN_STACK__
#define __DEUN_STACK__

#include <new>

namespace Deun {
	enum class StackError {
		STACK_ALLOCATE_FAILED,
		STACK_IS_FULL,
		STACK_IS_EMPTY,
	};

	template <typename T>
	class Stack {
	private:
		T* elements;
		unsigned long size;
		unsigned long top;

	public:
		Stack(unsigned long size = 100);
		~Stack();

		bool isFull();
		bool isEmpty();

		unsigned long getSize();
		unsigned long getCount();

		bool push(T element);
		T pop();
		T peek();
	};
}

#endif
