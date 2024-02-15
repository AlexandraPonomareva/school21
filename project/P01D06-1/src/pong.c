//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI

#include <stdio.h>

#define WIDTH 25
#define LENGTH 80

int graphic(int ball, int left, int right) {

    for (int h = 0; h < WIDTH; h++) {
        for ( int l = 0; l < LENGTH; l++) {
            if (h == 0 || h == 24) {
                printf("-");
            } else if (((h == left || h == left + 12 || h == left - 12) && l == 0) || ((h == right || h == right + 12 || h == right - 12) && l == 79 )) {
                printf("|");
            } else if (h == 12 && l == ball) {
                printf("o");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

int main(){
    int ball = 40 , left = 0 , right = 0;
    graphic(ball, left, right);
    return 0;
}