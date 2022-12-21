#include "pch.h"
#include "CppUnitTest.h"
#include "expr.h"

#include <string>
#include <sstream>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExprTests {
  TEST_CLASS(ExprTests) {
  public:
    TEST_METHOD_INITIALIZE(clearBuffer) {
      clear();
    }

    TEST_METHOD(parse_invalidArg) {
      Assert::IsFalse(parse("x"));
      Assert::IsFalse(parse("+-"));
      Assert::IsFalse(parse("     "));
    }

    TEST_METHOD(parse_invalidState) {
      Assert::IsFalse(parse("+")); // No numbers on the stack

      Assert::IsTrue(parse("42"));
      Assert::IsFalse(parse("+")); // Not enough numbers on the stack
    }

    TEST_METHOD(parse_validArg) {
      Assert::IsTrue(parse("32"));
      Assert::IsTrue(parse("177.43292"));
      Assert::IsTrue(parse("+"));
      Assert::IsTrue(parse("12"));
      Assert::IsTrue(parse("-"));
      Assert::IsTrue(parse("1"));
      Assert::IsTrue(parse("*"));
      Assert::IsTrue(parse("-0.05"));
      Assert::IsTrue(parse("/"));
    }

    TEST_METHOD(parse_divisionByZero) {
      Assert::IsTrue(parse("123"));
      Assert::IsTrue(parse("0"));
      Assert::IsFalse(parse("/"));
    }

    TEST_METHOD(type_unknown) {
      Assert::IsTrue(type("hello") == UNKNOWN);
      Assert::IsTrue(type("+-*/") == UNKNOWN);
    }

    TEST_METHOD(type_number) {
      Assert::IsTrue(parse("0") == NUMBER);
      Assert::IsTrue(parse("0.0") == NUMBER);

      Assert::IsTrue(type("124.756") == NUMBER);
      Assert::IsTrue(type("-0.000005") == NUMBER);
      Assert::IsTrue(type("1234") == NUMBER);
    }

    TEST_METHOD(type_operator) {
      Assert::IsTrue(type("+") == OPERATOR);
      Assert::IsTrue(type("-") == OPERATOR);
      Assert::IsTrue(type("*") == OPERATOR);
      Assert::IsTrue(type("/") == OPERATOR);
    }

    TEST_METHOD(result_validExpr) {
      std::stringstream stream{"1 2 - 4 5 + *"};

      const std::istream_iterator<std::string> begin(stream);
      const std::istream_iterator<std::string> end;
      std::vector<std::string> args(begin, end);

      for (auto& arg : args) {
        Assert::IsTrue(parse(arg.c_str()));
      }

      double res;
      double expected = -9.0;
      Assert::IsTrue(result(&res));
      Assert::AreEqual(expected, res, 0.01);
    }

    TEST_METHOD(result_invalidExpr) {
      std::stringstream stream{ "1 2 - 4 5 +" };

      // Reverse the string stream to get strings we can test against
      const std::istream_iterator<std::string> begin(stream);
      const std::istream_iterator<std::string> end;
      std::vector<std::string> args(begin, end);

      for (auto& arg : args) {
        Assert::IsTrue(parse(arg.c_str()));
      }

      double res;
      double expected = 9.0;
      Assert::IsFalse(result(&res));
      Assert::AreEqual(9.0, res);
    }
  };
}
