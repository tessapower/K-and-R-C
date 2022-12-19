#include "pch.h"
#include "CppUnitTest.h"

#include "strutils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StrNUtilsTests {
  TEST_CLASS(StrNUtilsTests) {
  public:
    //----------------------------------------------------------- strncopy --//
    TEST_METHOD(strncopy_nZero) {
      char s[20] = "hello";
      char t[] = ", world!";
      strncopy(s, t, 0);

      Assert::AreEqual(std::string{"hello"}, std::string{s});
    }

    TEST_METHOD(strncopy_nOne) {
      char s[20] = "hello";
      char t[] = "!";
      strncopy(s, t, 1);

      Assert::AreEqual(std::string{"!"}, std::string{s});
    }

    TEST_METHOD(strncopy_emptySrc) {
      char s[20] = "hello, world!";
      char t[] = "";
      strncopy(s, t, 1);

      Assert::AreEqual(std::string{""}, std::string{s});
    }

    TEST_METHOD(strncopy_emptyDest) {
      char s[20] = "";
      char t[] = "hello, world!";
      strncopy(s, t, 14);

      Assert::AreEqual(std::string{"hello, world!"}, std::string{s});
    }

    TEST_METHOD(strncopy_srcLongerThanDest) {
      char s[30] = "yo dawg";
      char t[] = "I heard you like strings";
      strncopy(s, t, 25);

      Assert::AreEqual(std::string{"I heard you like strings"}, std::string{s});
    }

    TEST_METHOD(strncopy_destLongerThanSrc) {
      char s[30] = "I heard you like strings";
      char t[] = "yo dawg";
      strncopy(s, t, 8);

      Assert::AreEqual(std::string{"yo dawg"}, std::string{s});
    }

    TEST_METHOD(strncopy_nLessThanSrc) {
      char s[40] = "yo dawg";
      char t[] = "I heard you like strings";
      strncopy(s, t, 11);

      Assert::AreEqual(std::string{"I heard you"}, std::string{s});
    }

    TEST_METHOD(strncopy_nMoreThanSrc) {
      char s[40] = "yo dawg";
      char t[] = "I heard you like strings";
      strncopy(s, t, 30);

      Assert::AreEqual(std::string{"I heard you like strings"}, std::string{s});
    }

    //--------------------------------------------------------- strnconcat --//

    TEST_METHOD(strnconcat_nZero) {
      char s[20] = "hello";
      char t[] = ", world!";
      strnconcat(s, t, 0);

      Assert::AreEqual(std::string{"hello"}, std::string{s});
    }

    TEST_METHOD(strnconcat_nOne) {
      char s[20] = "hello";
      char t[] = "!!";
      strnconcat(s, t, 1);

      Assert::AreEqual(std::string{"hello!"}, std::string{s});
    }

    TEST_METHOD(strnconcat_emptySrc) {
      char s[20] = "hello";
      char t[] = "";
      strnconcat(s, t, 1);

      Assert::AreEqual(std::string{"hello"}, std::string{s});
    }

    TEST_METHOD(strnconcat_emptyDest) {
      char s[20] = "";
      char t[] = "hello, world!";
      strnconcat(s, t, 14);

      Assert::AreEqual(std::string{"hello, world!"}, std::string{s});
    }

    TEST_METHOD(strnconcat_nLessThanSrc) {
      char s[40] = "yo dawg ";
      char t[] = "I heard you like strings";
      strnconcat(s, t, 11);

      Assert::AreEqual(std::string{"yo dawg I heard you"}, std::string{s});
    }

    TEST_METHOD(strnconcat_nMoreThanSrc) {
      char s[40] = "yo dawg ";
      char t[] = "I heard you like strings";
      strnconcat(s, t, 30);

      Assert::AreEqual(std::string{"yo dawg I heard you like strings"}, std::string{s});
    }

    //----------------------------------------------------------- strncomp --//

    TEST_METHOD(strncomp_nZero) {
      char s[] = "hello";
      char t[] = "world!";
      strncomp(s, t, 0);

      Assert::IsTrue(strncomp(s, t, 1) < 0);
    }

    TEST_METHOD(strncomp_nOneEqual) {
      char s[] = "hello";
      char t[] = "harrison";
      
      Assert::IsTrue(strncomp(s, t, 1) == 0);
    }

    TEST_METHOD(strncomp_nOneLessThan) {
      char s[] = "hello";
      char t[] = "world";

      Assert::IsTrue(strncomp(s, t, 1) < 0);
    }

    TEST_METHOD(strncomp_nOneGreaterThan) {
      char s[] = "foo";
      char t[] = "bar";

      Assert::IsTrue(strncomp(s, t, 1) > 0);
    }

    TEST_METHOD(strncomp_emptyVsEmpty) {
      char s[] = "";
      char t[] = "";

      Assert::IsTrue(strncomp(s, t, 1) == 0);
    }

    TEST_METHOD(strncomp_emptyVsNonempty) {
      char s[] = "";
      char t[] = "hello, world!";

      Assert::IsTrue(strncomp(s, t, 5) < 0);
    }

    TEST_METHOD(strncomp_NonemptyVsEmpty) {
      char s[] = "hello, world!";
      char t[] = "";

      Assert::IsTrue(strncomp(s, t, 5) > 0);
    }

    TEST_METHOD(strncomp_nLessThanSrc) {
      char s[] = "lorem ipsum";
      char t[] = "lorem muspi";

      Assert::IsTrue(strncomp(s, t, 6) == 0);
    }

    TEST_METHOD(strncomp_nMoreThanSrc) {
      char s[] = "lorem ipsum sit dolor amet";
      char t[] = "lorem muspi sit dolor tema";

      Assert::IsTrue(strncomp(s, t, 30) < 0);
    }

  };
}
