#include <stdio.h>

// Print Celsius - Fahrenheit table for celsius = 0, 20, ..., 300
// Exercise 1-5: Modify the temperature conversion program to print the table
//   in reverse order, that is from 300 degrees to 0.
int main() {
  const int lower = 0;
  const int upper = 300;
  const int step = 20;

  printf(" Celsius | Fahrenheit\n");
  printf("---------+------------\n");
  for (int celsius = upper; celsius >= lower; celsius -= step) {
    printf("%8i | %11.1f\n", celsius, (9.0f / 5.0f) * (celsius + 32.0f));
  }

  return 0;
}
