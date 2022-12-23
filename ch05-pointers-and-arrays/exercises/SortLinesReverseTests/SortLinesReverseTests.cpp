#include "pch.h"
#include "CppUnitTest.h"

// Add the project for the library to test to references
// Include the root/includes dir of the project as additional includes
#include "sort.h"
#include "strutils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortLinesReverseTests {
  TEST_CLASS(SortLinesReverseTests) {
  public:
    TEST_METHOD(sort_empty) {
      char* lineptr[10] = {};
      bool numeric = false;
      bool reverse = false;

      // We run this simply to make sure we don't have any errors
      // if we give sort no input
      sort((void**)lineptr, 0, numeric, reverse);
    }

    TEST_METHOD(sort_numeric) {
      const int n = 10;
      char const * const expected[n] =
      {"0", "1", "2", "5", "6", "19", "42", "100", "888", "1993"};

      char const *lines[n] =
      {"42", "19", "0", "1", "2", "6", "5", "888", "100", "1993"};
      bool numeric = true;
      bool reverse = false;

      sort((void**)lines, n, numeric, reverse);

      for (int i = 0; i < n; ++i) {
        Assert::AreEqual(std::string{expected[i]}, std::string{lines[i]});
      }
    }

    TEST_METHOD(sort_lex) {
      const int n = 10;
      char const* const expected[n] =
      {"0", "1", "100", "19", "1993", "2", "42", "5", "6", "888"};

      char const* lines[n] =
      {"42", "19", "0", "1", "2", "6", "5", "888", "100", "1993" };
      bool numeric = false;
      bool reverse = false;

      sort((void**)lines, n, numeric, reverse);

      for (int i = 0; i < n; ++i) {
        Assert::AreEqual(std::string{expected[i]}, std::string{lines[i]});
      }
    }

    TEST_METHOD(sort_reverseNumeric) {
      const int n = 10;
      char const* const expected[n] =
      {"1993", "888", "100", "42", "19", "6", "5", "2", "1", "0"};

      char const* lines[n] =
      {"42", "19", "0", "1", "2", "6", "5", "888", "100", "1993"};
      bool numeric = true;
      bool reverse = true;

      sort((void**)lines, n, numeric, reverse);

      for (int i = 0; i < n; ++i) {
        Assert::AreEqual(std::string{expected[i]}, std::string{lines[i]});
      }
    }

    TEST_METHOD(sort_reverseLex) {
      const int n = 10;
      char const* const expected[n] =
      {"888", "6", "5", "42", "2", "1993", "19", "100", "1", "0"};

      char const* lines[n] =
      {"42", "19", "0", "1", "2", "6", "5", "888", "100", "1993"};
      bool numeric = false;
      bool reverse = true;

      sort((void**)lines, n, numeric, reverse);

      for (int i = 0; i < n; ++i) {
        Assert::AreEqual(std::string{expected[i]}, std::string{lines[i]});
      }
    }
  };
}
