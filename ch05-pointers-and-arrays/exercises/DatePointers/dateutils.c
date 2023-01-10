#include "dateutils.h"

#include <stdio.h>

// Exercise 5-9: Rewrite the routines day_of_year and month_day with pointers
//  instead of indexing.

static char daytable[][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(const int year, const int month, const int day) {
  // Return error value if the month or year is nonsensical
  if (month < 1 || month > 12 || year < 1) return -1;

  // Subscript into the correct array of daytable
  int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  char *dt = daytable[leap];

  // Return error value if the day for the given month is nonsensical
  if (day < 1 || day > dt[month]) return -1;

  int d = day;
  int m = month;
  while (m--)
    d += *dt++;

  return d;
}

void month_day(const int year, const int yearday, int* pmonth, int* pday) {
  int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  // Return early if the year or yearday is nonsensical
  if (year < 1 || yearday < 1 
    || (leap ? yearday > 366 : yearday > 365))
    return;

  char *dt = daytable[leap];
  int d = yearday;
  while (d > *++dt) {
    d -= *dt;
  }

  *pmonth = dt - *(daytable + leap);
  *pday = d;
}
