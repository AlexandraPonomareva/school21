#include <stdio.h>

int maks();

int main() {
  int a, b;
  if (scanf("%d %d", &a, &b) != 2) {
    printf("n/a");

    return 0;
  };

  maks(a, b);

  return 0;
}

int maks(int a, int b) {
  if (a > b) {
    printf("%d", a);
  } else {
    printf("%d", b);
  };

  return 0;
}