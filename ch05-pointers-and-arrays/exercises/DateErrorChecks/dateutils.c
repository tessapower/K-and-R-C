#include "dateutils.h"

#include <stdio.h>

// Exercise 5-8: There is no error checking in day_of_year or month_day. Remedy
//  this defect.

static char daytable[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(const int year, const int month, const int day) {
  // Return error value if the month or year is nonsensical
  if (month < 1 || month > 12 || year < 1) return -1;

  // Subscript into the correct array of daytable
  int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  // Return error value if the day for the given month is nonsensical
  if (day < 1 || day > daytable[leap][month]) return -1;
  
  int d = day;
  for (int i = 1; i < month; ++i)
    d += daytable[leap][i];

  return d;
}

void month_day(const int year, const int yearday, int *pmonth, int *pday) {
  int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  // Return early if the year or yearday is nonsensical
  if (year < 1 || yearday < 1 || (leap ? yearday > 366 : yearday > 365)) return;

  int d = yearday;
  int m = 1;
  for (; d > daytable[leap][m]; ++m)
    d -= daytable[leap][m];

  *pmonth = m;
  *pday = d;
}
