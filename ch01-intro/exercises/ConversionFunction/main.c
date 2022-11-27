#include <stdio.h>

float celsiustofahr(int celsius);

// Print Celsius - Fahrenheit table for celsius = 0, 20, ..., 300
// Exercise 1-15: Rewrite the temperature conversion program to use a function.
int main() {
  int lower = 0;
  int upper = 300;
  int step = 20;
  float celsius = lower;
  float fahr;

  printf(" Celsius | Fahrenheit\n");
  printf("---------+------------\n");
  while (celsius <= upper) {
    fahr = celsiustofahr(celsius);
    printf("%8.0f | %11.1f\n", celsius, fahr);
    celsius += step;
  }

  return 0;
}

float celsiustofahr(int celsius) { return (9.0 / 5.0) * (celsius + 32.0); }
