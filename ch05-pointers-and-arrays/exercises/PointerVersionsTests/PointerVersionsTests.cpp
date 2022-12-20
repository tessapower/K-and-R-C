#include "pch.h"
#include "CppUnitTest.h"

#include "strutils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PointerVersionsTests {
  TEST_CLASS(PointerVersionsTests) {
  public:
    //---------------------------------------------- escape/unescape Tests --//
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

    //--------------------------------------------------------- stof Tests --//
    TEST_METHOD(stofEmpty) {
      Assert::AreEqual(0.0, stof(""));
    }

    TEST_METHOD(stofZero) {
      Assert::AreEqual(0.0, stof("0"));
      Assert::AreEqual(0.0, stof("0.0"));
      Assert::AreEqual(0.0, stof(".0"));
      Assert::AreEqual(0.0, stof(".0e0"));
      Assert::AreEqual(0.0, stof(".0e+0"));
      Assert::AreEqual(0.0, stof(".0e-0"));
      Assert::AreEqual(0.0, stof("0.0e-0"));
      Assert::AreEqual(0.0, stof("000000"));
    }

    TEST_METHOD(stofPosOne) {
      Assert::AreEqual(1.0, stof("1"));
      Assert::AreEqual(1.0, stof("1.0"));
      Assert::AreEqual(1.0, stof("1.0e0"));
      Assert::AreEqual(1.0, stof("1.0e+0"));
      Assert::AreEqual(1.0, stof("1.0e-0"));
      Assert::AreEqual(1.0, stof("000001"));
    }

    TEST_METHOD(stofNegOne) {
      Assert::AreEqual(-1.0, stof("-1"));
      Assert::AreEqual(-1.0, stof("-1.0"));
      Assert::AreEqual(-1.0, stof("-1.0e0"));
      Assert::AreEqual(-1.0, stof("-1.0e+0"));
      Assert::AreEqual(-1.0, stof("-1.0e-0"));
      Assert::AreEqual(-1.0, stof("-000001"));
    }

    TEST_METHOD(stofNoIntPart) {
      Assert::AreEqual(0.125, stof(".125"));
      Assert::AreEqual(0.00314159, stof(".00314159"));
      Assert::AreEqual(-0.125, stof("-.125"));
      Assert::AreEqual(-0.00314159, stof("-.00314159"));
    }

    TEST_METHOD(stofNoFractPart) {
      Assert::AreEqual(125.0, stof("125"));
      Assert::AreEqual(314159.0, stof("314159"));
      Assert::AreEqual(-125.0, stof("-125"));
      Assert::AreEqual(-314159.0, stof("-314159"));
    }

    TEST_METHOD(stofScientificWithInt) {
      Assert::AreEqual(123.0, stof("0.123e3"));
      Assert::AreEqual(123.0, stof("0.123e+3"));
      Assert::AreEqual(0.000123, stof("0.123e-3"));
    }

    TEST_METHOD(stofScientificNoInt) {
      Assert::AreEqual(3.14159, stof(".314159e1"));
      Assert::AreEqual(3.14159, stof(".314159e+1"));
      Assert::AreEqual(0.0314159, stof(".314159e-1"));
    }

    TEST_METHOD(stofScientificNoFract) {
      Assert::AreEqual(420000.0, stof("42e4"), 0.0001);
      Assert::AreEqual(420000.0, stof("42e+4"), 0.0001);
      Assert::AreEqual(0.0042, stof("42e-4"), 0.0001);
    }
  };
}
