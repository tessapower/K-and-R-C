#include <stdio.h>

// Print Fahrenheit - Celsius table for fahr = 0, 20, ..., 300
// Exercise 1-3: Modify the temperature conversion program to print a heading
//   above the table.
int main() {
  const int lower = 0;
  const int upper = 300;
  const int step = 20;

  float fahr = lower;
  float celsius;

  printf(" Fahrenheit | Celsius\n");
  printf("------------+---------\n");
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%11.0f | %8.1f\n", fahr, celsius);
    fahr += step;
  }

  return 0;
}
