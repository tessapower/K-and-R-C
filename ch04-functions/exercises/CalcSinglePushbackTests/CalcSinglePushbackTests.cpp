#include "pch.h"
#include "CppUnitTest.h"
#include "calc.h"

#include <string>
#include <sstream>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalcSinglePushbackTests {
  TEST_CLASS(CalcSinglePushbackTests) {
   public:
    TEST_METHOD_INITIALIZE(clearBuffer) {
      // Clear char buffer
      clearbuf();
      // Clear stack
      clear();
    }

    //-------------------------------------------------------- getch Tests --//

    TEST_METHOD(getch_GetFromBuffer) {
      std::string str{ "hello, world!" };
      for (int const c : str) {
        Assert::IsTrue(ungetch(c));
        Assert::AreEqual(c, getch());
      }
    }

    TEST_METHOD(ungetch_MoreThanOne) {
      int c = 'c';
      int d = 'd';
      Assert::IsTrue(ungetch(c));
      Assert::IsFalse(ungetch(d));
      Assert::AreEqual(c, getch());
    }

    TEST_METHOD(peekch_PeekFromBuffer) {
      int c = 'c';
      Assert::IsTrue(ungetch(c));
      Assert::AreEqual(c, peekch());
      Assert::IsFalse(ungetch(c));
    }

    //-------------------------------------------------------- Stack Tests --//

    // Push
    TEST_METHOD(push_EmptyStack) {
      Assert::AreEqual(0.0, pop());
      Assert::IsTrue(push(3.14159));
    }

    TEST_METHOD(push_NonEmptyStack) {
      Assert::IsFalse(pop());

      for (auto i = 0; i < 20; ++i) {
        Assert::IsTrue(push(i));
      }
    }

    TEST_METHOD(push_FullStack) {
      Assert::AreEqual(0.0, pop());
      for (auto i = 0; i < 100; ++i) {
        Assert::IsTrue(push(i));
      }
      Assert::IsFalse(push(100));
    }

    // Pop
    TEST_METHOD(pop_EmptyStack) {
      Assert::AreEqual(0.0, pop());
      push(1.0);
      Assert::IsTrue(pop());
      Assert::IsFalse(pop());
    }

    TEST_METHOD(pop_NonEmptyStack) {
      Assert::AreEqual(0.0, pop());
      push(1.0);
      push(2.0);
      push(3.0);
      for (auto i = 0; i < 3; ++i) {
        Assert::IsTrue(pop());
      }
      Assert::IsFalse(pop());
    }

    TEST_METHOD(pop_FullStack) {
      Assert::AreEqual(0.0, pop());
      for (auto i = 0; i < 100; ++i) {
        Assert::IsTrue(push(i));
      }
      Assert::IsFalse(push(100));
      Assert::IsTrue(pop());
    }

    // Peek
    TEST_METHOD(peek_EmptyStack) {
      Assert::AreEqual(0.0, pop());
      Assert::AreEqual(0.0, peek());
    }

    TEST_METHOD(peek_NonEmptyStack) {
      Assert::AreEqual(0.0, pop());
      push(42.0);
      Assert::AreEqual(42.0, peek());
      Assert::AreEqual(42.0, pop());
    }

    TEST_METHOD(peek_FullStack) {
      Assert::AreEqual(0.0, pop());
      for (auto i = 0; i < 100; ++i) {
        Assert::IsTrue(push(i));
      }
      Assert::AreEqual(99.0, pop());
    }

    // Swap
    TEST_METHOD(swaptop_EmptyStack) {
      Assert::AreEqual(0.0, pop());
      Assert::IsFalse(swaptop());
    }

    TEST_METHOD(swaptop_NonEmptyStack) {
      Assert::AreEqual(0.0, pop());
      Assert::IsFalse(swaptop());

      push(1.0);
      push(2.0);

      Assert::IsTrue(swaptop());
      Assert::AreEqual(1.0, pop());
      Assert::AreEqual(2.0, pop());
      // Make sure it's empty
      Assert::AreEqual(0.0, pop());
    }

    // Duplicate
    TEST_METHOD(dup_EmptyStack) {
      Assert::AreEqual(0.0, pop());
      Assert::IsFalse(dup());
    }

    TEST_METHOD(dup_NonEmptyStack) {
      Assert::AreEqual(0.0, pop());
      Assert::IsFalse(swaptop());

      push(1.0);
      push(2.0);

      Assert::IsTrue(dup());
      Assert::AreEqual(2.0, pop());
      Assert::AreEqual(2.0, pop());
      Assert::AreEqual(1.0, pop());
      // Make sure it's empty
      Assert::AreEqual(0.0, pop());
    }
  };
}
