#include "data_stat.h"

double max(double *data, int n) {
    int x = data[0];
    for (int i = 0; i < n; i++) {
        if (x > data[i]) {
            x = data[0];
        } else {
            x = data[i];
        }
    }
    return x;
}
double min(double *data, int n) {
    int x = data[0];
    for (int i = 0; i < n; i++) {
        if (x < data[i]) {
            x = data[0];
        } else {
            x = data[i];
        }
    }
    return x;
}
double mean(double *data, int n) {
    double m = 0;
    for (int i = 0; i < n; i++) {
        m += data[i];
    }
    return m / n;
}
double variance(double *data, int n) {
    double m = 0;
    double s = 0;
    double r = 0;
    for (int i = 0; i < n; i++) {
        m = m + data[i];
    }
    s = m / n;
    for (int i = 0; i < n; i++) {
        r += ((data[i] * data[i]) - (s * s));
    }
    return r / n;
}
