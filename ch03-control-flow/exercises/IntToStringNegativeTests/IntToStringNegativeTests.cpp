#include "pch.h"
#include "CppUnitTest.h"
#include <string>
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
      Assert::AreEqual(std::string{expected}, std::string{zero});
    }

    TEST_METHOD(itoaPositive) {
      char number[50];
      itoa2(78914800, number);
      char expected[] = "78914800";
      Assert::AreEqual(std::string{expected}, std::string{number});
    }

    TEST_METHOD(itoaNegative) {
      char number[50];
      itoa2(-1298420, number);
      char expected[] = "-1298420";
      Assert::AreEqual(std::string{expected}, std::string{number});
    }

    TEST_METHOD(itoaLargestNegative) {
      char intmin[50];
      char expected[50];
      _itoa_s(INT_MIN, expected, 10); // Built-in itoa
      itoa2(INT_MIN, intmin);
      Assert::AreEqual(std::string{expected}, std::string{intmin});
    }

    TEST_METHOD(itoaLargestPositive) {
      char intmax[50];
      char expected[50];
      _itoa_s(INT_MAX, expected, 10);  // Built-in itoa
      itoa2(INT_MAX, intmax);
      Assert::AreEqual(std::string{expected}, std::string{intmax});
    }
  };
}
