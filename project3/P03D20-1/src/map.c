#include <stdio.h>

#define ROWS 25
#define COLS 80

int main() {
    char map = malloc(sizeof(char));
    // Вывод игрового поля
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            map[i][j] = '.';
            printf("%c" , map[i][j]);
        }
        printf("\n");
    }

    return 0;
}



