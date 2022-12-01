#include "pch.h"
#include <time.h>
#include <stdlib.h>
#include "CppUnitTest.h"

extern "C" {
  #include "binsearch.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinarySearchTests {
  TEST_CLASS(BinarySearchTests) {
  public:
    TEST_METHOD(OldBinarySearch) {
      int nums[100];
      for (int i = 0; i < 100; i++) {
        nums[i] = i;
      }
      
      srand(0);
      int x = rand() % 100;
      Assert::AreEqual(binsearch1(x, nums, 100), x);
      Assert::AreEqual(binsearch1(-50, nums, 100), -1);
    }

    TEST_METHOD(NewBinarySearch) {
        int nums[100];
        for (int i = 0; i < 100; i++) {
          nums[i] = i;
        }

        srand(0);
        int x = rand() % 100;
        Assert::AreEqual(binsearch2(x, nums, 100), x);
        Assert::AreEqual(binsearch2(-50, nums, 100), -1);
    }
  };
}
