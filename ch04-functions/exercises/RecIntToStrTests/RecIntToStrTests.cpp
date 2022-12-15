#include "pch.h"
#include "CppUnitTest.h"
#include "../RecIntToStr/strutils.h"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RecIntToStrTests {
  TEST_CLASS(RecIntToStrTests) {
   public:
    TEST_METHOD(itostr_zero) {
      char s[10];
      int n = 0;
      itostr(n, s);
      Assert::AreEqual(std::to_string(n), std::string{s});
    }

    TEST_METHOD(itostr_one) {
      char s[10];
      int n = 1;
      itostr(n, s);
      Assert::AreEqual(std::to_string(n), std::string{s});
    }

    TEST_METHOD(itostr_negone) {
      char s[10];
      int n = -1;
      itostr(n, s);
      Assert::AreEqual(std::to_string(n), std::string{s});
    }

    TEST_METHOD(itostr_positive) {
      char s[10];
      int n = 78914800;
      itostr(n, s);
      Assert::AreEqual(std::to_string(n), std::string{s});
    }


    TEST_METHOD(itostr_negative) {
      char s[10];
      int n = -1298420;
      itostr(n, s);
      Assert::AreEqual(std::to_string(n), std::string{s});
    }

    TEST_METHOD(itostr_intmin) {
      char intmin[20];
      itostr(INT_MIN, intmin);
      Assert::AreEqual(std::to_string(INT_MIN), std::string{intmin});
    }

    TEST_METHOD(itostr_intmax) {
      char intmax[20];
      itostr(INT_MAX, intmax);
      Assert::AreEqual(std::to_string(INT_MAX), std::string{intmax});
    }
  };
}
