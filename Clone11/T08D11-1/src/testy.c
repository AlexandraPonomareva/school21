#include <stdio.h>
#include <stdlib.h>

double determinant(double mat[][-1], int n);
void adjoint(double mat[][-1], double adj[][-1], int n);
void transpose(double mat[][-1], double trans[][-1], int n);

int main() {
    int i, j, n;
    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);
    double mat[-1], adj[-1], inv[-1], trans[-1];
    double det = 0;

    // Input elements of the matrix
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            scanf("%lf", &mat[i][j]);

    // Calculate the determinant
    det = determinant(mat, n);

    if (det == 0) {
        printf("n/a\n");
        return 0;
    }

    // Calculate the adjoint of the matrix
    adjoint(mat, adj, n);

    // Transpose the adjoint matrix
    transpose(adj, trans, n);

    // Multiply transposed adjoint with original matrix
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            inv[i][j] = trans[i][j] / det;

    // Print the inverse of the matrix
    printf("Inverse of the matrix is:\n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j)
            printf("%.6lf ", inv[i][j]);
        printf("\n");
    }

    return 0;
}

// Function to calculate the determinant of a matrix
double determinant(double mat[][-1], int n) {
    double D = 0;
    if (n == 1)
        return mat[0][0];
    double submat[-1];
    int isub = 0;
    for (int x = 0; x < n; x++) {
        int jsub = 0;
        for (int j = 1; j < n; j++) {
            int ipick = 0;
            for (int i = 0; i < n; i++) {
                if (i == x)
                    continue;
                submat[isub][jsub] = mat[i][j];
                jsub++;
                if (jsub == n - 1) {
                    jsub = 0;
                    isub++;
                }
            }
        }
        D += pow(-1, x) * mat[x][0] * determinant(submat, n - 1);
    }

    return D;
}

// Function to calculate the adjoint of a matrix
void adjoint(double mat[][-1], double adj[][-1], int n) {
    if (n == 1) {
        adj[0][0] = 1;
        return;
    }

    double submat[-1];
    int sign = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int subi = 0, subj = 0;
            for (int m = 0; m < n; m++) {
                if (m == i)
                    continue;
                for (int n = 0; n < n; n++) {
                    if (n == j)
                        continue;
                    submat[subi][subj] = mat[m][n];
                    subj++;
                    if (subj == n - 1) {
                        subj = 0;
                        subi++;
                    }
                }
            }
            adj[j][i] = ((i + j) % 2 ? -1 : 1) * determinant(submat, n - 1);
        }
    }
}

// Function to calculate the transpose of a matrix
void transpose(double mat[][-1], double trans[][-1], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            trans[i][j] = mat[j][i];
}
