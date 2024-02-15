#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);
int sum(int matrix_first, int n_first, int m_first, int matrix_second, 
int n_second, int m_second, int **matrix_result, int *n_result, int *m_result);
int transpose(int **matrix, int n, int m);
int mul(int matrix_first, int n_first, int m_first, int matrix_second, 
    int n_second, int m_second, int **matrix_result, int *n_result, int *m_result);

int main()
{
int operation;
int matrix, n, m, matrix1;
int **result_matrix;

switch (operation)
{
case 1: if(matrix != NULL && result_matrix != NULL) {
                    sum(matrix, n, m, matrix1, n, m, result_matrix, &n, &m);
                } else {
                    printf("Ошибка выделения памяти\n");
                }
                break;
case 2: if(matrix != NULL) {
                    output(matrix, n, m);
                } else {
                    printf("Матрица не инициализирована\n");
                }
                break;
        


case 3: if(matrix != NULL && result_matrix != NULL) {
                    mul(matrix, n, m, matrix1, n, m, result_matrix, &n, &m);
                } else {
                    printf("Ошибка выделения памяти\n");
                }
                break;

case 4: if(matrix != NULL) {
                    transpose(matrix, n, m);
                } else {
                    printf("Матрица не инициализирована\n");
                }
                break;

default:
    printf("n/a\n");;

    }
return 0;

}

input(int **matrix, int *n, int *m){
    scanf("%d %d", n, m);
    *matrix = (int *)malloc(*n * *m * sizeof(int));
    if(*matrix == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }
    for(int i = 0; i < *n; i++) {
        for(int j = 0; j < *m; j++) {
            printf("Введите элемент матрицы [%d][%d]: ", i, j);
            scanf("%d", &(*matrix)[i * *m + j]);
        }
    }
    return 0;
}


void output(int **matrix, int n, int m) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int sum(int matrix_first, int n_first, int m_first, int matrix_second, 
    int n_second, int m_second, int **matrix_result, int *n_result, int *m_result) {
    int i, j;
    *n_result = n_first;
    *m_result = m_first;
    *matrix_result = (int *)malloc(*n_result * *m_result * sizeof(int));
    if(*matrix_result == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }
    for(i = 0; i < *n_result; i++) {
        for(j = 0; j < *m_result; j++) {
            (*matrix_result)[i * *m_result + j] = matrix_first[i][j] + matrix_second[i][j];
        }
    }
    return 0;
}

int mul(int matrix_first, int n_first, int m_first, int matrix_second, 
    int n_second, int m_second, int **matrix_result, int *n_result, int *m_result) {
    int i, j, k;
    *n_result = n_first;
    *m_result = m_second;
    *matrix_result = (int *)malloc(*n_result * *m_result * sizeof(int));
    if(*matrix_result == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }
    for(i = 0; i < *n_result; i++) {
        for(j = 0; j < *m_result; j++) {
            (*matrix_result)[i * *m_result + j] = 0;
            for(k = 0; k < m_first; k++) {
                (*matrix_result)[i * *m_result + j] += matrix_first[i][k] * matrix_second[k][j];
            }
        }
    }
    return 0;
}


int transpose(int **matrix, int n, int m) {
    int i, j;
    int transposed_matrix = (int )malloc(n * sizeof(int *));
    if(transposed_matrix == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }
    for(i = 0; i < n; i++) {
        transposed_matrix[i] = matrix[i];
    }
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            int temp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
    return 0;
}