#include "CppUnitTest.h"

#include "strutils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExpandTests {
  TEST_CLASS(ExpandTests) {
   public:
    TEST_METHOD(expandEmptyString){
      char in[] = "";
      char out[100];
      expand(in, out);
      Assert::AreEqual("", out);
    }

    TEST_METHOD(expandStringNoNotation) {
      char in[] = "hello world";
      char out[100];
      expand(in, out);
      Assert::AreEqual("hello world", out);
    }

    TEST_METHOD(expandStringNoValidNotation) {
      char in[] = "-h-el-lo w-or-l-d- 9-0 0-z a-a-";
      char out[100];
      char expected[] = "-h-el-lo w-or-l-d- 9-0 0-z a-a-";
      expand(in, out);
      Assert::AreEqual(expected, out);
    }

    TEST_METHOD(expandStringUppercasePartialAlphabet) {
      char in[] = "A-F G-L M-V W-X Y-Z";
      char out[100];
      char expected[] = "ABCDEF GHIJKL MNOPQRSTUV WX YZ";
      expand(in, out);
      Assert::AreEqual(expected, out);
    }

    TEST_METHOD(expandStringDigitsPartial) {
      char in[] = "0-1 1-5 5-9";
      char out[100];
      char expected[] = "01 12345 56789";
      expand(in, out);
      Assert::AreEqual(expected, out);
    }

    TEST_METHOD(expandStringDigits) {
      char in[] = "0-9";
      char out[100];
      char expected[] = "0123456789";
      expand(in, out);
      Assert::AreEqual(expected, out);
    }

    TEST_METHOD(expandStringMixedAlnum) {
      char in[] = "a-f0-9";
      char out[100];
      char expected[] = "abcdef0123456789";
      expand(in, out);
      Assert::AreEqual(expected, out);
    }

    TEST_METHOD(expandStringUppercaseWholeAlphabet) {
      char in[] = "A-Z";
      char out[100];
      char expected[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      expand(in, out);
      Assert::AreEqual(expected, out);
    }

    TEST_METHOD(expandStringLowercasePartialAlphabet){
      char in[] = "a-f-g-l m-v w-x-y-z";
      char out[100];
      char expected[] = "abcdefghijkl mnopqrstuv wxyz";
      expand(in, out);
      Assert::AreEqual(expected, out);
    }

    TEST_METHOD(expandStringLowercaseWholeAlphabet) {
      char in[] = "a-z";
      char out[100];
      char expected[] = "abcdefghijklmnopqrstuvwxyz";
      expand(in, out);
      Assert::AreEqual(expected, out);
    }

    TEST_METHOD(expandStringMixedCasePartialAlphabet) {
      char in[] = "A-L M-z";
      char out[100];
      char expected[] = "ABCDEFGHIJKL M-z";
      expand(in, out);
      Assert::AreEqual(expected, out);
    }

    TEST_METHOD(expandStringMixedCaseWholeAlphabet) {
      char in[] = "A-z";
      char out[100];
      char expected[] = "A-z";
      expand(in, out);
      Assert::AreEqual(expected, out);
    }
  };
}
