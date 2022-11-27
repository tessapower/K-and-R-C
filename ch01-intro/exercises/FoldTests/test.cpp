#include "gtest/gtest.h"
extern "C" {
  #include "StrUtils.h"
}

namespace FoldTests {
  TEST(fold, no_fold) {
    char str[MAX_LINE] = "Lorem Ipsum is simply dummy text.";
    char expected[MAX_LINE] = "Lorem Ipsum is simply dummy text.";

    const int foldLimit = 79;
    fold(str, foldLimit);
    EXPECT_STREQ(str, expected);
  }

  TEST(fold, empty) {
    char str[MAX_LINE] = "";
    char expected[MAX_LINE] = "";

    const int foldLimit = 79;
    fold(str, foldLimit);
    EXPECT_STREQ(str, expected);
  }

  TEST(fold, multiline_text) {
    char str[MAX_LINE] =
        "Lorem Ipsum is simply dummy text of the printing and typesetting "
        "industry. Lorem Ipsum has been the industry\'s standard dummy text ever "
        "since the 1500s, when an unknown printer took a galley of type and "
        "scrambled it to make a type specimen book.It has survived not only five "
        "centuries, but also the leap into electronic typesetting, remaining "
        "essentially unchanged.It was popularised in the 1960s with the release "
        "of Letraset sheets containing Lorem Ipsum passages, and more recently "
        "with desktop publishing software like Aldus PageMaker including "
        "versions of Lorem Ipsum.";

    char expected[MAX_LINE] =
        "Lorem Ipsum is simply dummy text of the printing and typesetting "
        "industry.\nLorem Ipsum has been the industry\'s standard dummy text "
        "ever since the 1500s,\nwhen an unknown printer took a galley of type "
        "and scrambled it to make a type\nspecimen book.It has survived not only "
        "five centuries, but also the leap into\nelectronic typesetting, "
        "remaining essentially unchanged.It was popularised in\nthe 1960s with "
        "the release of Letraset sheets containing Lorem Ipsum passages,\nand "
        "more recently with desktop publishing software like Aldus "
        "PageMaker\nincluding versions of Lorem Ipsum.";

    const int foldLimit = 79;
    fold(str, foldLimit);
    EXPECT_STREQ(str, expected);
  }

  TEST(fold, really_long_line) {
    char str[MAX_LINE] =
        "LoremIpsumissimplydummytextoftheprintingandtypesettingindustry."
        "LoremIpsumhasbeentheindustry\'sstandarddummytexteversincethe1500s,"
        "whenanunknownprintertookagalleyoftypeandscrambledittomakeatypespecimenbo"
        "ok.Ithassurvivednotonlyfivecenturies,butalsotheleapintoelectronic"
        "typesetting,remainingessentiallyunchanged.";

    char expected[MAX_LINE] =
        "LoremIpsumissimplydummytextoftheprintingandtypesettingindustry."
        "LoremIpsumhasbee\nntheindustry\'sstandarddummytexteversincethe1500s,"
        "whenanunknownprintertookagalle\nyoftypeandscrambledittomakeatypespecimen"
        "book.Ithassurvivednotonlyfivecenturies,\nbutalsotheleapintoelectronictyp"
        "esetting,remainingessentiallyunchanged.";

    const int foldLimit = 79;
    fold(str, foldLimit);
    EXPECT_STREQ(str, expected);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
