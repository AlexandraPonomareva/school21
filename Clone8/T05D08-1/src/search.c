/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n, double mea, double vr);
int even(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        return 0;
    };

    double m = mean(data, n);
    double v = variance(data, n);
    output(data, n, m, v);

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 && *n <= 10) {
        printf("n/a");
        return 1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            printf("n/a\n");
            return 1;
        }
    }
    return 0;
}

void output(int *a, int n, double mea, double vr) {
    for (int i = 0; i < n; i++) {
        if (*(a + i) % 2 == 0 && *(a + i) >= mea && *(a + i) <= mea + 3 * sqrt(vr) && *(a + i) != 0) {
            printf("%d\n", *(a + i));
        }
    }
}

double mean(int *a, int n) {
    double m = 0;
    for (int i = 0; i < n; i++) {
        m += a[i];
    }
    double k = m / n;
    return k;
}

double variance(int *a, int n) {
    double m = 0;
    double s = 0;
    double r = 0;
    for (int i = 0; i < n; i++) {
        m = m + a[i];
    }
    s = m / n;
    for (int i = 0; i < n; i++) {
        r += ((a[i] * a[i]) - (s * s));
    }
    return r / n;
}
