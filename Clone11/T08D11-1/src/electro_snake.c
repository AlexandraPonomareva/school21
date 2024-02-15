#include <stdio.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
//void sort_horizontal(int **matrix, int n, int m, int **result_matrix);


void input(int **matrix);
void output(int **matrix, int n, int m);


int main()
{
    int **matrix, **result;
    int n,m;

    input(matrix);
    
    sort_vertical(matrix, n, m, result);
    output(matrix, m, n);
    
    //sort_horizontal(matrix, n, m, result);
    //output(result);
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {

    int index = 0; 
    for (int j = n - 1; j >= 0; j--) {
        // Если столбец четный, проходимся по строкам сверху вниз
        if (j % 2 == 0) {
            for (int i = 0; i < m; i++) {
                matrix[index][j] = matrix[i][j];
                index++;
            }
        }
        // Если столбец нечетный, проходимся по строкам снизу вверх
        else {
            for (int i = m - 1; i >= 0; i--) {
                matrix[index][j] = matrix[i][j];
                index++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void output(int **matrix, int n, int m) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void input(int **matrix) {
    int m,n;

    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}