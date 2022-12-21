#ifndef DATEUTILS_H
#define DATEUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

  /**
   * @brief Set the day of the year from month & day.
  */
  int day_of_year(const int year, const int month, const int day);

  /**
   * @brief Set month, day from day of year.
  */
  void month_day(const int year, const int yearday, int* pmonth, int* pday);

#ifdef __cplusplus
}
#endif

#endif // DATEUTILS_H
