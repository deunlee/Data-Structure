#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../Stack/Stack.h"
#include "../Stack/Stack.cpp"

TEST_CLASS(Stack) {
public:

    TEST_METHOD(Basic) {
        Deun::Stack s(10);

        Assert::AreEqual(s.getSize(), 10U);
        Assert::AreEqual(s.getCount(), 0U);
        Assert::IsTrue(s.isEmpty());
        Assert::IsFalse(s.isFull());

        Assert::IsTrue(s.push(1));
        Assert::IsTrue(s.push(2));
        Assert::IsTrue(s.push(3));

        Assert::AreEqual(s.getSize(), 10U);
        Assert::AreEqual(s.getCount(), 3U);
        Assert::IsFalse(s.isEmpty());
        Assert::IsFalse(s.isFull());

        Assert::AreEqual(s.pop(), 3);
        Assert::AreEqual(s.pop(), 2);
        Assert::AreEqual(s.pop(), 1);

        Assert::AreEqual(s.getSize(), 10U);
        Assert::AreEqual(s.getCount(), 0U);
        Assert::IsTrue(s.isEmpty());
        Assert::IsFalse(s.isFull());
    }

    TEST_METHOD(TooManyPush) {
        Deun::Stack s(2);

        Assert::IsTrue(s.push(1));
        Assert::IsTrue(s.push(2));
        Assert::IsFalse(s.push(3));
    }

    TEST_METHOD(TooManyPop) {
        Deun::Stack s(2);

        Assert::IsTrue(s.push(1));
        Assert::IsTrue(s.push(2));
        Assert::AreEqual(s.pop(), 2);
        Assert::AreEqual(s.pop(), 1);
        Assert::ExpectException<Deun::StackError>([&] { s.pop(); });

        try {
            s.pop();
        }
        catch (Deun::StackError err) {
            if (err == Deun::StackError::STACK_IS_EMPTY) {
                return;
            }
        }

        Assert::Fail();
    }

    TEST_METHOD(Peek) {
        Deun::Stack s(2);

        Assert::IsTrue(s.push(1));
        Assert::IsTrue(s.push(2));

        Assert::AreEqual(s.peek(), 2);
        Assert::AreEqual(s.pop(), 2);
        Assert::AreEqual(s.peek(), 1);
        Assert::AreEqual(s.pop(), 1);

        Assert::ExpectException<Deun::StackError>([&] { s.peek(); });
    }

    TEST_METHOD(Cycle) {
        Deun::Stack s(3);

        for (int i = 0; i < 10; i++) {
            Assert::IsTrue(s.push(1));
            Assert::IsTrue(s.push(2));
            Assert::IsTrue(s.push(3));
            Assert::AreEqual(s.getCount(), 3U);
            Assert::IsFalse(s.isEmpty());
            Assert::IsTrue(s.isFull());
            Assert::AreEqual(s.pop(), 3);
            Assert::AreEqual(s.pop(), 2);
            Assert::AreEqual(s.pop(), 1);
            Assert::AreEqual(s.getCount(), 0U);

            Assert::IsTrue(s.push(4));
            Assert::AreEqual(s.getCount(), 1U);
            Assert::AreEqual(s.peek(), 4);
            Assert::IsTrue(s.push(5));
            Assert::AreEqual(s.getCount(), 2U);
            Assert::AreEqual(s.pop(), 5);
            Assert::IsTrue(s.push(6));
            Assert::AreEqual(s.getCount(), 2U);
            Assert::AreEqual(s.pop(), 6);
            Assert::IsTrue(s.push(7));
            Assert::AreEqual(s.pop(), 7);
            Assert::AreEqual(s.getCount(), 1U);
            Assert::AreEqual(s.pop(), 4);
            Assert::IsTrue(s.push(8));
            Assert::AreEqual(s.pop(), 8);
            Assert::IsTrue(s.isEmpty());
            Assert::IsFalse(s.isFull());
        }
    }
};
