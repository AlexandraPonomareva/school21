#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        return 0;
    };
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

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
        };
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int max(int *a, int n) {
    int x = a[0];
    for (int i = 0; i < n; i++) {
        if (x > a[i]) {
            x = a[0];
        } else {
            x = a[i];
        }
    }
    return x;
}

int min(int *a, int n) {
    int x = a[0];
    for (int i = 0; i < n; i++) {
        if (x < a[i]) {
            x = a[0];
        } else {
            x = a[i];
        }
    }
    return x;
}

double mean(int *a, int n) {
    double m = 0;
    for (int i = 0; i < n; i++) {
        m += a[i];
    }
    return m / n;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}