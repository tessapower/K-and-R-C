#include "CppUnitTest.h"

#include "strutils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntToMinWidthStringTests {
  TEST_CLASS(IntToMinWidthStringTests) {
  public:
    TEST_METHOD(itostrNoPad) {
      char nStr[64];
      itostr(0, nStr, 0);
      Assert::AreEqual(std::string{"0"}, std::string(nStr));

      itostr(1, nStr, 0);
      Assert::AreEqual(std::string{"1"}, std::string(nStr));

      itostr(-1, nStr, 0);
      Assert::AreEqual(std::string{"-1"}, std::string(nStr));
    }

    TEST_METHOD(itostrLessThanPad) {
      char nStr[64];
      itostr(123456, nStr, 10);
      Assert::AreEqual(std::string{"    123456"}, std::string(nStr));

      itostr(123, nStr, 4);
      Assert::AreEqual(std::string{" 123"}, std::string(nStr));

      itostr(-111, nStr, 5);
      Assert::AreEqual(std::string{" -111"}, std::string(nStr));

      itostr(-18747, nStr, 8);
      Assert::AreEqual(std::string{"  -18747"}, std::string(nStr));
    }

    TEST_METHOD(itostrMoreThanPad) {
      char nStr[64];
      itostr(1234, nStr, 4);
      Assert::AreEqual(std::string{"1234"}, std::string(nStr));

      itostr(19874827, nStr, 4);
      Assert::AreEqual(std::string{"19874827"}, std::string(nStr));

      itostr(-1118, nStr, 4);
      Assert::AreEqual(std::string{"-1118"}, std::string(nStr));
    }
  };
}
