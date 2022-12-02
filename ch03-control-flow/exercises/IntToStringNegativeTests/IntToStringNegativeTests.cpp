#include "pch.h"
#include "CppUnitTest.h"
#include <cstdlib>

extern "C" {
  #include "strutils.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntToStringNegativeTests {
  TEST_CLASS(IntToStringNegativeTests) {
   public:
    TEST_METHOD(itoaZero){
      char zero[10];
      itoa2(0, zero);
      char expected[] = "0";
      Assert::AreEqual(expected, zero);
    }

    TEST_METHOD(itoaPositive) {
      char number[50];
      itoa2(78914800, number);
      char expected[] = "78914800";
      Assert::AreEqual(expected, number);
    }

    TEST_METHOD(itoaNegative) {
      char number[50];
      itoa2(-1298420, number);
      char expected[] = "-1298420";
      Assert::AreEqual(expected, number);
    }

    TEST_METHOD(itoaLargestNegative) {
      char intmin[50];
      char expected[50];
      _itoa_s(INT_MIN, expected, 10); // Built-in itoa
      itoa2(INT_MIN, intmin);
      Assert::AreEqual(expected, intmin);
    }

    TEST_METHOD(itoaLargestPositive) {
      char intmax[50];
      char expected[50];
      _itoa_s(INT_MAX, expected, 10);  // Built-in itoa
      itoa2(INT_MAX, intmax);
      Assert::AreEqual(expected, intmax);
    }
  };
}
