#include "gtest/gtest.h"
#include "bittwiddling.h"


TEST(invert, invertNothing) {
  EXPECT_EQ(invert(0b0, 0, 0),        0b0);
  EXPECT_EQ(invert(0b01010101, 7, 0), 0b01010101);
}

TEST(invert, invertSingleBit) {
  EXPECT_EQ(invert(0b0, 0, 1),        0b1);
  EXPECT_EQ(invert(0b1, 0, 1),        0b0);
  EXPECT_EQ(invert(0b01010111, 4, 1), 0b01000111);
  EXPECT_EQ(invert(0b01010101, 3, 1), 0b01011101);
}

TEST(invert, invertMultipleBits) {
  EXPECT_EQ(invert(0b0000, 3, 2),     0b1100);
  EXPECT_EQ(invert(0b11100101, 7, 5), 0b00011101);
  EXPECT_EQ(invert(0b01010111, 4, 1), 0b01000111);
  EXPECT_EQ(invert(0b01010101, 3, 1), 0b01011101);
}

TEST(invert, invertAllBits) {
  EXPECT_EQ(invert(0b0000, 3, 4),               0b1111);
  EXPECT_EQ(invert(0b11111111, 7, 8),           0b00000000);
  EXPECT_EQ(invert(0b11100101, 7, 8),           0b00011010);
  EXPECT_EQ(invert(0b0110101101010111, 15, 16), 0b1001010010101000);
}
