#include <stdio.h>

// Print Celsius - Fahrenheit table for celsius = 0, 20, ..., 300
// Exercise 1-4: Write a program to print the corresponding Celsius to
//   Fahrenheit table.
int main() {
  int lower = 0;
  int upper = 300;
  int step = 20;
  float celsius = lower;
  float fahr;

  printf(" Celsius | Fahrenheit\n");
  printf("---------+------------\n");
  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * (celsius + 32.0);
    printf("%8.0f | %11.1f\n", celsius, fahr);
    celsius += step;
  }

  return 0;
}
