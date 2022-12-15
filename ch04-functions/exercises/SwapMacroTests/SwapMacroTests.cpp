#include "pch.h"
#include "CppUnitTest.h"

#include "swap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SwapMacroTests {
  TEST_CLASS(SwapMacroTests) {
  public:
    TEST_METHOD(swap_char) {
      char x = 'a';
      char y = 'z';
      char t = 0;
      SWAP(t, x, y);
      Assert::AreEqual(x, 'z');
      Assert::AreEqual(y, 'a');
    }

    TEST_METHOD(swap_int) {
      int x = 1;
      int y = 0;
      int t = -1;
      SWAP(t, x, y);
      Assert::AreEqual(x, 0);
      Assert::AreEqual(y, 1);
    }

    TEST_METHOD(swap_double) {
      double x = 42.0;
      double y = 0.11;
      double t = -1.0;
      SWAP(t, x, y);
      Assert::AreEqual(x, 0.11);
      Assert::AreEqual(y, 42.0);
    }

    TEST_METHOD(swap_float) {
      float x = 3.14159f;
      float y = 99.999f;
      float t = -1.0f;
      SWAP(t, x, y);
      Assert::AreEqual(x, 99.999f);
      Assert::AreEqual(y, 3.14159f);
    }

    TEST_METHOD(swap_arrayElems) {
      int a[] = {2, 4, 6};
      int t = 0;
      SWAP(t, a[0], a[2]);
      Assert::AreEqual(6, a[0]);
      Assert::AreEqual(2, a[2]);
    }
  };
}
