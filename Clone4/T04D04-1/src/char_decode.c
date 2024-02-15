#include <math.h>
#include <stdio.h>

void encode(char ch) {
  int firstDigit = ch / 16;
  int secondDigit = ch % 16;
  printf("%X%X ", firstDigit, secondDigit);
}

void decode(char firstDigit, char secondDigit) {
  int num = 0;
  if (firstDigit >= '0' && firstDigit <= '9') {
    num += (firstDigit - '0') * 16;
  } else if (firstDigit >= 'A' && firstDigit <= 'F') {
    num += (firstDigit - 'A' + 10) * 16;
  }
  if (secondDigit >= '0' && secondDigit <= '9') {
    num += (secondDigit - '0');
  } else if (secondDigit >= 'A' && secondDigit <= 'F') {
    num += (secondDigit - 'A' + 10);
  }
  printf("%c ", num);
}

int main() {
  int choice;
  char ch;

  printf("Определите операцию (1 или 0): ");
  scanf(" %d", &choice);

  if (choice == 0) {
    printf("Введите текс: ");
    while (scanf(" %c", &ch) == 1 && ch != '\n') {
      encode(ch);
    }
  } else if (choice == 1) {
    printf("Введите код: ");
    char first, second;
    while (scanf(" %c%c", &first, &second) == 2 && first != '\n') {
      decode(first, second);
    }
  } else {
    printf("Неверно!\n");
    return 1;
  }

  return 0;
}