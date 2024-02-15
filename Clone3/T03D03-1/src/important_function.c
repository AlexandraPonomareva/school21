#include <math.h>
#include <stdio.h>

float comprt(float);

int main() {

  float x;

  if (scanf("%f", &x) != 1) {
    printf("n/a");

    return 0;
  };

  comprt(x);

  return 0;
}

float comprt(float x) {

  float y;

  y = 7e-3 * pow(x, 4) +
      ((22.8 * pow(x, (1 / 3)) - 1e3) * x + 3) / (x * x / 2) -
      x * pow((10 + x), (2 / x)) - 1.01;
  printf("%.1lf", y);

  return 0;
}
