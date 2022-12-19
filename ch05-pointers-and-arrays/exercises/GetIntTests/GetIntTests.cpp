#include "pch.h"
#include "CppUnitTest.h"

#include "getint.h"
#include "getch.h"

#include <limits>
#include <iostream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GetIntTests {
  TEST_CLASS(GetIntTests) {
  public:
    TEST_METHOD_INITIALIZE(clearBuffer) {
      // Clear char buffer
      clearbuf();
    }

    TEST_METHOD(getint_nan) {
      ungets("zero  ");

      int pn;
      Assert::IsTrue(getint(&pn) == 0);
    }

    TEST_METHOD(getint_zero) {
      ungets("0  ");

      int pn;
      Assert::IsTrue(getint(&pn) > 0);
      Assert::AreEqual(0, pn);
    }


    TEST_METHOD(getint_leadingZeroes) {
      ungets("001  ");

      int pn;
      Assert::IsTrue(getint(&pn) > 0);
      Assert::AreEqual(1, pn);
    }

    TEST_METHOD(getint_justSymbols) {
      ungets("  +  -  ");

      int pn;
      // plus sign
      Assert::IsTrue(getint(&pn) == 0);
      // minus sign
      Assert::IsTrue(getint(&pn) == 0);
    }

    TEST_METHOD(getint_one) {
      ungets("1  ");

      int pn;
      Assert::IsTrue(getint(&pn) > 0);
      Assert::AreEqual(1, pn);
    }

    TEST_METHOD(getint_negone) {
      ungets("-1  ");

      int pn;
      Assert::IsTrue(getint(&pn) > 0);
      Assert::AreEqual(-1, pn);
    }

    TEST_METHOD(getint_number) {
      ungets("12348  82749");

      int pn;
      Assert::IsTrue(getint(&pn) > 0);
      Assert::AreEqual(12348, pn);
    }

    TEST_METHOD(getint_ws) {
      ungets("     4242     ");

      int pn;
      Assert::IsTrue(getint(&pn) > 0);
      Assert::AreEqual(4242, pn);
    }

    TEST_METHOD(getint_repeatedCalls) {
      ungets("123 456 789  ");

      int pn;
      Assert::IsTrue(getint(&pn) > 0);
      Assert::AreEqual(123, pn);
      Assert::IsTrue(getint(&pn) > 0);
      Assert::AreEqual(456, pn);
      Assert::IsTrue(getint(&pn) > 0);
      Assert::AreEqual(789, pn);
    }

    TEST_METHOD(getint_intmax) {
      std::string str = std::to_string(INT_MAX);
      str += "  ";
      ungets(str.c_str());

      int pn;
      Assert::IsTrue(getint(&pn) > 0);
      Assert::AreEqual(INT_MAX, pn);
    }

    TEST_METHOD(getint_intmin) {
      std::string str = std::to_string(INT_MIN);
      str += "  ";
      ungets(str.c_str());

      int pn;
      Assert::IsTrue(getint(&pn) > 0);
      Assert::AreEqual(INT_MIN, pn);
    }
  };
}
