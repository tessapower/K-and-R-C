#include "pch.h"
#include "CppUnitTest.h"
#include "getfloat.h"
#include "getch.h"

#include <limits>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GetFloatTests {
  TEST_CLASS(GetFloatTests) {
  public:
    TEST_METHOD_INITIALIZE(clearBuffer) {
      // Clear char buffer
      clearbuf();
    }

    TEST_METHOD(getfloat_nan) {
      ungets("zero  ");

      float pn;
      Assert::IsTrue(getfloat(&pn) == 0);
    }

    TEST_METHOD(getfloat_zero) {
      ungets("0  0.0  .0  ");

      float pn;
      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(0.0f, pn);

      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(0.0f, pn);

      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(0.0f, pn);
    }

    TEST_METHOD(getfloat_leadingZeroes) {
      ungets("001.5  ");

      float pn;
      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(1.5f, pn);
    }

    TEST_METHOD(getfloat_justSymbols) {
      ungets("  +  -  ");

      float pn;
      // plus sign
      Assert::IsTrue(getfloat(&pn) == 0);
      // minus sign
      Assert::IsTrue(getfloat(&pn) == 0);
    }

    TEST_METHOD(getfloat_one) {
      ungets("1  1.0  +1.0  ");

      float pn;
      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(1.0f, pn);
      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(1.0f, pn);
      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(1.0f, pn);
    }

    TEST_METHOD(getfloat_negone) {
      ungets("-1  -1.0 -1.  ");

      float pn;
      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(-1.0f, pn);
      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(-1.0f, pn);
      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(-1.0f, pn);
    }

    TEST_METHOD(getfloat_number) {
      ungets("1234.8  827.49  ");

      float pn;
      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(1234.8f, pn);
    }

    TEST_METHOD(getfloat_noFloatPart) {
      ungets("1234  827  ");

      float pn;
      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(1234.0f, pn);
    }

    TEST_METHOD(getfloat_negativeFloat) {
      ungets("-0.000238  -827.49  ");

      float pn;
      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(-0.000238f, pn);
    }

    TEST_METHOD(getfloat_ws) {
      ungets("     42.42     ");

      float pn;
      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(42.42f, pn);
    }

    TEST_METHOD(getfloat_repeatedCalls) {
      ungets("123.0 45.6 7.89  ");

      float pn;
      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(123.0f, pn);
      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(45.6f, pn);
      Assert::IsTrue(getfloat(&pn) > 0);
      Assert::AreEqual(7.89f, pn);
    }
  };
}
