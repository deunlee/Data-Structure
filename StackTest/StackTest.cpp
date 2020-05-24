#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../Stack/Stack.h"
#include "../Stack/Stack.cpp"
using namespace Deun;

TEST_CLASS(UnitTest)
{
public:

	TEST_METHOD(Basic)
	{
		Stack s(10);

		Assert::AreEqual(s.getSize(), 10UL);
		Assert::AreEqual(s.getCount(), 0UL);
		Assert::IsTrue(s.isEmpty());
		Assert::IsFalse(s.isFull());
		
		Assert::IsTrue(s.push(1));
		Assert::IsTrue(s.push(2));
		Assert::IsTrue(s.push(3));

		Assert::AreEqual(s.getSize(), 10UL);
		Assert::AreEqual(s.getCount(), 3UL);
		Assert::IsFalse(s.isEmpty());
		Assert::IsFalse(s.isFull());

		Assert::AreEqual(s.pop(), 3);
		Assert::AreEqual(s.pop(), 2);
		Assert::AreEqual(s.pop(), 1);

		Assert::AreEqual(s.getSize(), 10UL);
		Assert::AreEqual(s.getCount(), 0UL);
		Assert::IsTrue(s.isEmpty());
		Assert::IsFalse(s.isFull());
	}

	TEST_METHOD(TooManyPush)
	{
		Stack s(2);

		Assert::IsTrue(s.push(1));
		Assert::IsTrue(s.push(2));

		Assert::IsFalse(s.push(3));
	}

	TEST_METHOD(TooManyPop)
	{
		Stack s(2);

		Assert::IsTrue(s.push(1));
		Assert::IsTrue(s.push(2));
		Assert::AreEqual(s.pop(), 2);
		Assert::AreEqual(s.pop(), 1);

		Assert::ExpectException<StackError>([&] { s.pop(); });

		try {
			s.pop();
		}
		catch (StackError err) {
			if (err == StackError::STACK_IS_EMPTY) {
				return;
			}
		}

		Assert::Fail();
	}

	TEST_METHOD(Peek)
	{
		Stack s(2);

		Assert::IsTrue(s.push(1));
		Assert::IsTrue(s.push(2));

		Assert::AreEqual(s.peek(), 2);
		Assert::AreEqual(s.pop(), 2);
		Assert::AreEqual(s.peek(), 1);
		Assert::AreEqual(s.pop(), 1);

		Assert::ExpectException<StackError>([&] { s.peek(); });
	}
};
