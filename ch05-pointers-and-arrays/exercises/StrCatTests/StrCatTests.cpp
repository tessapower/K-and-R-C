#include "pch.h"
#include "CppUnitTest.h"

 #include "strcat.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StrCatTests {
  TEST_CLASS(StrCatTests) {
  public:
    TEST_METHOD(strconcat_emptyOntoEmpty) {
      char s[10] = "";
      char t[10] = "";

      strconcat(s, t);
      Assert::AreEqual(std::string{""}, std::string{s});
    }

    TEST_METHOD(strconcat_emptyOntoNonempty) {
      char s[20] = "hello";
      char t[10] = "";

      strconcat(s, t);
      Assert::AreEqual(std::string{"hello"}, std::string{s});
    }

    TEST_METHOD(strconcat_nonemptyOntoEmpty) {
      char s[20] = "";
      char t[] = "hello";

      strconcat(s, t);
      Assert::AreEqual(std::string{"hello"}, std::string{s});
    }

    TEST_METHOD(strconcat_twoStrings) {
      char s[20] = "hello";
      char t[] = ", world!";

      strconcat(s, t);
      Assert::AreEqual(std::string{"hello, world!"}, std::string{s});
    }
  };
}
