#include "gtest/gtest.h"
#include <string>
extern "C" {
  #include "strutils.h"
}

TEST(getline, empty) {
  const int MAX_LINE = 1000;
  char s[MAX_LINE];

  auto getc = [] {
    return (int)'\0';
  };

  EXPECT_EQ(getline(s, MAX_LINE, getc), 1);
  EXPECT_STREQ(s, "");
}

TEST(getline, lessThanMax) {
  const int MAX_LINE = 1000;
  char s[MAX_LINE];

  auto getc = [] {
    static int i = 0;
    static std::string hello = "hello, world!";

    return (int)hello[i++];
  };

  EXPECT_EQ(getline(s, MAX_LINE, getc), 14);
  EXPECT_STREQ(s, "hello, world!");
}

TEST(getline, moreThanMax) {
  const int MAX_LINE = 15;
  char s[MAX_LINE];

  auto getc = [] {
    static int i = 0;
    static std::string lorem = "lorem ipsum sit dolor amet.";

    return (int)lorem[i++];
  };

  EXPECT_EQ(getline(s, MAX_LINE, getc), 28);
  EXPECT_STREQ(s, "lorem ipsum si");
}

TEST(getline, winLineEndings) {
  const int MAX_LINE = 1000;
  char s[MAX_LINE];

  auto getc = [] {
    static int i = 0;
    static std::string hello = "hello, world!\r\n";

    return (int)hello[i++];
  };

  EXPECT_EQ(getline(s, MAX_LINE, getc), 15);
  EXPECT_STREQ(s, "hello, world!\n");
}

TEST(getline, unixLineEndings) {
  const int MAX_LINE = 1000;
  char s[MAX_LINE];

  auto getc = [] {
    static int i = 0;
    static std::string hello = "hello, world!\n";

    return (int)hello[i++];
  };

  EXPECT_EQ(getline(s, MAX_LINE, getc), 15);
  EXPECT_STREQ(s, "hello, world!\n");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
