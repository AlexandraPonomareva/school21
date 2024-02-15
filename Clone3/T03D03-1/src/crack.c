#include <stdio.h>

int main() {

  int R = 25;
  float x, y;

  scanf("%f %f", &x, &y);
  if ((x * x) + (y * y) <= R) {
    printf("GOTCHA\n");
  } else {
    printf("MISS\n");
  }

  return 0;
}




