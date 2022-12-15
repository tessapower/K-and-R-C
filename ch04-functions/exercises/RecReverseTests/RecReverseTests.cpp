#include "pch.h"
#include "CppUnitTest.h"
#include "strutils.h"

#include <algorithm>
#include <string>
#include <cstring>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RecReverseTests {
  TEST_CLASS(RecReverseTests) {
  public:
    TEST_METHOD(recreverse_empty) {
      char s[] = "";
      std::string expected{ s };

      std::ranges::reverse(expected.begin(), expected.end());
      reverse(s);

      Assert::AreEqual(expected, std::string{s});
    }

    TEST_METHOD(recreverse_nonempty) {
      char s[] = "ABCDEF";
      std::string expected{s};

      std::ranges::reverse(expected.begin(), expected.end());
      reverse(s);

      Assert::AreEqual(expected, std::string{s});
    }

    TEST_METHOD(recreverse_evenLength) {
      char s[] = "lorem ipsum sit dolor amet";
      std::string expected{s};

      std::ranges::reverse(expected.begin(), expected.end());
      reverse(s);

      Assert::AreEqual(expected, std::string{s});
    }

    TEST_METHOD(recreverse_oddLength) {
      char s[] = "lorem ipsum sit dolor amet.";
      std::string expected{s};

      std::ranges::reverse(expected.begin(), expected.end());
      reverse(s);

      Assert::AreEqual(expected, std::string{s});
    }
  };
}
