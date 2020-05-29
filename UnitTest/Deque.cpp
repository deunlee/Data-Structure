#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../Deque/Deque.cpp"

TEST_CLASS(Deque) {
public:

    TEST_METHOD(Basic) {
        Deun::Deque d(10);

        Assert::AreEqual(d.getSize(), 10U);
        Assert::AreEqual(d.getCount(), 0U);
        Assert::IsTrue(d.isEmpty());
        Assert::IsFalse(d.isFull());

        Assert::IsTrue(d.pushRear(1));
        Assert::IsTrue(d.pushFront(2));
        Assert::IsTrue(d.pushRear(3));

        Assert::AreEqual(d.getSize(), 10U);
        Assert::AreEqual(d.getCount(), 3U);
        Assert::IsFalse(d.isEmpty());
        Assert::IsFalse(d.isFull());

        Assert::AreEqual(d.peekFront(), 2);
        Assert::AreEqual(d.peekRear(), 3);
        Assert::AreEqual(d.popRear(), 3);
        Assert::AreEqual(d.popFront(), 2);
        Assert::AreEqual(d.popRear(), 1);

        Assert::AreEqual(d.getSize(), 10U);
        Assert::AreEqual(d.getCount(), 0U);
        Assert::IsTrue(d.isEmpty());
        Assert::IsFalse(d.isFull());
    }

    TEST_METHOD(TooManyPush) {
        Deun::Deque d(2);

        Assert::IsTrue(d.pushRear(1));
        Assert::IsTrue(d.pushRear(2));
        Assert::IsFalse(d.pushRear(3));
        Assert::AreEqual(d.popRear(), 2);
        Assert::AreEqual(d.popRear(), 1);

        Assert::IsTrue(d.pushFront(4));
        Assert::IsTrue(d.pushFront(5));
        Assert::IsFalse(d.pushFront(6));
        Assert::AreEqual(d.popFront(), 5);
        Assert::AreEqual(d.popFront(), 4);

        Assert::IsTrue(d.pushRear(7));
        Assert::IsTrue(d.pushFront(8));
        Assert::IsFalse(d.pushRear(9));
        Assert::IsFalse(d.pushFront(0));
        Assert::AreEqual(d.peekRear(), 7);
        Assert::AreEqual(d.peekFront(), 8);
    }

    TEST_METHOD(TooManyPop) {
        Deun::Deque d(2);

        Assert::IsTrue(d.pushRear(1));
        Assert::IsTrue(d.pushRear(2));
        Assert::AreEqual(d.popRear(), 2);
        Assert::AreEqual(d.popRear(), 1);
        Assert::ExpectException<Deun::DequeError>([&] { d.popRear(); });
        Assert::ExpectException<Deun::DequeError>([&] { d.popFront(); });

        Deun::DequeError errRear;
        try {
            d.popRear();
        }
        catch (Deun::DequeError err) {
            errRear = err;
        }

        Deun::DequeError errFront;
        try {
            d.popFront();
        }
        catch (Deun::DequeError err) {
            errFront = err;
        }

        if (errRear == Deun::DequeError::ELEMENT_NOT_FOUND &&
            errFront == Deun::DequeError::ELEMENT_NOT_FOUND) {
            return;
        }

        Assert::Fail();
    }

    TEST_METHOD(LikeStack) {
        Deun::Deque d(4);

        Assert::IsTrue(d.pushRear(1));
        Assert::IsTrue(d.pushRear(2));
        Assert::IsTrue(d.pushRear(3));
        Assert::IsTrue(d.pushRear(4));
        Assert::IsTrue(d.isFull());
        Assert::AreEqual(d.popRear(), 4);
        Assert::AreEqual(d.popRear(), 3);
        Assert::AreEqual(d.popRear(), 2);
        Assert::AreEqual(d.popRear(), 1);
        Assert::IsTrue(d.isEmpty());

        Assert::IsTrue(d.pushFront(5));
        Assert::IsTrue(d.pushFront(6));
        Assert::IsTrue(d.pushFront(7));
        Assert::IsTrue(d.pushFront(8));
        Assert::IsTrue(d.isFull());
        Assert::AreEqual(d.popFront(), 8);
        Assert::AreEqual(d.popFront(), 7);
        Assert::AreEqual(d.popFront(), 6);
        Assert::AreEqual(d.popFront(), 5);
        Assert::IsTrue(d.isEmpty());
    }

    TEST_METHOD(LikeQueue) {
        Deun::Deque d(4);

        Assert::IsTrue(d.pushRear(1));
        Assert::IsTrue(d.pushRear(2));
        Assert::IsTrue(d.pushRear(3));
        Assert::IsTrue(d.pushRear(4));
        Assert::IsTrue(d.isFull());
        Assert::AreEqual(d.popFront(), 1);
        Assert::AreEqual(d.popFront(), 2);
        Assert::AreEqual(d.popFront(), 3);
        Assert::AreEqual(d.popFront(), 4);
        Assert::IsTrue(d.isEmpty());

        Assert::IsTrue(d.pushFront(5));
        Assert::IsTrue(d.pushFront(6));
        Assert::IsTrue(d.pushFront(7));
        Assert::IsTrue(d.pushFront(8));
        Assert::IsTrue(d.isFull());
        Assert::AreEqual(d.popRear(), 5);
        Assert::AreEqual(d.popRear(), 6);
        Assert::AreEqual(d.popRear(), 7);
        Assert::AreEqual(d.popRear(), 8);
        Assert::IsTrue(d.isEmpty());
    }
};
