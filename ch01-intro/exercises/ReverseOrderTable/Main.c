#include <stdio.h>

// Print Celsius - Fahrenheit table for celsius = 0, 20, ..., 300
// Exercise 1-5: Modify the temperature conversion program to print the table
//   in reverse order, that is from 300 degrees to 0.
int main() {
  int lower = 0;
  int upper = 300;
  int step = 20;

  printf(" Celsius | Fahrenheit\n");
  printf("---------+------------\n");
  for (float celsius = upper; celsius >= lower; celsius -= step) {
    printf("%8.0f | %11.1f\n", celsius, (9.0 / 5.0) * (celsius + 32.0));
  }

  return 0;
}
