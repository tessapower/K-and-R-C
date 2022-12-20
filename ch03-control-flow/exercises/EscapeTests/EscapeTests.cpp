#include "pch.h"
#include "CppUnitTest.h"

#include <string>

extern "C" {
  #include "strutils.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EscapeTests {
  TEST_CLASS(EscapeTests) {
   public:
    TEST_METHOD(escapeEmptyString) {
      char t[] = "";
      char s[10];
      escape(s, t);

      Assert::AreEqual(std::string{t}, std::string{""});
      Assert::AreEqual(std::string{s}, std::string{""});
    }

    TEST_METHOD(escapeString) {
      char t[] = "Hello,\aworld\t!\vHere\'s a\bstring with lots of \"escaped chars\"\r\n";
      char s[100];
      escape(s, t);

      Assert::AreEqual(std::string{s}, std::string{"Hello,\\aworld\\t!\\vHere\\'s a\\bstring with lots of "
        "\\\"escaped chars\\\"\\r\\n"});
    }

    TEST_METHOD(escapeNoEscapedChars) {
      char t[] = "hello, world! this string has no escaped characters";
      char s[100];
      escape(s, t);

      Assert::AreEqual(std::string{s}, std::string{"hello, world! this string has no escaped characters"});
    }

    TEST_METHOD(unescapeEmptyString) {
      char t[] = "";
      char s[10];
      unescape(s, t);

      Assert::AreEqual(std::string{t}, std::string{""});
      Assert::AreEqual(std::string{s}, std::string{""});
    }

    TEST_METHOD(unescapeNoEscapedChars) {
      char t[] = "hello, world! this string has no unescaped characters";
      char s[100];
      unescape(s, t);

      Assert::AreEqual(std::string{s}, std::string{"hello, world! this string has no unescaped characters"});
    }

    TEST_METHOD(unescapeString) {
      char t[] = "Hello,\\aworld\\t!\\vHere\\'s a\\bstring with lots of \\\"escaped chars\\\"\\r\\n";
      char s[100];
      unescape(s, t);

      char expected[] =
          "Hello,\aworld\t!\vHere\'s a\bstring with lots of \"escaped "
          "chars\"\r\n";

      Assert::AreEqual(std::string{s}, std::string{expected});
    }
  };
}
