#include "gtest/gtest.h"
extern "C" {
  #include "strutils.h"
}

TEST(lower, nonalpha) {
  EXPECT_EQ(lower(' '), ' ');
  EXPECT_EQ(lower('1'), '1');
  EXPECT_EQ(lower('\t'), '\t');
}

TEST(lower, upper) {
  EXPECT_EQ(lower('P'), 'p');
  EXPECT_EQ(lower('E'), 'e');
  EXPECT_EQ(lower('J'), 'j');
}

TEST(lower, lower) {
  EXPECT_EQ(lower('a'), 'a');
  EXPECT_EQ(lower('v'), 'v');
  EXPECT_EQ(lower('f'), 'f');
}
