#include "CppUnitTest.h"
#include <string>
#include <cstdlib>

#include "strutils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntToStringNegativeTests {
  TEST_CLASS(IntToStringNegativeTests) {
   public:
    TEST_METHOD(itoaZero){
      char zero[10];
      itostr(0, zero);
      char expected[] = "0";
      Assert::AreEqual(std::string{expected}, std::string{zero});
    }

    TEST_METHOD(itoaPositive) {
      char number[50];
      itostr(78914800, number);
      char expected[] = "78914800";
      Assert::AreEqual(std::string{expected}, std::string{number});
    }

    TEST_METHOD(itoaNegative) {
      char number[50];
      itostr(-1298420, number);
      char expected[] = "-1298420";
      Assert::AreEqual(std::string{expected}, std::string{number});
    }

    TEST_METHOD(itoaLargestNegative) {
      char intmin[50];
      char expected[50];
      _itoa_s(INT_MIN, expected, 10); // Built-in itoa
      itostr(INT_MIN, intmin);
      Assert::AreEqual(std::string{expected}, std::string{intmin});
    }

    TEST_METHOD(itoaLargestPositive) {
      char intmax[50];
      char expected[50];
      _itoa_s(INT_MAX, expected, 10);  // Built-in itoa
      itostr(INT_MAX, intmax);
      Assert::AreEqual(std::string{expected}, std::string{intmax});
    }
  };
}
