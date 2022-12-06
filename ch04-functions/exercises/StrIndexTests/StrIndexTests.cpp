#include "pch.h"
#include "CppUnitTest.h"
#include "strutils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StrIndexTests {
  TEST_CLASS(StrIndexTests) {
   public:
     TEST_METHOD(strrindexEmptyStr) {
       char s[] = "";
       char t[] = "hello";

       Assert::AreEqual(-1, strrindex(s, t));
     }

     TEST_METHOD(strrindexEmptySearch) {
       char s[] = "hello";
       char t[] = "";

       Assert::AreEqual(-1, strrindex(s, t));
     }

     TEST_METHOD(strrindexNoneFound) {
       char s[] = "hello world, this is a test and should return -1.";
       char t[] = "waldo";

       Assert::AreEqual(-1, strrindex(s, t));
     }

     TEST_METHOD(strrindexStartOfString) {
       char s[] = "42 is the answer.";
       char t[] = "42";

       Assert::AreEqual(0, strrindex(s, t));
     }

     TEST_METHOD(strrindexEndOfString) {
       char s[] = "Yes, that's right. The answer is 42";
       char t[] = "42";

       Assert::AreEqual(33, strrindex(s, t));
     }

     TEST_METHOD(strrindexMultiple) {
       char s[] = "42 is the answer. Yes, the number 42. The answer is 42";
       char t[] = "answer";

       Assert::AreEqual(42, strrindex(s, t));
     }

     TEST_METHOD(strrindexSingleLetterSearch) {
       char s[] = "42 is the answer. Yes, the number 42. The answer is 42";
       char t[] = "e";

       Assert::AreEqual(46, strrindex(s, t));
     }
  };
}
