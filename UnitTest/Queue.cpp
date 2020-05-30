#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../Queue/Queue.cpp"

TEST_CLASS(Queue) {
public:

    TEST_METHOD(Basic) {
        Deun::Queue q(10);

        Assert::AreEqual(q.getSize(), 10U);
        Assert::AreEqual(q.getCount(), 0U);
        Assert::IsTrue(q.isEmpty());
        Assert::IsFalse(q.isFull());

        Assert::IsTrue(q.enqueue(1));
        Assert::IsTrue(q.enqueue(2));
        Assert::IsTrue(q.enqueue(3));

        Assert::AreEqual(q.getSize(), 10U);
        Assert::AreEqual(q.getCount(), 3U);
        Assert::IsFalse(q.isEmpty());
        Assert::IsFalse(q.isFull());

        Assert::AreEqual(q.dequeue(), 1);
        Assert::AreEqual(q.dequeue(), 2);
        Assert::AreEqual(q.dequeue(), 3);

        Assert::AreEqual(q.getSize(), 10U);
        Assert::AreEqual(q.getCount(), 0U);
        Assert::IsTrue(q.isEmpty());
        Assert::IsFalse(q.isFull());
    }

    TEST_METHOD(TooManyEnqueue) {
        Deun::Queue q(2);

        Assert::IsTrue(q.enqueue(1));
        Assert::IsTrue(q.enqueue(2));
        Assert::IsFalse(q.enqueue(3));
    }

    TEST_METHOD(TooManyDequeue) {
        Deun::Queue q(2);

        Assert::IsTrue(q.enqueue(1));
        Assert::IsTrue(q.enqueue(2));
        Assert::AreEqual(q.dequeue(), 1);
        Assert::AreEqual(q.dequeue(), 2);
        Assert::ExpectException<Deun::QueueError>([&] { q.dequeue(); });

        try {
            q.dequeue();
        }
        catch (Deun::QueueError err) {
            if (err == Deun::QueueError::ELEMENT_NOT_FOUND) {
                return;
            }
        }

        Assert::Fail();
    }

    TEST_METHOD(Peek) {
        Deun::Queue q(2);

        Assert::IsTrue(q.enqueue(1));
        Assert::IsTrue(q.enqueue(2));

        Assert::AreEqual(q.peek(), 1);
        Assert::AreEqual(q.dequeue(), 1);
        Assert::AreEqual(q.peek(), 2);
        Assert::AreEqual(q.dequeue(), 2);

        Assert::ExpectException<Deun::QueueError>([&] { q.peek(); });
    }

    TEST_METHOD(Cycle) {
        Deun::Queue q(3);

        for (int i = 0; i < 10; i++) {
            Assert::IsTrue(q.enqueue(1));
            Assert::IsTrue(q.enqueue(2));
            Assert::IsTrue(q.enqueue(3));
            Assert::AreEqual(q.getCount(), 3U);
            Assert::IsFalse(q.isEmpty());
            Assert::IsTrue(q.isFull());
            Assert::AreEqual(q.dequeue(), 1);
            Assert::AreEqual(q.dequeue(), 2);
            Assert::AreEqual(q.dequeue(), 3);
            Assert::AreEqual(q.getCount(), 0U);

            Assert::IsTrue(q.enqueue(4));
            Assert::AreEqual(q.getCount(), 1U);
            Assert::AreEqual(q.peek(), 4);
            Assert::IsTrue(q.enqueue(5));
            Assert::AreEqual(q.getCount(), 2U);
            Assert::AreEqual(q.dequeue(), 4);
            Assert::IsTrue(q.enqueue(6));
            Assert::AreEqual(q.getCount(), 2U);
            Assert::AreEqual(q.dequeue(), 5);
            Assert::IsTrue(q.enqueue(7));
            Assert::AreEqual(q.dequeue(), 6);
            Assert::AreEqual(q.getCount(), 1U);
            Assert::AreEqual(q.dequeue(), 7);
            Assert::IsTrue(q.enqueue(8));
            Assert::AreEqual(q.dequeue(), 8);
            Assert::IsTrue(q.isEmpty());
            Assert::IsFalse(q.isFull());
        }
    }
};
