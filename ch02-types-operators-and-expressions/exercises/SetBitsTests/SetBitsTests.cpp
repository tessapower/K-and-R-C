#include "gtest/gtest.h"
#include "bittwiddling.h"

TEST(getlowerbits, zero) {
  EXPECT_EQ(getlowerbits(0b0, 0), 0);
}

TEST(getlowerbits, allZero) {
  EXPECT_EQ(getlowerbits(0b0000, 1), 0);
  EXPECT_EQ(getlowerbits(0b0000, 2), 0);
  EXPECT_EQ(getlowerbits(0b0000, 3), 0);
  EXPECT_EQ(getlowerbits(0b0000, 4), 0);
}

TEST(getlowerbits, allOne) {
  EXPECT_EQ(getlowerbits(0b1111, 1), 0b0001);
  EXPECT_EQ(getlowerbits(0b1111, 2), 0b0011);
  EXPECT_EQ(getlowerbits(0b1111, 3), 0b0111);
  EXPECT_EQ(getlowerbits(0b1111, 4), 0b1111);
}

TEST(getlowerbits, moreThanNBits) {
  EXPECT_EQ(getlowerbits(0b1010, 7),      0b1010);
  EXPECT_EQ(getlowerbits(0b11011, 10),    0b11011);
  EXPECT_EQ(getlowerbits(0b01, 3),        0b01);
  EXPECT_EQ(getlowerbits(0b11111111, 16), 0b11111111);
}

TEST(getlowerbits, lessThanNBits) {
  EXPECT_EQ(getlowerbits(0b1010, 2),     0b10);
  EXPECT_EQ(getlowerbits(0b11011, 4),    0b1011);
  EXPECT_EQ(getlowerbits(0b01, 1),       0b1);
  EXPECT_EQ(getlowerbits(0b10011010, 4), 0b1010);
}

TEST(setbits, setSingleBit) {
  EXPECT_EQ(setbits(0b1111, 0, 1, 0b0000), 0b1110);
  EXPECT_EQ(setbits(0b1111, 1, 1, 0b0000), 0b1101);
  EXPECT_EQ(setbits(0b1111, 2, 1, 0b0000), 0b1011);
  EXPECT_EQ(setbits(0b1111, 3, 1, 0b0000), 0b0111);
}

TEST(setbits, setAllZero) {
  EXPECT_EQ(setbits(0b1, 0, 1, 0b0),       0b0);
  EXPECT_EQ(setbits(0b11, 1, 2, 0b00),     0b00);
  EXPECT_EQ(setbits(0b111, 2, 3, 0b000),   0b000);
  EXPECT_EQ(setbits(0b1111, 3, 4, 0b0000), 0b0000);
}

TEST(setbits, setAllOne) {
  EXPECT_EQ(setbits(0b0, 0, 1, 0b1),       0b1);
  EXPECT_EQ(setbits(0b00, 1, 2, 0b11),     0b11);
  EXPECT_EQ(setbits(0b000, 2, 3, 0b111),   0b111);
  EXPECT_EQ(setbits(0b0000, 3, 4, 0b1111), 0b1111);
}

TEST(setbits, setCombo) {
  EXPECT_EQ(setbits(0b11011011, 5, 3, 0b0),        0b11000011);
  EXPECT_EQ(setbits(0b01011111, 7, 6, 0b100000),   0b10000011);
  EXPECT_EQ(setbits(0b01011110, 7, 1, 0b10101),    0b11011110);
  EXPECT_EQ(setbits(0b10000100, 4, 2, 0b10011001), 0b10001100);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
