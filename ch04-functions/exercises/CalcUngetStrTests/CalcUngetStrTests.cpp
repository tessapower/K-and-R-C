#include "pch.h"
#include "CppUnitTest.h"
#include "calc.h"

#include <string>
#include <sstream>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalcUngetStrTests {
  TEST_CLASS(CalcUngetStrTests) {
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
        Assert::IsTrue(ungetch(c));
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
        Assert::IsTrue(ungetch(c));
        Assert::AreEqual(c, peekch());
      }
    }

    TEST_METHOD(ungetch_MoreThanMax) {
      for (int i = 0; i < 100; ++i) {
        Assert::IsTrue(ungetch('c'));
      }
      Assert::IsFalse(ungetch('c'));
    }

    TEST_METHOD(ungets_lessThanMax) {
      char s[] = "and another thing...!";
      ungets(s);

      Assert::IsTrue(ungetch('!'));
    }

    TEST_METHOD(ungets_correctOrdering) {
      char s[] = "and another thing...!";
      ungets(s);

      std::string str{ s };
      for (int const c : str) {
        Assert::AreEqual(c, getch());
      }
    }

    TEST_METHOD(ungets_moreThanMax) {
      char s[] = "This is a very, very, very, very, very, VERY long string. "
        "It's probably about 100 characters or so, by now.";
      ungets(s);

      Assert::IsFalse(ungetch('!'));
    }

    //-------------------------------------------------------- getop Tests --//

    //-------------------------------------------------------- getop Tests --//

    TEST_METHOD(getop_Number) {
      // We add a few spaces at the end so there is always something on
      // the internal buffer. This stops getch() going to stdin for input.
      std::stringstream stream{"0 3 42 117 1245 45228 765000 "
        "1344547 11111111  "};
      ungets(stream.str().data());

      const std::istream_iterator<std::string> begin(stream);
      const std::istream_iterator<std::string> end;
      std::vector<std::string> tokens(begin, end);

      char s[MAXOP];
      for (auto const& token : tokens) {
        char type = getop(s);
        Assert::IsTrue(type == NUMBER);
        Assert::AreEqual(token, std::string{s});
      }
    }

    TEST_METHOD(getop_NegativeInt) {
      // We add a few spaces at the end so there is always something on
      // the internal buffer. This stops getch() going to stdin for input.
      std::stringstream stream{"-0 -42 -1 -17 -124578 -452 -765 "
        "-13445467 -111111  "};
      ungets(stream.str().data());

      const std::istream_iterator<std::string> begin(stream);
      const std::istream_iterator<std::string> end;
      std::vector<std::string> tokens(begin, end);

      char s[MAXOP];
      for (auto const& token : tokens) {
        char type = getop(s);
        Assert::IsTrue(type == NUMBER);
        Assert::AreEqual(token, std::string{s});
      }
    }

    TEST_METHOD(getop_Float) {
      // We add a few spaces at the end so there is always something on
      // the internal buffer. This stops getch() going to stdin for input.
      std::stringstream stream{"0.3 4.2 1.1 1.7 124.578 4.52 0.765 1.3445467"
        " 0.0 11.1111  "};
      ungets(stream.str().data());

      const std::istream_iterator<std::string> begin(stream);
      const std::istream_iterator<std::string> end;
      std::vector<std::string> tokens(begin, end);

      char s[MAXOP];
      for (auto const& token : tokens) {
        char type = getop(s);
        Assert::IsTrue(type == NUMBER);
        Assert::AreEqual(token, std::string{s});
      }
    }

    TEST_METHOD(getop_NegativeFloat) {
      // We add a few spaces at the end so there is always something on
      // the internal buffer. This stops getch() going to stdin for input.
      std::stringstream stream{"-4.000002 -1.1 -7.1 -1245.78 -4.52 "
        "-0.0765 -1.3445467 -11111.1  "};
      ungets(stream.str().data());

      const std::istream_iterator<std::string> begin(stream);
      const std::istream_iterator<std::string> end;
      std::vector<std::string> tokens(begin, end);

      char s[MAXOP];
      for (auto const& token : tokens) {
        char type = getop(s);
        Assert::IsTrue(type == NUMBER);
        Assert::AreEqual(token, std::string{s});
      }
    }

    TEST_METHOD(getop_FloatNoIntPart) {
      // We add a few spaces at the end so there is always something on
      // the internal buffer. This stops getch() going to stdin for input.
      std::stringstream stream{".3 .42 .1 .17 .124578 .452 .765 .13445467 .0 .111111  "};
      ungets(stream.str().data());

      const std::istream_iterator<std::string> begin(stream);
      const std::istream_iterator<std::string> end;
      std::vector<std::string> tokens(begin, end);

      char s[MAXOP];
      for (auto const& token : tokens) {
        char type = getop(s);
        Assert::IsTrue(type == NUMBER);
        Assert::AreEqual(token, std::string{s});
      }
    }

    TEST_METHOD(getop_FloatNoFractPart) {
      // We add a few spaces at the end so there is always something on
      // the internal buffer. This stops getch() going to stdin for input.
      std::stringstream stream{"3. 42. 1. 17. 124578. 452. 765. 13445467. 0. 111111.  "};
      ungets(stream.str().data());

      const std::istream_iterator<std::string> begin(stream);
      const std::istream_iterator<std::string> end;
      std::vector<std::string> tokens(begin, end);

      char s[MAXOP];
      for (auto const& token : tokens) {
        char type = getop(s);
        Assert::IsTrue(type == NUMBER);
        Assert::AreEqual(token, std::string{s});
      }
    }

    TEST_METHOD(getop_AddOperator) {
      char str[] = "3 2 +  ";
      ungets(str);

      char s[MAXOP];
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"3"}, std::string{s});
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"2"}, std::string{s});
      Assert::IsTrue(getop(s) == ADD);
    }

    TEST_METHOD(getop_SubOperator) {
      char str[] = "-14 7 -  ";
      ungets(str);

      char s[MAXOP];
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"-14"}, std::string{s});
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"7"}, std::string{s});
      Assert::IsTrue(getop(s) == SUB);
    }

    TEST_METHOD(getop_MulOperator) {
      char str[] = "2.1414 0.6 *  ";
      ungets(str);

      char s[MAXOP];
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"2.1414"}, std::string{s});
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"0.6"}, std::string{s});
      Assert::IsTrue(getop(s) == MUL);
    }

    TEST_METHOD(getop_DivOperator) {
      char str[] = "3.14159 2.0 /  ";
      ungets(str);

      char s[MAXOP];
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"3.14159"}, std::string{s});
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"2.0"}, std::string{s});
      Assert::IsTrue(getop(s) == DIV);
    }

    TEST_METHOD(getop_ModOperator) {
      char str[] = "50 4 %  ";
      ungets(str);

      char s[MAXOP];
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"50"}, std::string{s});
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"4"}, std::string{s});
      Assert::IsTrue(getop(s) == MOD);
    }

    TEST_METHOD(getop_PowOperator) {
      char str[] = "2 8 ^  ";
      ungets(str);

      char s[MAXOP];
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"2"}, std::string{s});
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"8"}, std::string{s});
      Assert::IsTrue(getop(s) == POW);
    }

    TEST_METHOD(getop_ExpOperator) {
      char str[] = "2 E  ";
      ungets(str);

      char s[MAXOP];
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"2"}, std::string{s});
      Assert::IsTrue(getop(s) == EXP);
    }

    TEST_METHOD(getop_SinOperator) {
      char str[] = "3.14159 ~  ";
      ungets(str);

      char s[MAXOP];
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"3.14159"}, std::string{s});
      Assert::IsTrue(getop(s) == SIN);
    }

    TEST_METHOD(getop_ReturnsCharWhenUnknown) {
      char str[] = "2 8 #  ";
      ungets(str);

      char s[MAXOP];
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"2"}, std::string{s});
      Assert::IsTrue(getop(s) == NUMBER);
      Assert::AreEqual(std::string{"8"}, std::string{s});
      Assert::AreEqual(int('#'), getop(s));
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
