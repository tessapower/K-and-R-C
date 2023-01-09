#include <limits.h>
#include <string>

#include "CppUnitTest.h"
#include "strutils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntToBaseStringTests {
  TEST_CLASS(IntToBaseStringTests) {
   public:
    TEST_METHOD(itobZero){
      constexpr int zero = 0;
      char zeroStr[8];
      const char expected[] = "0";

      // Binary
      itob(zero, zeroStr, 2);
      Assert::AreEqual(std::string(expected), std::string(zeroStr));

      // Octal
      itob(zero, zeroStr, 8);
      Assert::AreEqual(std::string(expected), std::string(zeroStr));

      // Decimal
      itob(zero, zeroStr, 10);
      Assert::AreEqual(std::string(expected), std::string(zeroStr));

      // Hex
      itob(zero, zeroStr, 16);
      Assert::AreEqual(std::string(expected), std::string(zeroStr));
    }

    TEST_METHOD(itobPositiveOneBin) {
      constexpr int n = 1;
      char nStr[64];
      itob(n, nStr, 2);

      char expectedBin[64];
      _itoa_s(n, expectedBin, 2);  // Built-in itoa

      Assert::AreEqual(std::string(expectedBin), std::string(nStr));
    }

    TEST_METHOD(itobNegativeOneBin) {
      constexpr int n = -1;
      char nStr[64];
      itob(n, nStr, 2);

      char expectedBin[64];
      _itoa_s(n, expectedBin, 2);  // Built-in itoa

      Assert::AreEqual(std::string(expectedBin), std::string(nStr));
    }

    TEST_METHOD(itobPositiveOneOct) {
      constexpr int n = 1;
      char nStr[64];
      itob(n, nStr, 8);

      char expectedBin[64];
      _itoa_s(n, expectedBin, 8);  // Built-in itoa

      Assert::AreEqual(std::string(expectedBin), std::string(nStr));
    }

    TEST_METHOD(itobNegativeOneOct) {
      constexpr int n = -1;
      char nStr[64];
      itob(n, nStr, 8);

      char expectedBin[64];
      _itoa_s(n, expectedBin, 8);  // Built-in itoa

      Assert::AreEqual(std::string(expectedBin), std::string(nStr));
    }

    TEST_METHOD(itobPositiveOneDec) {
      constexpr int n = 1;
      char nStr[64];
      itob(n, nStr, 10);

      char expectedBin[64];
      _itoa_s(n, expectedBin, 10);  // Built-in itoa

      Assert::AreEqual(std::string(expectedBin), std::string(nStr));
    }

    TEST_METHOD(itobNegativeOneDec) {
      constexpr int n = -1;
      char nStr[64];
      itob(n, nStr, 10);

      char expectedBin[64];
      _itoa_s(n, expectedBin, 10);  // Built-in itoa

      Assert::AreEqual(std::string(expectedBin), std::string(nStr));
    }

    TEST_METHOD(itobPositiveOneHex) {
      constexpr int n = 1;
      char nStr[64];
      itob(n, nStr, 16);

      char expectedBin[64];
      _itoa_s(n, expectedBin, 16);  // Built-in itoa

      Assert::AreEqual(std::string(expectedBin), std::string(nStr));
    }

    TEST_METHOD(itobNegativeOneHex) {
      constexpr int n = -1;
      char nStr[64];
      itob(n, nStr, 16);

      char expectedBin[64];
      _itoa_s(n, expectedBin, 16);  // Built-in itoa

      Assert::AreEqual(std::string(expectedBin), std::string(nStr));
    }

    TEST_METHOD(itobPositiveOneArbitraryBase) {
      constexpr int n = 1;
      char nStr[64];
      itob(n, nStr, 12);

      char expectedBin[64];
      _itoa_s(n, expectedBin, 12);  // Built-in itoa

      Assert::AreEqual(std::string(expectedBin), std::string(nStr));

      itob(n, nStr, 5);
      _itoa_s(n, expectedBin, 5);  // Built-in itoa

      Assert::AreEqual(std::string(expectedBin), std::string(nStr));
    }

    TEST_METHOD(itobPositiveIntMaxBin) {
      char nStr[64];
      itob(INT_MAX, nStr, 2);

      char expectedBin[64];
      _itoa_s(INT_MAX, expectedBin, 2);  // Built-in itoa

      Assert::AreEqual(std::string(expectedBin), std::string(nStr));
    }

    TEST_METHOD(itobPositiveUIntMaxBin) {
      char nStr[64];
      itob(INT_MAX, nStr, 2);

      char expectedBin[64];
      _itoa_s(INT_MAX, expectedBin, 2);  // Built-in itoa

      Assert::AreEqual(std::string(expectedBin), std::string(nStr));
    }

    TEST_METHOD(itobPositiveIntMaxDec) {
      char nStr[64];
      itob(INT_MAX, nStr, 10);

      char expectedBin[64];
      _itoa_s(INT_MAX, expectedBin, 10);  // Built-in itoa

      Assert::AreEqual(std::string(expectedBin), std::string(nStr));
    }

    TEST_METHOD(itobPositiveUIntMaxDec) {
      char nStr[64];
      itob(INT_MAX, nStr, 10);

      char expectedBin[64];
      _itoa_s(INT_MAX, expectedBin, 10);  // Built-in itoa

      Assert::AreEqual(std::string(expectedBin), std::string(nStr));
    }

    TEST_METHOD(itobPositive) {
      char nStr[64];
      constexpr int n = 78914800;

      // Binary
      itob(n, nStr, 2);
      char expectedBin[64];
      _itoa_s(n, expectedBin, 2); // Built-in itoa
      Assert::AreEqual(std::string(expectedBin), std::string(nStr));

      // Arbitrary
      itob(n, nStr, 5);
      char expectedArb[64];
      _itoa_s(n, expectedArb, 5); // Built-in itoa
      Assert::AreEqual(std::string(expectedArb), std::string(nStr));

      // Octal
      itob(n, nStr, 8);
      char expectedOct[64];
      _itoa_s(n, expectedOct, 8); // Built-in itoa
      Assert::AreEqual(std::string(expectedOct), std::string(nStr));

      // Decimal
      itob(n, nStr, 10);
      char expectedDec[64];
      _itoa_s(n, expectedDec, 10); // Built-in itoa
      Assert::AreEqual(std::string(expectedDec), std::string(nStr));

      // Hex
      itob(n, nStr, 16);
      char expectedHex[64];
      _itoa_s(n, expectedHex, 16); // Built-in itoa
      Assert::AreEqual(std::string(expectedHex), std::string(nStr));
    }

    TEST_METHOD(itobNegativeOne) {
      char nStr[64];
      constexpr int n = -1;

      // Binary
      itob(n, nStr, 2);
      char expectedBin[64];
      _itoa_s(n, expectedBin, 2);  // Built-in itoa
      Assert::AreEqual(std::string(expectedBin), std::string(nStr));
    }

    TEST_METHOD(itobNegative) {
      char nStr[64];
      constexpr int n = -1298420;

      // Binary
      itob(n, nStr, 2);
      char expectedBin[64];
      _itoa_s(n, expectedBin, 2); // Built-in itoa
      Assert::AreEqual(std::string(expectedBin), std::string(nStr));

      // Arbitrary
      itob(n, nStr, 12);
      char expectedArb[64];
      _itoa_s(n, expectedArb, 12); // Built-in itoa
      Assert::AreEqual(std::string(expectedArb), std::string(nStr));

      // Octal
      itob(n, nStr, 8);
      char expectedOct[64];
      _itoa_s(n, expectedOct, 8); // Built-in itoa
      Assert::AreEqual(std::string(expectedOct), std::string(nStr));

      // Decimal
      itob(n, nStr, 10);
      char expectedDec[64];
      _itoa_s(n, expectedDec, 10); // Built-in itoa
      Assert::AreEqual(std::string(expectedDec), std::string(nStr));

      // Hex
      itob(n, nStr, 16);
      char expectedHex[64];
      _itoa_s(n, expectedHex, 16); // Built-in itoa
      Assert::AreEqual(std::string(expectedHex), std::string(nStr));
    }
  };
}
