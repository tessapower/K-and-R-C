#include "pch.h"
#include "CppUnitTest.h"
 #include "strutils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StrToFloatTests {
  TEST_CLASS(StrToFloatTests) {
  public:
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
