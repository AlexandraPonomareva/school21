#include <stdio.h>

#define NMAX 10
#define TRUE 1
#define FALSE 0

void input(int* data);
void bubble_sortirovka(int* data, int* n);
void swap(int* a, int* b);
void output(int* data);

int main() {
    int data[NMAX], n = NMAX;

    input(data);
    bubble_sortirovka(data, &n);
    output(data);
}

void bubble_sortirovka(int* data, int* n) {
    for (int i = 0; i < *n - 1; i++) {
        for (int j = 0; j < *n - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data + j, data + j + 1);
            }
        }
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void input(int* data) {
    for (int i = 0; i < NMAX; i++) {
        if (scanf("%d", &data[i]) != 1 || *data >= 11) {
            printf("n/a\n");
        }
    }
}

void output(int* data) {
    for (int i = 0; i < NMAX; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}