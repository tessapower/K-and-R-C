#include <stdio.h>

// Print Fahrenheit - Celsius table for fahr = 0, 20, ..., 300
int main() {
  int lower = 0;
  int upper = 300;
  int step = 20;
  int fahr = lower;
  float celsius;

  while (fahr <= upper) {
    celsius = (5.0f / 9.0f) * (fahr - 32.0f);
    printf("%11i | %8.1f\n", fahr, celsius);
    fahr += step;
  }

  return 0;
}
