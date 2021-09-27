//
// Created by Tessa Power on 24/09/21.
//

#include <gtest/gtest.h>
extern "C" {
#include <str_cat.h>
}


TEST(str_cat, valid) {
    char s[100] = "con";
    char t[] = "cat";
    str_cat(s, t);

    EXPECT_STREQ(s, "concat");
}

TEST(str_cat, not_backwards) {
    char s[100] = "con";
    char t[] = "cat";
    str_cat(s, t);

    EXPECT_STRNE(s, "catcon");
}

TEST(str_cat, super_long) {
    char s[100] = "concatenate a really, really, ";
    char t[] = "really, REALLY long string";
    str_cat(s, t);

    EXPECT_STREQ(s, "concatenate a really, really, really, REALLY long string");
}

TEST(str_cat, first_empty) {
    char s[100] = " ";
    char t[] = " world!";
    str_cat(s, t);

    EXPECT_STREQ(s, "  world!");
}

TEST(str_cat, second_empty) {
    char s[100] = "hello,";
    char t[] = "";
    str_cat(s, t);

    EXPECT_STREQ(s, "hello,");
}

TEST(str_cat, both_empty) {
    char s[100] = "";
    char t[] = "";
    str_cat(s, t);

    EXPECT_STREQ(s, "");
}

TEST(str_cat, first_null_second_empty) {
    char *s = NULL;
    char t[] = "";
    str_cat(s, t);

    EXPECT_TRUE(s == NULL);
}

TEST(str_cat, first_empty_second_null) {
    char s[100] = "";
    char *t = NULL;
    str_cat(s, t);

    EXPECT_STREQ(s, "");

}

TEST(str_cat, both_null) {
    char *s = NULL;
    char *t = NULL;
    str_cat(s, t);

    EXPECT_TRUE(s == NULL);
}

TEST(str_cat, first_null) {
    char *s = NULL;
    char t[] = "aristotle";
    str_cat(s, t);

    EXPECT_TRUE(s == NULL);
}

TEST(str_cat, second_null) {
    char s[100] = "hercules";
    char *t = NULL;
    str_cat(s, t);

    EXPECT_STREQ(s, "hercules");
}