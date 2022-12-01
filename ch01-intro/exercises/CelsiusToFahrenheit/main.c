#include <stdio.h>

// Print Celsius - Fahrenheit table for celsius = 0, 20, ..., 300
// Exercise 1-4: Write a program to print the corresponding Celsius to
//   Fahrenheit table.
int main() {
  const int lower = 0;
  const int upper = 300;
  const int step = 20;

  int celsius = lower;
  float fahr;

  printf(" Celsius | Fahrenheit\n");
  printf("---------+------------\n");
  while (celsius <= upper) {
    fahr = (9.0f / 5.0f) * (celsius + 32.0f);
    printf("%8i | %11.1f\n", celsius, fahr);
    celsius += step;
  }

  return 0;
}
