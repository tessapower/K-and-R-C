#include "pch.h"
extern "C" {
  #include "bittwiddling.h"
}

TEST(rightrot, rotateByZero) {
  EXPECT_EQ(rightrot(0b0101, 0), 0b0101);
  EXPECT_EQ(rightrot(0b0101, sizeof(unsigned) * CHAR_BIT), 0b0101);
  EXPECT_EQ(rightrot(0b0101, sizeof(unsigned) * CHAR_BIT * 2), 0b0101);
  EXPECT_EQ(rightrot(0b0101, sizeof(unsigned) * CHAR_BIT * 3), 0b0101);
  EXPECT_EQ(rightrot(0b0101, sizeof(unsigned) * CHAR_BIT * 4), 0b0101);
}

TEST(rightrot, rotateByOne) {
  EXPECT_EQ(rightrot(0b0, 1), 0b0);
  EXPECT_EQ(rightrot(0b1, 1), 0b1 << (sizeof(unsigned) * CHAR_BIT - 1));

  unsigned x = 0b0101;
  // Shift the 1 in the LSB position to MSB position to get 1000...0010
  unsigned expected = (0b1 << (sizeof(unsigned) * CHAR_BIT - 1)) | (x >> 1);
  EXPECT_EQ(rightrot(x,                                   1), expected);
  EXPECT_EQ(rightrot(x, sizeof(unsigned) * CHAR_BIT     + 1), expected);
  EXPECT_EQ(rightrot(x, sizeof(unsigned) * CHAR_BIT * 2 + 1), expected);
  EXPECT_EQ(rightrot(x, sizeof(unsigned) * CHAR_BIT * 3 + 1), expected);
  EXPECT_EQ(rightrot(x, sizeof(unsigned) * CHAR_BIT * 4 + 1), expected);
}

TEST(rightrot, rotateByMany) {
  EXPECT_EQ(rightrot(0b0, 30), 0b0);
  EXPECT_EQ(rightrot(0b1, 5), 0b1 << (sizeof(unsigned) * CHAR_BIT - 5));

  unsigned x = 0b10100101;
  EXPECT_EQ(rightrot(x, 1), 0b10000000000000000000000001010010);
  EXPECT_EQ(rightrot(x, 4), 0b01010000000000000000000000001010);
  EXPECT_EQ(rightrot(x, 8), 0b10100101000000000000000000000000);
  EXPECT_EQ(rightrot(x, 17), 0b010100101000000000000000);
  EXPECT_EQ(rightrot(x, 21), 0b01010010100000000000);
}
  
