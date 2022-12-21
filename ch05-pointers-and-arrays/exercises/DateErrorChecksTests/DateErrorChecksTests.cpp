#include "pch.h"
#include "CppUnitTest.h"

#include "dateutils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DateErrorChecksTests {
  TEST_CLASS(DateErrorChecksTests) {
  public:
    TEST_METHOD(day_of_year_invalidDate) {
      Assert::AreEqual(-1, day_of_year(0, 0, 0));
    }

    TEST_METHOD(day_of_year_invalidDay) {
      Assert::AreEqual(-1, day_of_year(2022, 2, 29));
      Assert::AreEqual(-1, day_of_year(1984, 5, 59));
      Assert::AreEqual(-1, day_of_year(1999, 11, 0));
      Assert::AreEqual(-1, day_of_year(1666, 1, -10));
    }

    TEST_METHOD(day_of_year_invalidMonth) {
      Assert::AreEqual(-1, day_of_year(2022, 0, 28));
      Assert::AreEqual(-1, day_of_year(1984, 13, 19));
      Assert::AreEqual(-1, day_of_year(1999, 18, 3));
      Assert::AreEqual(-1, day_of_year(1666, -1, 10));
    }

    TEST_METHOD(day_of_year_invalidYear) {
      Assert::AreEqual(-1, day_of_year(0, 1, 28));
      Assert::AreEqual(-1, day_of_year(-1500, 11, 19));
    }

    TEST_METHOD(day_of_year_validDate) {
      Assert::AreEqual(1, day_of_year(2001, 1, 1));
      Assert::AreEqual(70, day_of_year(1993, 3, 11));
      Assert::AreEqual(365, day_of_year(2013, 12, 31));
    }

    TEST_METHOD(day_of_year_leapYear) {
      Assert::AreEqual(1, day_of_year(2024, 1, 1));
      Assert::AreEqual(71, day_of_year(1992, 3, 11));
      Assert::AreEqual(366, day_of_year(1600, 12, 31));
    }

    TEST_METHOD(month_day_invalidDate) {
      int day = -1;
      int month = -1;

      month_day(0, 0, &month, &day);

      Assert::AreEqual(-1, day);
      Assert::AreEqual(-1, month);
    }

    TEST_METHOD(month_day_invalidDay) {
      int day = -1;
      int month = -1;

      month_day(1990, 0, &month, &day);
      Assert::AreEqual(-1, day);
      Assert::AreEqual(-1, month);

      month_day(2020, -332, &month, &day);
      Assert::AreEqual(-1, day);
      Assert::AreEqual(-1, month);

      month_day(1909, 366, &month, &day);
      Assert::AreEqual(-1, day);
      Assert::AreEqual(-1, month);
    }

    TEST_METHOD(month_day_invalidYear) {
      int day = -1;
      int month = -1;

      month_day(0, 332, &month, &day);
      Assert::AreEqual(-1, day);
      Assert::AreEqual(-1, month);

      month_day(-1223, 111, &month, &day);
      Assert::AreEqual(-1, day);
      Assert::AreEqual(-1, month);
    }

    TEST_METHOD(month_day_validDate) {
      int day = -1;
      int month = -1;

      month_day(1993, 70, &month, &day);

      Assert::AreEqual(11, day);
      Assert::AreEqual(3, month);
    }

    TEST_METHOD(month_day_leapYear) {
      int day = -1;
      int month = -1;

      month_day(1992, 71, &month, &day);

      Assert::AreEqual(11, day);
      Assert::AreEqual(3, month);
    }
  };
}
