#include "gtest/gtest.h"
extern "C" {
  #include "strutils.h"
}

namespace HexToIntTests {
  TEST(htoi, NaN) {
    EXPECT_EQ(htoi("nonsense"), 0x0);
  }

  TEST(htoi, zero) {
    EXPECT_EQ(htoi(  "0"), 0x0);
    EXPECT_EQ(htoi("0x0"), 0x0);
    EXPECT_EQ(htoi("0X0"), 0x0);
  }

  TEST(htoi, noLeadingZero) {
    EXPECT_EQ(htoi("x123ABC"), 0);
    EXPECT_EQ(htoi("X123ABC"), 0);
  }

  TEST(htoi, one) {
    EXPECT_EQ(htoi("1"), 0x1);
    EXPECT_EQ(htoi("0x1"), 0x1);

    EXPECT_EQ(htoi("01"), 0x1);
    EXPECT_EQ(htoi("0x01"), 0x1);

    EXPECT_EQ(htoi("001"), 0x1);
    EXPECT_EQ(htoi("0x001"), 0x1);

    EXPECT_EQ(htoi("0001"), 0x1);
    EXPECT_EQ(htoi("0x0001"), 0x1);

    EXPECT_EQ(htoi("00001"), 0x1);
    EXPECT_EQ(htoi("0x00001"), 0x1);

    EXPECT_EQ(htoi("000001"), 0x1);
    EXPECT_EQ(htoi("0x000001"), 0x1);

    EXPECT_EQ(htoi("0000001"), 0x1);
    EXPECT_EQ(htoi("0x0000001"), 0x1);

    EXPECT_EQ(htoi("00000001"), 0x1);
    EXPECT_EQ(htoi("0x00000001"), 0x1);
  }

  TEST(htoi, half_valid_str) {
    EXPECT_EQ(htoi("123XYZ"), 0x123);
    EXPECT_EQ(htoi("0x123XYZ"), 0x123);

    EXPECT_EQ(htoi("XYZABC"), 0x0);
    EXPECT_EQ(htoi("0xXYZABC"), 0x0);
    
    EXPECT_EQ(htoi("0x0x0C1"), 0x0);
    
    EXPECT_EQ(htoi("AXB1J2"), 0xA);
    EXPECT_EQ(htoi("0xAXB1J2"), 0xA);
  }

  TEST(htoi, digits) {
    EXPECT_EQ(htoi("2"), 0x2);
    EXPECT_EQ(htoi("0x2"), 0x2);
    
    EXPECT_EQ(htoi("3"), 0x3);
    EXPECT_EQ(htoi("0x3"), 0x3);
    
    EXPECT_EQ(htoi("4"), 0x4);
    EXPECT_EQ(htoi("0x4"), 0x4);
    
    EXPECT_EQ(htoi("5"), 0x5);
    EXPECT_EQ(htoi("0x5"), 0x5);
    
    EXPECT_EQ(htoi("6"), 0x6);
    EXPECT_EQ(htoi("0x6"), 0x6);
    
    EXPECT_EQ(htoi("7"), 0x7);
    EXPECT_EQ(htoi("0x7"), 0x7);
    
    EXPECT_EQ(htoi("8"), 0x8);
    EXPECT_EQ(htoi("0x8"), 0x8);
    
    EXPECT_EQ(htoi("9"), 0x9);
    EXPECT_EQ(htoi("0x9"), 0x9);

  }

  TEST(htoi, letters) {
    EXPECT_EQ(htoi("A"), 0xA);
    EXPECT_EQ(htoi("0xA"), 0xA);

    EXPECT_EQ(htoi("B"), 0xB);
    EXPECT_EQ(htoi("0xB"), 0xB);

    EXPECT_EQ(htoi("C"), 0xC);
    EXPECT_EQ(htoi("0xC"), 0xC);
    
    EXPECT_EQ(htoi("D"), 0xD);
    EXPECT_EQ(htoi("0xD"), 0xD);

    EXPECT_EQ(htoi("E"), 0xE);
    EXPECT_EQ(htoi("0xE"), 0xE);

    EXPECT_EQ(htoi("F"), 0xF);
    EXPECT_EQ(htoi("0xF"), 0xF);

    EXPECT_EQ(htoi("X"), 0x0);
    EXPECT_EQ(htoi("0xX"), 0x0);
  }

  TEST(htoi, combination) {
    EXPECT_EQ(htoi("ABC123"), 0xABC123);
    EXPECT_EQ(htoi("0xABC123"), 0xABC123);
    
    EXPECT_EQ(htoi("123ABC"), 0x123ABC);
    EXPECT_EQ(htoi("0x123ABC"), 0x123ABC);
    
    EXPECT_EQ(htoi("000C1"), 0xC1);
    EXPECT_EQ(htoi("0x000C1"), 0xC1);
    
    EXPECT_EQ(htoi("D9001"), 0xD9001);
    EXPECT_EQ(htoi("0xD9001"), 0xD9001);
    
    EXPECT_EQ(htoi("F67E"), 0xF67E);
    EXPECT_EQ(htoi("0xF67E"), 0xF67E);
    
    EXPECT_EQ(htoi("FFFF"), 0xFFFF);
    EXPECT_EQ(htoi("0xFFFF"), 0xFFFF);
    
    EXPECT_EQ(htoi("A1B2C3"), 0xA1B2C3);
    EXPECT_EQ(htoi("0xA1B2C3"), 0xA1B2C3);
  }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
