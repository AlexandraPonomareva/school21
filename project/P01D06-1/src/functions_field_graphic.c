#include <stdio.h>

int pong_field(int HEIGHT_SCRING, int WIDTH_SCRING, int left_position, int pos_ball_x, int right_position);
int Printf_Boards_With_Rules_And_Points(int HEIGHT_SCOPE, int WIDTH_SCRING, int START_INPUT_EXIT, int NUMBER_SCOPE_CHARACTERS,
int score_player_left, int START_INPUT_SCOPE, int score_player_right);

int main(){
    int pos_ball_x = 40;
	int left_position = 0;
	int right_position = 0;
    int HEIGHT_SCRING = 25;
    int WIDTH_SCRING = 80;

	int HEIGHT_SCOPE = 3;
	int START_INPUT_EXIT = 5;
	int NUMBER_SCOPE_CHARACTERS = 55;

	int score_player_left = 0;
	int START_INPUT_SCOPE = 19;
	int score_player_right = 0;

	Printf_Boards_With_Rules_And_Points(HEIGHT_SCOPE, WIDTH_SCRING, START_INPUT_EXIT, NUMBER_SCOPE_CHARACTERS,
	score_player_left, START_INPUT_SCOPE, score_player_right);

    pong_field(HEIGHT_SCRING, WIDTH_SCRING, left_position, pos_ball_x, right_position);
    return 0;
}


int Printf_Boards_With_Rules_And_Points(int HEIGHT_SCOPE, int WIDTH_SCRING, int START_INPUT_EXIT, int NUMBER_SCOPE_CHARACTERS, int score_player_left, int START_INPUT_SCOPE, int score_player_right) {

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

	// доска со счётом
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
    return 0;
}



int pong_field(int HEIGHT_SCRING, int WIDTH_SCRING, int left_position, int pos_ball_x, int right_position) {

    for (int x = 0; x < HEIGHT_SCRING; x++) {  // тут я поменяла местами WIDTH_SCRING и HEIGHT_SCRING из этих for условий
        for ( int y = 0; y < WIDTH_SCRING; y++) {
            if (x == 0 || x == HEIGHT_SCRING - 1) {
                printf("-");
            } else if (((x == left_position || x == left_position + 12|| x == left_position - 12 || x == left_position + 11 || x == left_position + 13) && y == 1) || ((x == right_position || x == right_position + 12 || x == right_position - 12 || x == right_position + 11 || x == right_position + 13) && y == 78 ) || ((y == 40 && x > 0 && x != 12 && x < 24 )) || ((y == 0 || y == 79) && (x > 0 && x < 24) )) {
                printf("|");
            } else if (x == 12 && y == pos_ball_x) {
                printf("o");
            } else {
                printf(" ");
            } 
        }
        printf("\n");
    }
    return 0;
}