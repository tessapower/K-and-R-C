#include "pch.h"
#include "CppUnitTest.h"

#include "sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortLinesCaseTests {
  TEST_CLASS(SortLinesCaseTests) {
  public:
    TEST_METHOD(sort_empty) {
      char* lineptr[10] = {};
      int options = 0x0000;

      // We run this simply to make sure we don't have any errors
      // if we give sort no input
      sort((void**)lineptr, 0, options);
    }

    TEST_METHOD(sort_numeric) {
      const int n = 10;
      char const * const expected[n] =
      {"0", "1", "2", "5", "6", "19", "42", "100", "888", "1993"};

      char const *lines[n] =
      {"42", "19", "0", "1", "2", "6", "5", "888", "100", "1993"};

      int options = 0x0000;
      options |= NUMERIC;

      sort((void**)lines, n, options);

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

      int options = 0x0000;

      sort((void**)lines, n, options);

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

      int options = 0x0000;
      options |= NUMERIC;
      options |= REVERSE;

      sort((void**)lines, n, options);

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

      int options = 0x0000;
      options |= REVERSE;

      sort((void**)lines, n, options);

      for (int i = 0; i < n; ++i) {
        Assert::AreEqual(std::string{expected[i]}, std::string{lines[i]});
      }
    }

    TEST_METHOD(sort_caseInsensitiveNumeric) {
      const int n = 10;
      char const* const expected[n] =
      { "0", "1", "2", "5", "6", "19", "42", "100", "888", "1993" };

      char const* lines[n] =
      { "42", "19", "0", "1", "2", "6", "5", "888", "100", "1993" };

      int options = 0x0000;
      options |= NUMERIC;
      options |= CASE_INSENSITIVE;

      sort((void**)lines, n, options);

      for (int i = 0; i < n; ++i) {
        Assert::AreEqual(std::string{expected[i]}, std::string{lines[i]});
      }
    }

    TEST_METHOD(sort_caseInsensitiveReverseNumeric) {
      const int n = 10;
      char const* const expected[n] =
      { "1993", "888", "100", "42", "19", "6", "5", "2", "1", "0" };

      char const* lines[n] =
      { "42", "19", "0", "1", "2", "6", "5", "888", "100", "1993" };

      int options = 0x0000;
      options |= NUMERIC;
      options |= REVERSE;
      options |= CASE_INSENSITIVE;

      sort((void**)lines, n, options);

      for (int i = 0; i < n; ++i) {
        Assert::AreEqual(std::string{expected[i]}, std::string{lines[i]});
      }
    }

    TEST_METHOD(sort_caseInsensitiveLex) {
      const int n = 10;
      char const* const expected[n] =
      { "000", "19", "abracadabra", "Alakazam", "bingo", "Cow", "edimame",
        "Foo", "int", "Zoo" };

      char const* lines[n] =
      { "bingo", "19", "Zoo", "Cow", "edimame", "abracadabra", "Foo",
        "int", "000", "Alakazam" };

      int options = 0x0000;
      options |= CASE_INSENSITIVE;

      sort((void**)lines, n, options);

      for (int i = 0; i < n; ++i) {
        Assert::AreEqual(std::string{expected[i]}, std::string{lines[i]});
      }
    }

    TEST_METHOD(sort_caseInsensitiveReverseLex) {
      const int n = 10;
      char const* const expected[n] =
      {"Zoo", "int", "Foo", "edimame", "Cow", "bingo", "Alakazam",
        "abracadabra", "19", "000"};

      char const* lines[n] =
      {"bingo", "19", "Zoo", "Cow", "edimame", "abracadabra", "Foo", 
        "int", "000", "Alakazam"};

      int options = 0x0000;
      options |= REVERSE;
      options |= CASE_INSENSITIVE;

      sort((void**)lines, n, options);

      for (int i = 0; i < n; ++i) {
        Assert::AreEqual(std::string{expected[i]}, std::string{lines[i]});
      }
    }
  };
}
