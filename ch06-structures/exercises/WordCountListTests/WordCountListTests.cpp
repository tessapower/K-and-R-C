#include "CppUnitTest.h"

#include "ioutils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WordCountListTests {
  TEST_CLASS(WordCountListTests) {
  public:
    TEST_METHOD(WordCount_noLines) {
      WordCount list = NULL;
      const char** lines = NULL;
      list = wordcount(lines, 0);

      Assert::IsNull(list);
    }

    TEST_METHOD(WordCount_emptyLines) {
      const char* lines[5];
      for (int i = 0; i < 5; i++) {
        lines[i] = "";
      }

      WordCount list = NULL;
      list = wordcount(lines, 5);

      Assert::IsNull(list);
    }

    TEST_METHOD(WordCount_whitespaceLines) {
      const char* lines[5];
      for (int i = 0; i < 5; i++) {
        lines[i] = " \n \n \t \r\n ";
      }

      WordCount list = NULL;
      list = wordcount(lines, 5);

      Assert::IsNull(list);
    }

    TEST_METHOD(WordCount_singleWordDifferentCases) {
      const char* lines[] = {"and anD aND AND ANd And AnD"};
      WordCount list = NULL;

      list = wordcount(lines, 1);

      Assert::IsNotNull(list);

      Assert::AreEqual("and", list->word);
      Assert::AreEqual(7, list->count);
      Assert::IsNull(list->next);
    }

    TEST_METHOD(WordCount_normalLines) {
      const char* lines[4];
      lines[0] = "Lorem ipsum sit";
      lines[1] = " ipsum sit dolor ";
      lines[2] = "\n sit lorem ipsum sit";
      lines[3] = "sit dolor amet SIT DOLOR AMET";

      WordCount list = NULL;
      list = wordcount(lines, 4);

      Assert::IsNotNull(list);
      Assert::AreEqual("amet", list->word);
      Assert::AreEqual(2, list->count);

      list = list->next;
      Assert::AreEqual("Lorem", list->word);
      Assert::AreEqual(2, list->count);

      list = list->next;
      Assert::AreEqual("dolor", list->word);
      Assert::AreEqual(3, list->count);

      list = list->next;
      Assert::AreEqual("ipsum", list->word);
      Assert::AreEqual(3, list->count);

      list = list->next;
      Assert::AreEqual("sit", list->word);
      Assert::AreEqual(6, list->count);

      freelist(list);
    }

    TEST_METHOD(processline_none) {
      char* line = NULL;
      WordCount list = NULL;

      list = processline(line, list);
      Assert::IsNull(list);
    }

    TEST_METHOD(processline_empty) {
      char line[] = "";
      WordCount list = NULL;

      list = processline(line, list);
      Assert::IsNull(list);
    }

    TEST_METHOD(processline_onlyWhitespace) {
      char line[] = " \n \n \t \r\n ";
      WordCount list = NULL;

      list = processline(line, list);
      Assert::IsNull(list);
    }

    //TEST_METHOD(processline_normalLine) {
    //  char line[] = "Lorem ipsum sit dolor amet";
    //  WordCount list = NULL;

    //  list = processline(line, list);
    //  Assert::IsNotNull(list);
    //  Assert::AreEqual("Lorem", list->word);
    //  Assert::AreEqual(1, list->lines->number);

    //  Assert::AreEqual("ipsum", list->left->word);
    //  Assert::AreEqual(1, list->left->lines->number);

    //  Assert::AreEqual("sit", list->right->word);
    //  Assert::AreEqual(1, list->right->lines->number);
    //}
  };
}
