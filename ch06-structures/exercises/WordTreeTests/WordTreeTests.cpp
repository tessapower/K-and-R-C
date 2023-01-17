#include "CppUnitTest.h"
#include "ioutils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WordTreeTests {
  TEST_CLASS(WordTreeTests) {
  public:
    TEST_METHOD(wordtree_noLines) {
      WordTree root = NULL;
      const char** lines = NULL;
      root = wordtree(lines, 0);

      Assert::IsNull(root);
    }

    TEST_METHOD(wordtree_emptyLines) {
      const char* lines[5];
      for (int i = 0; i < 5; i++) {
        lines[i] = "";
      }

      WordTree root = NULL;
      root = wordtree(lines, 5);

      Assert::IsNull(root);
    }

    TEST_METHOD(wordtree_whitespaceLines) {
      const char* lines[5];
      for (int i = 0; i < 5; i++) {
        lines[i] = " \n \n \t \r\n ";
      }

      WordTree root = NULL;
      root = wordtree(lines, 5);

      Assert::IsNull(root);
    }

    TEST_METHOD(wordtree_noiseWordsLines) {
      const char* lines[5];
      for (int i = 0; i < 5; i++) {
        lines[i] = "and of I OR to tHe so iT";
      }
      WordTree root = NULL;

      root = wordtree(lines, 5);

      Assert::IsNull(root);
    }

    TEST_METHOD(wordtree_normalLines) {
      const char* lines[4];
      lines[0] = "Lorem";
      lines[1] = " ipsum ";
      lines[2] = "\n";
      lines[3] = "sit dolor amet";

      WordTree root = NULL;
      root = wordtree(lines, 4);

      Assert::IsNotNull(root);
      Assert::AreEqual("Lorem", root->word);
      Assert::AreEqual(1, root->lines->number);

      Assert::AreEqual("ipsum", root->left->word);
      Assert::AreEqual(2, root->left->lines->number);

      Assert::AreEqual("sit", root->right->word);
      Assert::AreEqual(4, root->right->lines->number);
    }

    TEST_METHOD(processline_none) {
      char* line = NULL;
      WordTree root = NULL;

      root = processline(line, 1, root);
      Assert::IsNull(root);
    }

    TEST_METHOD(processline_empty) {
      char line[] = "";
      WordTree root = NULL;

      root = processline(line, 1, root);
      Assert::IsNull(root);
    }

    TEST_METHOD(processline_onlyWhitespace) {
      char line[] = " \n \n \t \r\n ";
      WordTree root = NULL;

      root = processline(line, 1, root);
      Assert::IsNull(root);
    }

    TEST_METHOD(processline_onlyNoiseWords) {
      char line[] = "and of I OR to tHe so iT";
      WordTree root = NULL;

      root = processline(line, 1, root);
      Assert::IsNull(root);
    }

    TEST_METHOD(processline_normalLine) {
      char line[] = "Lorem ipsum sit dolor amet";
      WordTree root = NULL;

      root = processline(line, 1, root);
      Assert::IsNotNull(root);
      Assert::AreEqual("Lorem", root->word);
      Assert::AreEqual(1, root->lines->number);

      Assert::AreEqual("ipsum", root->left->word);
      Assert::AreEqual(1, root->left->lines->number);

      Assert::AreEqual("sit", root->right->word);
      Assert::AreEqual(1, root->right->lines->number);
    }
  };
}
