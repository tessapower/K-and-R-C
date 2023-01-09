#include "gtest/gtest.h"
#include "strutils.h"

TEST(any, empty) {
  EXPECT_EQ(any("", ""), -1);
  EXPECT_EQ(any("lorem ipsum", ""), -1);
  EXPECT_EQ(any("", "lorem ipsum"), -1);
}

TEST(any, whitespace) {
  EXPECT_EQ(any("lorem ipsum\tsit dolor amet.\n", " \t\n"), 5);
  EXPECT_EQ(any("lorem ipsum\tsit dolor amet.\n", "\t\n "), 11);
  EXPECT_EQ(any("lorem ipsum\tsit dolor amet.\n", "\n \t"), 27);
  EXPECT_EQ(any("loremipsumsitdoloramet.", " \t\n"), -1);
}

TEST(any, symbols) {
  EXPECT_EQ(any("lorem !psum $it dolor @met.", "!.@$"), 6);
  EXPECT_EQ(any("lorem ipsum sit dolor amet", "!.@$"), -1);
}

TEST(any, numbers) {
  EXPECT_EQ(any("one two three 4 five 6 seven 8 9 zero", "1234567890"), 14);
  EXPECT_EQ(any("one two three four five", "12345"), -1);
}

TEST(any, chars) {
  EXPECT_EQ(any("lorem ipsum sit dolor amet.", "aeiou"), 22);
  EXPECT_EQ(any("lorem ipsum sit dolor amet.", "zyxwv"), -1);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
