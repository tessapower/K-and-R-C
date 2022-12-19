#include "pch.h"
#include "CppUnitTest.h"

 #include "strend.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StrEndTests {
  TEST_CLASS(StrEndTests) {
  public:
    TEST_METHOD(strend_emptyEmpty) {
      // An empty string occurs at the end of an empty string
      char s[] = "";
      char t[] = "";

      Assert::AreEqual(1, strend(s, t));
    }

    TEST_METHOD(strend_emptyNonempty) {
      char s[] = "";
      char t[] = "hello";

      Assert::AreEqual(0, strend(s, t));
    }
    TEST_METHOD(strend_nonemptyEmpty) {
      // An empty string occurs at the end of a string
      char s[] = "hello";
      char t[] = "";

      Assert::AreEqual(1, strend(s, t));
    }

    TEST_METHOD(strend_noMatch) {
      char s[] = "well, hello";
      char t[] = "there";

      Assert::AreEqual(0, strend(s, t));
    }

    TEST_METHOD(strend_noMatchUppercase) {
      char s[] = "well, hello";
      char t[] = "HELLO";

      Assert::AreEqual(0, strend(s, t));
    }

    TEST_METHOD(strend_match) {
      char s[] = "hello";
      char t[] = "ello";

      Assert::AreEqual(1, strend(s, t));
    }

    TEST_METHOD(strend_multipleMatches) {
      char s[] = "hello hello";
      char t[] = "lo";

      Assert::AreEqual(1, strend(s, t));
    }
  };
}
