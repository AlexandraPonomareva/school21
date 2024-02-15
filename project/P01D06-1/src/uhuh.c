#include <stdio.h>

void rendering_screen(int pos_rocket_left, int pos_rocket_right, int pos_ball_x,
                      int pos_ball_y);
void clear_screen(void);
int pong_field(int HEIGHT_SCRING, int WIDTH_SCRING, int left_position,
               int pos_ball_x, int right_position);
int print_boards_with_rules_and_points(int score_player_left,
                                       int score_player_right);

int main() {
  int WIDTH_SCRING = 80;  //Ширина поля
  int HEIGHT_SCRING = 25; //Высота поля
  int START_POS_LEFT_ROCKET = 5; //Начальные координаты левой ракетки
  int START_POS_RIGHT_ROCKET = 12; //Начальные координаты правой ракетки
  int ROCKET1_DEFAULT_X = 2;
  int ROCKET2_DEFAULT_X = (WIDTH_SCRING - 3);
  int WINSCORE = 21; //Количество очков для победы

  int pos_rocket_left = START_POS_LEFT_ROCKET;
  int pos_rocket_right = START_POS_RIGHT_ROCKET;
  int pos_ball_x = (WIDTH_SCRING / 2); //Половина от ширины поля
  int pos_ball_y = (HEIGHT_SCRING / 2); //Половина от высоты поля
  int vector_x = -1;
  int vector_y = 1;

  int score_player_left = 0;
  int score_player_right = 0;

  while (1) {
    print_boards_with_rules_and_points(score_player_left, score_player_right);
    rendering_screen(pos_rocket_left, pos_rocket_right, pos_ball_x, pos_ball_y);

    char temp = getchar();

    if (temp == 'a' && pos_rocket_left != 2) {
      pos_rocket_left -= 1;
    }
    if (temp == 'z' && pos_rocket_left != HEIGHT_SCRING - 3) {
      pos_rocket_left += 1;
    }
    if (temp == 'k' && pos_rocket_right != 2) {
      pos_rocket_right -= 1;
    }
    if (temp == 'm' && pos_rocket_right != HEIGHT_SCRING - 3) {
      pos_rocket_right += 1;
    }

    if (pos_ball_y == 1 || pos_ball_y == HEIGHT_SCRING - 2) {
      vector_y = -(vector_y);
    }

    //если столкновение с игрком1 (слева), направление по Х становится
    //противоположным (отскок)
    if (pos_ball_x == ROCKET1_DEFAULT_X + 1 &&
        (pos_ball_y == pos_rocket_left - 1 || pos_ball_y == pos_rocket_left ||
         pos_ball_y == pos_rocket_left + 1)) {
      vector_x = -(vector_x);
    }

    //если столкновение с игрком2 (справа), направление по Х становится
    //противоположным (отскок)
    if (pos_ball_x == ROCKET2_DEFAULT_X - 1 &&
        (pos_ball_y == pos_rocket_right - 1 || pos_ball_y == pos_rocket_right ||
         pos_ball_y == pos_rocket_right + 1)) {
      vector_x = -(vector_x);
    }

    //делаем шажок по направлению с соответсвии с измеёнными или прежними (не
    //вощло в if) результатами вектора
    pos_ball_y += vector_y;
    pos_ball_x += vector_x;

    clear_screen();

    if (pos_ball_x > WIDTH_SCRING - 3) {
      score_player_left += 1;
      pos_ball_x = (WIDTH_SCRING / 2);
      pos_ball_y = (HEIGHT_SCRING / 2);
    }
    if (pos_ball_x < 2) {
      score_player_right += 1;
      pos_ball_x = (WIDTH_SCRING / 2);
      pos_ball_y = (HEIGHT_SCRING / 2);
    }

    /* Проверяем, если у одного из игроков счет равен WINSCORE
    выводим сообщение о конце игры и завершаем цикл */
    if (score_player_left == WINSCORE || score_player_right == WINSCORE) {
      printf("\nИГРА ЗАКОНЧИЛАСЬ!!! СЧЕТ %d / %d.\n", score_player_left,
             score_player_right);
      break;
    }
  }

  return 0;
}

void rendering_screen(int pos_rocket_left, int pos_rocket_right, int pos_ball_x,
                      int pos_ball_y) {
  /*
      Функция отрисовывает поле исходя из переданных аргументов:
      pos_rocket_left: Положение левой ракетки
      rocket_right: Положение правой ракетки
      pos_ball_x: Расположение мяча по Х
      pos_ball_y: Расположение мяча по Y
      sc_player_l: Счет игрока слева
      sc_player_r: Счет игрока справа
  */
  int WIDTH_SCRING = 80;  //Ширина поля
  int HEIGHT_SCRING = 25; //Высота поля

  int ROCKET1_DEFAULT_X = 2; //Отступ ракетки от левого края
  int ROCKET2_DEFAULT_X = (WIDTH_SCRING - 3); //Отступ ракетки от правого края

  for (int y = 0; y < HEIGHT_SCRING; ++y) {
    for (int x = 0; x < WIDTH_SCRING; ++x) {
      if ((x == ROCKET1_DEFAULT_X &&
           (y == pos_rocket_left - 1 || y == pos_rocket_left ||
            y == pos_rocket_left + 1)) ||
          (x == ROCKET2_DEFAULT_X &&
           (y == pos_rocket_right - 1 || y == pos_rocket_right ||
            y == pos_rocket_right + 1))) {
        printf("|");
      } else if (x == pos_ball_x && y == pos_ball_y) {
        printf("o");
      } else if ((y == 0 && x != 0 && x != WIDTH_SCRING - 1) ||
                 (y == HEIGHT_SCRING - 1 && x != 0 && x != WIDTH_SCRING - 1)) {
        printf("-");
      } else if ((x == 0 && y != 0 && y != HEIGHT_SCRING - 1) ||
                 (x == WIDTH_SCRING - 1 && y != 0 && y != HEIGHT_SCRING - 1) ||
                 (x == WIDTH_SCRING / 2)) {
        printf("|");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int print_boards_with_rules_and_points(int score_player_left,
                                       int score_player_right) {
  int WIDTH_SCRING = 80; //Ширина поля
  int HEIGHT_SCOPE = 3;  //Высота табла с очками
  int START_INPUT_EXIT =
      5; //Позиция, с которой мы начинаем печатать текст с условиями
  int START_INPUT_SCOPE = 19; //Позиция, с которой мы начинаем печатать очки
  int NUMBER_SCOPE_CHARACTERS = 55;

  for (int y = 0; y < HEIGHT_SCOPE; ++y) {
    for (int x = 0; x < WIDTH_SCRING; ++x) {
      if ((y == 0 && x != 0 && x != WIDTH_SCRING - 1) ||
          (y == HEIGHT_SCOPE - 1 && x != 0 && x != WIDTH_SCRING - 1)) {
        printf("-");
      } else if (((x == 0 && y != 0 && y != HEIGHT_SCOPE - 1))) {
        printf("|");
      } else if (x == START_INPUT_EXIT) {
        printf("НАЖМИ \'Control + c\' ДЛЯ ВЫХОДА. ПРАВИЛА УПРАВЛЕНИЯ: A/Z, "
               "K/M!            |");
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
          (y == HEIGHT_SCOPE - 1 && x != 0 && x != WIDTH_SCRING - 1)) {
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

void clear_screen(void) { printf("\33[HJ\33[2J"); }
