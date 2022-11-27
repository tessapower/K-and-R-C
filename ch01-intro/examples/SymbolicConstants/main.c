#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
  printf(" Celsius | Fahrenheit\n");
  printf("---------+------------\n");
  for (float celsius = UPPER; celsius >= LOWER; celsius -= STEP) {
    printf("%8.0f | %11.1f\n", celsius, (9.0 / 5.0) * (celsius + 32.0));
  }

  return 0;
}
