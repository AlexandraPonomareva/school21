#include <stdio.h>
int graphic(int pos_ball_x, int left_position, int right_position, int score_player_left, int score_player_right) {
    int WIDTH_SCRING = 80; //Ширина поля
    int HEIGHT_SCRING = 25; //Высота поля
    int HEIGHT_SCOPE = 3; //Высота табла с очками
    int START_INPUT_EXIT = 5; //Позиция, с которой мы начинаем печатать текст с условиями
    int START_INPUT_SCOPE = 19; //Позиция, с которой мы начинаем печатать очки
    int NUMBER_SCOPE_CHARACTERS = 55;
    //int ROCKET1_DEFAULT_X = 2;
    //int ROCKET2_DEFAULT_X = (WIDTH_SCRING - 3);
    // int pos_rocket_left = 12;
    // int pos_rocket_right = 12;
    // int pos_ball_x = 40;
    // int pos_ball_y = 12;
    // int score_player_left = 0;
    // int score_player_right = 0;
    // int left_position = 0;
    // int right_position = 0;

    for (int y = 0; y < HEIGHT_SCOPE; ++y) {
        for (int x = 0; x < WIDTH_SCRING; ++x) {
            if ((y == 0 && x != 0 && x != WIDTH_SCRING - 1) ||
                (y == HEIGHT_SCOPE - 1 && x != 0 && x != WIDTH_SCRING - 1) ) {
                printf("-");
            } else if (((x == 0 && y != 0 && y != HEIGHT_SCOPE - 1))) {
                printf("|");
            } else if (x == START_INPUT_EXIT) {
                printf("НАЖМИ \'Control + c\' ДЛЯ ВЫХОДА. ПРАВИЛА УПРАВЛЕНИЯ: A/Z, K/M!            |");
            } else if (y == 1 && x < WIDTH_SCRING - NUMBER_SCOPE_CHARACTERS) {
                printf(" ");
            } else if (y != 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int y = 0; y < HEIGHT_SCOPE; ++y) {
        for (int x = 0; x < WIDTH_SCRING; ++x) {
            if ((y == 0 && x != 0 && x != WIDTH_SCRING - 1) ||
                (y == HEIGHT_SCOPE - 1 && x != 0 && x != WIDTH_SCRING - 1) ) {
                printf("-");
            } else if (((x == 0 && y != 0 && y != HEIGHT_SCOPE - 1))) {
                printf("|");
            } else if (x == START_INPUT_EXIT) {
                printf("СЧЁТ 1 ИГРОКА:%d                    |", score_player_left);
            } else if (x == START_INPUT_SCOPE) {
                printf("СЧЁТ 2 ИГРОКА:%d         |", score_player_right);
            } else if (y == 1 && x < WIDTH_SCRING - NUMBER_SCOPE_CHARACTERS) {
                printf(" ");
            } else if (y != 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int h = 0; h < WIDTH_SCRING; h++) {
        for ( int l = 0; l < HEIGHT_SCRING; l++) {
            if (h == 0 || h == HEIGHT_SCRING - 1) {
                printf("-");
            } else if (((h == left_position || h == left_position + 12|| h == left_position - 12 || h == left_position + 11 || h == left_position + 13) && l == 1) || ((h == right_position || h == right_position + 12 || h == right_position - 12 || h == right_position + 11 || h == right_position + 13) && l == 78 ) || ((l == 40 && h > 0 && h != 12 && h < 24 )) || ((l == 0 || l == 79) && (h > 0 && h < 24) )) {
                printf("|");
            } else if (h == 12 && l == pos_ball_x) {
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
    int pos_ball_x = 40, left_position = 0, right_position = 0, score_player_left = 0, score_player_right = 0;
    graphic( pos_ball_x,  left_position,  right_position,  score_player_left,  score_player_right);
    return 0;
}