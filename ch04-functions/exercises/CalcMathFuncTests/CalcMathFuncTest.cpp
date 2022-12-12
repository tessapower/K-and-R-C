#include "pch.h"
#include "CppUnitTest.h"
#include "calc.h"

#include <string>
#include <sstream>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalcMathFuncTests {
  TEST_CLASS(CalcMathFuncTests) {
   public:
    TEST_METHOD_INITIALIZE(clearBuffer) {
      // Clear char buffer
      clearbuf();
      // Clear stack
      clear();
    }

    //-------------------------------------------------------- getch Tests --//

    TEST_METHOD(getch_GetFromBuffer) {
      std::string str{ "hello, world!" };
      for (auto const& c : str) {
        ungetch(c);
      }

      auto len = str.length();
      for (auto i = 0; i < len; ++i) {
        int c = str.back();
        str.pop_back();
        Assert::AreEqual(c, getch());
      }
    }

    TEST_METHOD(peekch_PeekFromBuffer) {
      for (int const& c : "hello, world!") {
        ungetch(c);
        Assert::AreEqual(c, peekch());
      }
    }

    //-------------------------------------------------------- getop Tests --//

    TEST_METHOD(getop_Number) {
      // This stringstream will push backwards numbers on the stack
      // We add a few spaces at the beginning so there is always something on
      // the internal buffer
      std::stringstream stream{ "  3 42 1 17 124578 452 765 13445467 0 111111" };
      for (auto const& c : stream.str()) {
        ungetch(c);
      }

      // Reverse the string stream to get strings we can test against
      const std::istream_iterator<std::string> begin(stream);
      const std::istream_iterator<std::string> end;
      std::vector<std::string> tokens(begin, end);
      // Reverse each token
      for (auto& token : tokens) {
        std::reverse(token.begin(), token.end());
      }
      // Reverse the order of tokens
      std::reverse(tokens.begin(), tokens.end());

      char s[MAXOP];
      for (auto i = 0; i < tokens.size(); ++i) {
        char type = getop(s);
        Assert::IsTrue(type == NUMBER);
        Assert::AreEqual(tokens[i], std::string{ s });
      }
    }

    TEST_METHOD(getop_NegativeNumber) {
      // This stringstream will push backwards numbers on the stack
      // We add a few spaces at the beginning so there is always something on
      // the internal buffer
      std::stringstream stream{ "  0 42- 1- 17- 124578- 452- 765- 13445467- 111111-" };
      for (auto const& c : stream.str()) {
        ungetch(c);
      }

      // Reverse the string stream to get strings we can test against
      const std::istream_iterator<std::string> begin(stream);
      const std::istream_iterator<std::string> end;
      std::vector<std::string> tokens(begin, end);
      // Reverse each token
      for (auto& token : tokens) {
        std::reverse(token.begin(), token.end());
      }
      // Reverse the order of tokens
      std::reverse(tokens.begin(), tokens.end());

      char s[MAXOP];
      for (auto i = 0; i < tokens.size(); ++i) {
        char type = getop(s);
        Assert::IsTrue(type == NUMBER);
        Assert::AreEqual(tokens[i], std::string{ s });
      }
    }

    TEST_METHOD(getop_Float) {
      // This stringstream will push backwards numbers on the stack
      // We add a few spaces at the beginning so there is always something on
      // the internal buffer
      std::stringstream stream{ "  0.3 4.2 1.1 1.7 124.578 4.52 0.765 1.3445467 0.0 11.1111" };
      for (auto const& c : stream.str()) {
        ungetch(c);
      }

      // Reverse the string stream to get strings we can test against
      const std::istream_iterator<std::string> begin(stream);
      const std::istream_iterator<std::string> end;
      std::vector<std::string> tokens(begin, end);
      // Reverse each token
      for (auto& token : tokens) {
        std::reverse(token.begin(), token.end());
      }
      // Reverse the order of tokens
      std::reverse(tokens.begin(), tokens.end());

      char s[MAXOP];
      for (auto i = 0; i < tokens.size(); ++i) {
        char type = getop(s);
        Assert::IsTrue(type == NUMBER);
        Assert::AreEqual(tokens[i], std::string{ s });
      }
    }

    TEST_METHOD(getop_NegativeFloat) {
      // This stringstream will push backwards numbers on the stack
      // We add a few spaces at the beginning so there is always something on
      // the internal buffer
      std::stringstream stream{ "  4.2- 1.1- 1.7- 124.578- 4.52- 0.0765- 1.3445467- 11.1111-" };
      for (auto const& c : stream.str()) {
        ungetch(c);
      }

      // Reverse the string stream to get strings we can test against
      const std::istream_iterator<std::string> begin(stream);
      const std::istream_iterator<std::string> end;
      std::vector<std::string> tokens(begin, end);
      // Reverse each token
      for (auto& token : tokens) {
        std::reverse(token.begin(), token.end());
      }
      // Reverse the order of tokens
      std::reverse(tokens.begin(), tokens.end());

      char s[MAXOP];
      for (auto i = 0; i < tokens.size(); ++i) {
        char type = getop(s);
        Assert::IsTrue(type == NUMBER);
        Assert::AreEqual(tokens[i], std::string{ s });
      }
    }

    TEST_METHOD(getop_FloatNoIntPart) {
      // This stringstream will push backwards numbers on the stack
      // We add a few spaces at the beginning so there is always something on
      // the internal buffer
      std::stringstream stream{ "  3. 42. 1. 17. 124578. 452. 765. 13445467. 0. 111111." };
      for (auto const& c : stream.str()) {
        ungetch(c);
      }

      // Reverse the string stream to get strings we can test against
      const std::istream_iterator<std::string> begin(stream);
      const std::istream_iterator<std::string> end;
      std::vector<std::string> tokens(begin, end);
      // Reverse each token
      for (auto& token : tokens) {
        std::reverse(token.begin(), token.end());
      }
      // Reverse the order of tokens
      std::reverse(tokens.begin(), tokens.end());

      char s[MAXOP];
      for (auto i = 0; i < tokens.size(); ++i) {
        char type = getop(s);
        Assert::IsTrue(type == NUMBER);
        Assert::AreEqual(tokens[i], std::string{ s });
      }
    }

    TEST_METHOD(getop_FloatNoFractPart) {
      // This stringstream will push backwards numbers on the stack
      std::stringstream stream{ "  .3 .42 .1 .17 .124578 .452 .765 .13445467 .0 .111111" };
      for (auto const& c : stream.str()) {
        ungetch(c);
      }

      // Reverse the string stream to get strings we can test against
      const std::istream_iterator<std::string> begin(stream);
      const std::istream_iterator<std::string> end;
      std::vector<std::string> tokens(begin, end);
      // Reverse each token
      for (auto& token : tokens) {
        std::reverse(token.begin(), token.end());
      }
      // Reverse the order of tokens
      std::reverse(tokens.begin(), tokens.end());

      char s[MAXOP];
      for (auto i = 0; i < tokens.size(); ++i) {
        char type = getop(s);
        Assert::IsTrue(type == NUMBER);
        Assert::AreEqual(tokens[i], std::string{ s });
      }
    }

    TEST_METHOD(getop_AddOperator) {
      for (auto const& c : std::string{ "  3 2 +" }) {
        ungetch(c);
      }

      char s[MAXOP];
      Assert::IsTrue(getop(s) == ADD);
    }

    TEST_METHOD(getop_SubOperator) {
      for (auto const& c : std::string{ "  14 7 -" }) {
        ungetch(c);
      }

      char s[MAXOP];
      Assert::IsTrue(getop(s) == SUB);
    }

    TEST_METHOD(getop_MulOperator) {
      for (auto const& c : std::string{ "  2.1414 0.6 *" }) {
        ungetch(c);
      }

      char s[MAXOP];
      Assert::IsTrue(getop(s) == MUL);
    }

    TEST_METHOD(getop_DivOperator) {
      for (auto const& c : std::string{ "  3.14159 2.0 /" }) {
        ungetch(c);
      }

      char s[MAXOP];
      Assert::IsTrue(getop(s) == DIV);
    }

    TEST_METHOD(getop_ModOperator) {
      for (auto const& c : std::string{ "  50 4 %" }) {
        ungetch(c);
      }

      char s[MAXOP];
      Assert::IsTrue(getop(s) == MOD);
    }

    TEST_METHOD(getop_PowOperator) {
      for (auto const& c : std::string{ "  2 8 ^" }) {
        ungetch(c);
      }

      char s[MAXOP];
      Assert::IsTrue(getop(s) == POW);
    }

    TEST_METHOD(getop_ExpOperator) {
      for (auto const& c : std::string{ "  2 E" }) {
        ungetch(c);
      }

      char s[MAXOP];
      Assert::IsTrue(getop(s) == EXP);
    }

    TEST_METHOD(getop_SinOperator) {
      for (auto const& c : std::string{ "  3.14159 2 / ~" }) {
        ungetch(c);
      }

      char s[MAXOP];
      Assert::IsTrue(getop(s) == SIN);
    }

    TEST_METHOD(getop_ReturnsCharWhenUnknown) {
      for (auto const& c : std::string{ "  2 8 ^" }) {
        ungetch(c);
      }

      char s[MAXOP];
      char res = getop(s);
      Assert::AreEqual('^', res);
    }

    //-------------------------------------------------------- Stack Tests --//

    // Push
    TEST_METHOD(push_EmptyStack) {
      Assert::AreEqual(0.0, pop());
      Assert::IsTrue(push(3.14159));
    }

    TEST_METHOD(push_NonEmptyStack) {
      Assert::IsFalse(pop());

      for (auto i = 0; i < 20; ++i) {
        Assert::IsTrue(push(i));
      }
    }

    TEST_METHOD(push_FullStack) {
      Assert::AreEqual(0.0, pop());
      for (auto i = 0; i < 100; ++i) {
        Assert::IsTrue(push(i));
      }
      Assert::IsFalse(push(100));
    }

    // Pop
    TEST_METHOD(pop_EmptyStack) {
      Assert::AreEqual(0.0, pop());
      push(1.0);
      Assert::IsTrue(pop());
      Assert::IsFalse(pop());
    }

    TEST_METHOD(pop_NonEmptyStack) {
      Assert::AreEqual(0.0, pop());
      push(1.0);
      push(2.0);
      push(3.0);
      for (auto i = 0; i < 3; ++i) {
        Assert::IsTrue(pop());
      }
      Assert::IsFalse(pop());
    }

    TEST_METHOD(pop_FullStack) {
      Assert::AreEqual(0.0, pop());
      for (auto i = 0; i < 100; ++i) {
        Assert::IsTrue(push(i));
      }
      Assert::IsFalse(push(100));
      Assert::IsTrue(pop());
    }

    // Peek
    TEST_METHOD(peek_EmptyStack) {
      Assert::AreEqual(0.0, pop());
      Assert::AreEqual(0.0, peek());
    }

    TEST_METHOD(peek_NonEmptyStack) {
      Assert::AreEqual(0.0, pop());
      push(42.0);
      Assert::AreEqual(42.0, peek());
      Assert::AreEqual(42.0, pop());
    }

    TEST_METHOD(peek_FullStack) {
      Assert::AreEqual(0.0, pop());
      for (auto i = 0; i < 100; ++i) {
        Assert::IsTrue(push(i));
      }
      Assert::AreEqual(99.0, pop());
    }

    // Swap
    TEST_METHOD(swaptop_EmptyStack) {
      Assert::AreEqual(0.0, pop());
      Assert::IsFalse(swaptop());
    }

    TEST_METHOD(swaptop_NonEmptyStack) {
      Assert::AreEqual(0.0, pop());
      Assert::IsFalse(swaptop());

      push(1.0);
      push(2.0);

      Assert::IsTrue(swaptop());
      Assert::AreEqual(1.0, pop());
      Assert::AreEqual(2.0, pop());
      // Make sure it's empty
      Assert::AreEqual(0.0, pop());
    }

    // Duplicate
    TEST_METHOD(dup_EmptyStack) {
      Assert::AreEqual(0.0, pop());
      Assert::IsFalse(dup());
    }

    TEST_METHOD(dup_NonEmptyStack) {
      Assert::AreEqual(0.0, pop());
      Assert::IsFalse(swaptop());

      push(1.0);
      push(2.0);

      Assert::IsTrue(dup());
      Assert::AreEqual(2.0, pop());
      Assert::AreEqual(2.0, pop());
      Assert::AreEqual(1.0, pop());
      // Make sure it's empty
      Assert::AreEqual(0.0, pop());
    }
  };
}
