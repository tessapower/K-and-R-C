#include "gtest/gtest.h"
extern "C" {
  #include "strutils.h"
}

TEST(squeeze, empty) {
  char s[] = "";
  char toDelete[] = "";
  char expected[] = "";
  squeeze(s, toDelete);

  EXPECT_STREQ(s, expected);
}

TEST(squeeze, emptyCharsToDelete) {
  char s[] = "Lorem ipsum sit dolor amet.";
  char toDelete[] = "";
  char expected[] = "Lorem ipsum sit dolor amet.";
  squeeze(s, toDelete);

  EXPECT_STREQ(s, expected);
}

TEST(squeeze, noCharsToDelete) {
  char s[] = "Lorem ipsum sit dolor amet.";
  char toDelete[] = "1234567890zyxwv";
  char expected[] = "Lorem ipsum sit dolor amet.";
  squeeze(s, toDelete);

  EXPECT_STREQ(s, expected);
}

TEST(squeeze, removeWhitespace) {
  char s1[] = "Lorem ipsum sit dolor amet.";
  char spaces[] = " ";
  char expected1[] = "Loremipsumsitdoloramet.";
  squeeze(s1, spaces);

  EXPECT_STREQ(s1, expected1);

  char s2[] = "Lor\nem\n ip\nsum \nsi\nt\n dol\nor \nam\net\n.\n";
  char newlines[] = "\n";
  char expected2[] = "Lorem ipsum sit dolor amet.";
  squeeze(s2, newlines);

  EXPECT_STREQ(s2, expected2);

  char s3[] = "\tLorem\tipsum\tsit\tdolor\tamet.\t";
  char tabs[] = "\t";
  char expected3[] = "Loremipsumsitdoloramet.";
  squeeze(s3, tabs);

  EXPECT_STREQ(s3, expected3);
}

TEST(squeeze, removeEntireString) {
  char s[] = "Hello World!";
  char toDelete[] = "Hello World!";
  char expected[] = "";
  squeeze(s, toDelete);

  EXPECT_STREQ(s, expected);
}

TEST(squeeze, standard) {
  char s[] = "Lorem ipsum sit dolor amet.";
  char toDelete[] = "aeiou";
  char expected[] = "Lrm psm st dlr mt.";
  squeeze(s, toDelete);

  EXPECT_STREQ(s, expected);
}
