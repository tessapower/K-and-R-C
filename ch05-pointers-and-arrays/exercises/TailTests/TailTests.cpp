#include "pch.h"
#include "CppUnitTest.h"

#include "ioutils.h"

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TailTests {
  TEST_CLASS(TailTests) {
  public:
    TEST_METHOD(readline_empty) {
      auto getc = [] {
        return EOF;
      };

      std::string str{readline(getc)};
      Assert::AreEqual(std::string{""}, str);
    }

    TEST_METHOD(readline_newline) {
      auto getc = [] {
        return (int)'\n';
      };

      std::string str{ readline(getc) };
      Assert::AreEqual(std::string{"\n"}, str);
    }

    TEST_METHOD(readline_nonempty) {
      auto getc = [] {
        static int i = 0;
        static std::string hello = "hello, world!\n";

        return (int)hello[i++];
      };

      std::string str{readline(getc)};
      Assert::AreEqual(std::string{"hello, world!\n"}, str);
    }

    TEST_METHOD(readlines_noInput) {
      auto getc = [] {
        return EOF;
      };

      char** lines = static_cast<char**>(malloc(5 * sizeof(char*)));
      Assert::IsNotNull(lines);

      int nRead = readlines(lines, 5, getc);
      Assert::AreEqual(0, nRead);

      free(lines);
    }

    TEST_METHOD(readlines_nlinesSameAsInput) {
      auto getc = [] {
        static int i = 0;
        static std::string strs = "hello, world!\n"
          "lorem ipsum sit dolor amet\n"
          "happy birthday\n"
          "merry christmas\n" 
          "and another thing...!\n";

        return (i == strs.length() ? EOF : (int)strs[i++]);
      };

      char** lines = static_cast<char**>(malloc(5 * sizeof(char*)));
      Assert::IsNotNull(lines);

      int nRead = readlines(lines, 5, getc);

      Assert::AreEqual(5, nRead);
      Assert::AreEqual(std::string{"hello, world!\n"}, std::string{lines[0]});
      Assert::AreEqual(std::string{"lorem ipsum sit dolor amet\n"}, std::string{lines[1]});
      Assert::AreEqual(std::string{"happy birthday\n"}, std::string{lines[2]});
      Assert::AreEqual(std::string{"merry christmas\n"}, std::string{lines[3]});
      Assert::AreEqual(std::string{"and another thing...!\n"}, std::string{lines[4]});

      for (auto i = 0; i < nRead; ++i) {
        free(lines[i]);
      }
      free(lines);
    }

    TEST_METHOD(readlines_nlinesLessThanInput) {
      auto getc = [] {
        static int i = 0;
        static std::string strs = "hello, world!\n"
          "lorem ipsum sit dolor amet\n"
          "happy birthday\n"
          "merry christmas\n"
          "and another thing...!\n";

        return (i == strs.length() ? EOF : (int)strs[i++]);
      };

      char** lines = static_cast<char**>(malloc(3 * sizeof(char*)));
      Assert::IsNotNull(lines);

      int nRead = readlines(lines, 3, getc);

      Assert::AreEqual(3, nRead);
      Assert::AreEqual(std::string{"happy birthday\n"}, std::string{lines[0]});
      Assert::AreEqual(std::string{"merry christmas\n"}, std::string{lines[1]});
      Assert::AreEqual(std::string{"and another thing...!\n"}, std::string{lines[2]});

      for (auto i = 0; i < nRead; ++i) {
        free(lines[i]);
      }
      free(lines);
    }

    TEST_METHOD(readlines_nlinesGreaterThanInput) {
      auto getc = [] {
        static int i = 0;
        static std::string strs = "hello, world!\n"
          "lorem ipsum sit dolor amet\n"
          "happy birthday\n"
          "merry christmas\n"
          "and another thing...!\n";

        return (i == strs.length() ? EOF : (int)strs[i++]);
      };

      char** lines = static_cast<char**>(malloc(10 * sizeof(char*)));
      Assert::IsNotNull(lines);

      int nRead = readlines(lines, 10, getc);

      Assert::AreEqual(5, nRead);
      Assert::AreEqual(std::string{"hello, world!\n"}, std::string{lines[0]});
      Assert::AreEqual(std::string{"lorem ipsum sit dolor amet\n"}, std::string{lines[1]});
      Assert::AreEqual(std::string{"happy birthday\n"}, std::string{lines[2]});
      Assert::AreEqual(std::string{"merry christmas\n"}, std::string{lines[3]});
      Assert::AreEqual(std::string{"and another thing...!\n"}, std::string{lines[4]});

      for (auto i = 0; i < nRead; ++i) {
        free(lines[i]);
      }
      free(lines);
    }
  };
}
