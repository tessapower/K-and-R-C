#include <stdio.h>

float celsiustofahr(int celsius);

// Print Celsius - Fahrenheit table for celsius = 0, 20, ..., 300
// Exercise 1-15: Rewrite the temperature conversion program to use a function.
int main() {
  int lower = 0;
  int upper = 300;
  int step = 20;
  int celsius = lower;
  float fahr;

  printf(" Celsius | Fahrenheit\n");
  printf("---------+------------\n");
  while (celsius <= upper) {
    fahr = celsiustofahr(celsius);
    printf("%8i | %11.1f\n", celsius, fahr);
    celsius += step;
  }

  return 0;
}

float celsiustofahr(int celsius) { return (9.0f / 5.0f) * (celsius + 32.0f); }
