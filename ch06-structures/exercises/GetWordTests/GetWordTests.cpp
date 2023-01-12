#include "CppUnitTest.h"
#include "strutils.h"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GetWordTests {
  TEST_CLASS(GetWordTests) {
  public:
    TEST_METHOD_INITIALIZE(clearBuffer) {
      clearbuf();
    }

    TEST_METHOD(getword_emptyString) {
      const std::string str = "";
      ungets(str.c_str());

      constexpr int lim = 32;
      char word[lim];
      Assert::AreEqual(int('\0'), getword(word, lim));
      Assert::AreEqual('\0', *word);
    }

    TEST_METHOD(getword_noWords) {
      const std::string str =
        "// hello world, this is a comment\n"
        "/* comment, comment, comment\n"
        " * a multiline comment\n"
        " */"
        "'here is a string'"
        "\"and another one!\"  ";
      ungets(str.c_str());

      constexpr int lim = 32;
      char word[lim];
      Assert::AreEqual(int('\0'), getword(word, lim));
      Assert::AreEqual('\0', *word);
    }

    TEST_METHOD(getword_skipComments) {
      const std::string str =
        " // hello world, this is a comment\n"
        " int x"
        " /* comment, comment, comment\n"
        "  * a multiline comment\n"
        "  */"
        " = 10;";
      ungets(str.c_str());

      constexpr int lim = 32;
      char word[lim];

      Assert::AreEqual(int('i'), getword(word, lim));
      Assert::AreEqual(std::string{"int"}, std::string{word});
      Assert::AreEqual(int('x'), getword(word, lim));
      Assert::AreEqual(std::string{"x"}, std::string{word});
      Assert::AreEqual(int('='), getword(word, lim));
      Assert::AreEqual(std::string{"="}, std::string{word});
      Assert::AreEqual(int('1'), getword(word, lim));
      Assert::AreEqual(std::string{"1"}, std::string{word});
      Assert::AreEqual(int('0'), getword(word, lim));
      Assert::AreEqual(std::string{"0"}, std::string{word});
      Assert::AreEqual(int(';'), getword(word, lim));
      Assert::AreEqual(std::string{";"}, std::string{word});
    }

    TEST_METHOD(getword_skipWhitespace) {
      const std::string str =
        " \t\v\t\t\t\t\t\r\n"
        " int    \t      \t       x       \r\n    "
        "  \t    =      \v      \v  "
        "\n\n\n\n\n\n 10  ;  ";
      ungets(str.c_str());

      constexpr int lim = 32;
      char word[lim];

      Assert::AreEqual(int('i'), getword(word, lim));
      Assert::AreEqual(std::string{ "int" }, std::string{ word });
      Assert::AreEqual(int('x'), getword(word, lim));
      Assert::AreEqual(std::string{ "x" }, std::string{ word });
      Assert::AreEqual(int('='), getword(word, lim));
      Assert::AreEqual(std::string{ "=" }, std::string{ word });
      Assert::AreEqual(int('1'), getword(word, lim));
      Assert::AreEqual(std::string{ "1" }, std::string{ word });
      Assert::AreEqual(int('0'), getword(word, lim));
      Assert::AreEqual(std::string{ "0" }, std::string{ word });
      Assert::AreEqual(int(';'), getword(word, lim));
      Assert::AreEqual(std::string{ ";" }, std::string{ word });
    }

    TEST_METHOD(getword_skipStrings) {
      const std::string str =
        "'here is a string'int x\"= 42\" = 'hello world' 10  ;";
      ungets(str.c_str());

      constexpr int lim = 32;
      char word[lim];

      Assert::AreEqual(int('i'), getword(word, lim));
      Assert::AreEqual(std::string{ "int" }, std::string{ word });
      Assert::AreEqual(int('x'), getword(word, lim));
      Assert::AreEqual(std::string{ "x" }, std::string{ word });
      Assert::AreEqual(int('='), getword(word, lim));
      Assert::AreEqual(std::string{ "=" }, std::string{ word });
      Assert::AreEqual(int('1'), getword(word, lim));
      Assert::AreEqual(std::string{ "1" }, std::string{ word });
      Assert::AreEqual(int('0'), getword(word, lim));
      Assert::AreEqual(std::string{ "0" }, std::string{ word });
      Assert::AreEqual(int(';'), getword(word, lim));
      Assert::AreEqual(std::string{ ";" }, std::string{ word });
    }

    TEST_METHOD(getword_singleChar) {
      const std::string str =
        "(!a | b) ? 1 : -1;";
      ungets(str.c_str());

      constexpr int lim = 32;
      char word[lim];
      Assert::AreEqual(int('('), getword(word, lim));
      Assert::AreEqual(std::string{"("}, std::string{word});
      Assert::AreEqual(int('!'), getword(word, lim));
      Assert::AreEqual(std::string{"!"}, std::string{word});
      Assert::AreEqual(int('a'), getword(word, lim));
      Assert::AreEqual(std::string{"a"}, std::string{word});
      Assert::AreEqual(int('|'), getword(word, lim));
      Assert::AreEqual(std::string{"|"}, std::string{word});
      Assert::AreEqual(int('b'), getword(word, lim));
      Assert::AreEqual(std::string{"b"}, std::string{word});
      Assert::AreEqual(int(')'), getword(word, lim));
      Assert::AreEqual(std::string{")"}, std::string{word});
      Assert::AreEqual(int('?'), getword(word, lim));
      Assert::AreEqual(std::string{"?"}, std::string{word});
      Assert::AreEqual(int('1'), getword(word, lim));
      Assert::AreEqual(std::string{"1"}, std::string{word});
      Assert::AreEqual(int(':'), getword(word, lim));
      Assert::AreEqual(std::string{":"}, std::string{word});
      Assert::AreEqual(int('-'), getword(word, lim));
      Assert::AreEqual(std::string{"-"}, std::string{word});
      Assert::AreEqual(int('1'), getword(word, lim));
      Assert::AreEqual(std::string{"1"}, std::string{word});
      Assert::AreEqual(int(';'), getword(word, lim));
      Assert::AreEqual(std::string{";"}, std::string{word});
    }

    TEST_METHOD(getword_preprocessorDirective) {
      const std::string str =
        "#ifdef PROMPT"
        "  #define YES 1"
        "  #define NO  0"
        "#endif";
      ungets(str.c_str());

      constexpr int lim = 32;
      char word[lim];

      Assert::AreEqual(int('#'), getword(word, lim));
      Assert::AreEqual(std::string{"#ifdef"}, std::string{word});
      Assert::AreEqual(int('P'), getword(word, lim));
      Assert::AreEqual(std::string{"PROMPT"}, std::string{word});
      Assert::AreEqual(int('#'), getword(word, lim));
      Assert::AreEqual(std::string{"#define"}, std::string{word});
      Assert::AreEqual(int('Y'), getword(word, lim));
      Assert::AreEqual(std::string{"YES"}, std::string{word});
      Assert::AreEqual(int('1'), getword(word, lim));
      Assert::AreEqual(std::string{"1"}, std::string{word});
      Assert::AreEqual(int('#'), getword(word, lim));
      Assert::AreEqual(std::string{ "#define" }, std::string{ word });
      Assert::AreEqual(int('N'), getword(word, lim));
      Assert::AreEqual(std::string{"NO"}, std::string{word});
      Assert::AreEqual(int('0'), getword(word, lim));
      Assert::AreEqual(std::string{"0"}, std::string{word});
      Assert::AreEqual(int('#'), getword(word, lim));
      Assert::AreEqual(std::string{"#endif"}, std::string{word});
    }

    TEST_METHOD(getword_underscore) {
      const std::string str =
        "Point _location;"
        "char __secretchar;";
      ungets(str.c_str());

      constexpr int lim = 32;
      char word[lim];
      Assert::AreEqual(int('P'), getword(word, lim));
      Assert::AreEqual(std::string{"Point"}, std::string{word});
      Assert::AreEqual(int('_'), getword(word, lim));
      Assert::AreEqual(std::string{"_location"}, std::string{word});
      Assert::AreEqual(int(';'), getword(word, lim));
      Assert::AreEqual(std::string{";"}, std::string{word});
      Assert::AreEqual(int('c'), getword(word, lim));
      Assert::AreEqual(std::string{"char"}, std::string{word});
      Assert::AreEqual(int('_'), getword(word, lim));
      Assert::AreEqual(std::string{"__secretchar"}, std::string{word});
      Assert::AreEqual(int(';'), getword(word, lim));
      Assert::AreEqual(std::string{ ";" }, std::string{ word });
    }
  };
}
