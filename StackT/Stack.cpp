#include "Stack.hpp"

namespace Deun {
	template <typename T>
	Stack<T>::Stack(unsigned long size) {
		this->size = size;
		top = 0;
		elements = new (std::nothrow) T[size];

		if (!elements) {
			this->size = 0;
			throw StackError::STACK_ALLOCATE_FAILED;
		}
	}

	template <typename T>
	Stack<T>::~Stack() {
		delete[] elements;
	}

	template <typename T>
	bool Stack<T>::isFull() {
		return (top == size);
	}

	template <typename T>
	bool Stack<T>::isEmpty() {
		return (top == 0);
	}

	template <typename T>
	unsigned long Stack<T>::getSize() {
		return size;
	}

	template <typename T>
	unsigned long Stack<T>::getCount() {
		return top;
	}

	template <typename T>
	bool Stack<T>::push(T element) {
		if (isFull()) {
			return false;
		}

		elements[top++] = element;
		return true;
	}

	template <typename T>
	T Stack<T>::pop() {
		if (isEmpty()) {
			throw StackError::STACK_IS_EMPTY;
		}

		return elements[--top];
	}

	template <typename T>
	T Stack<T>::peek() {
		if (isEmpty()) {
			throw StackError::STACK_IS_EMPTY;
		}

		return elements[top - 1];
	}
}
