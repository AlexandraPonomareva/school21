#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n);
void input(double ***matrix, int *n, int *m);
void output(double det);

int main() {
    double **matrix;
    int n, m;

    input(&matrix, &n, &m);
    if (det(matrix, n) >= 0) {
        output(fabs(det(matrix, n)));
    } else {
        output((det(matrix, n)));
    };
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

void input(double ***matrix, int *n, int *m) {
    if (scanf("%d %d", n, m) != 2) {
        printf("n/a");
    }
    *matrix = malloc(*n * sizeof(int *));
    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = malloc(*m * sizeof(int));
        for (int j = 0; j < *m; j++) {
            if (scanf("%le", &((*matrix)[i][j])) != 1) {
                printf("n/a");
            }
            break;
        }
    }
}

void output(double det) { printf("%lf", det); }

double det(double **matrix, int n) {
    int i, j, k;
    double t, det;
    for (k = 0; k < n; k++) {
        for (i = k + 1; i < n; i++) {
            t = matrix[i][k] / matrix[k][k];
            matrix[i][k] = 0;
            for (j = k + 1; j < n; j++) {
                matrix[i][j] = matrix[i][j] - t * matrix[k][j];
            }
        }
    }
    det = 1.0;
    for (k = 0; k < n; k++) {
        det = det * matrix[k][k];
    }
    return det;
}