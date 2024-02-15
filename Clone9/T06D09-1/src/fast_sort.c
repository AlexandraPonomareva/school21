#include <stdio.h>

#define NMAX 10
#define TRUE 1
#define FALSE 0

void input(int* data, int* numbers);
void qsortRecursive(int* a, int n);
void swap(int* a, int* b);
void siftDown(int* numbers, int root, int bottom);
void heapSort(int* numbers, int array_size);
void output(int* data, int* numbers);

int main() {
    int data[NMAX], n = NMAX, numbers[NMAX];
    input(data, numbers);
    qsortRecursive(data, n);
    heapSort(numbers, n);
    output(data, numbers);
}

void input(int* a, int* numbers) {
    for (int i = 0; i < NMAX; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("n/a\n");
        } else {
            numbers[i] = a[i];
        }
    }
}

void output(int* data, int* numbers) {
    for (int i = 0; i < NMAX; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    for (int i = 0; i < NMAX; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void qsortRecursive(int* a, int n) {
    int i = 0;
    int j = n - 1;

    int mid = a[n / 2];

    do {
        while (a[i] < mid) {
            i++;
        }
        while (a[j] > mid) {
            j--;
        }

        if (i <= j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        qsortRecursive(a, j + 1);
    }
    if (i < n) {
        qsortRecursive(&a[i], n - i);
    }
}

void siftDown(int* numbers, int root, int bottom) {
    int maxChild;
    int done = 0;

    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom)
            maxChild = root * 2;

        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;

        if (numbers[root] < numbers[maxChild]) {
            int temp = numbers[root];
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        } else
            done = 1;
    }
}

void heapSort(int* numbers, int array_size) {
    for (int i = (array_size / 2); i >= 0; i--) siftDown(numbers, i, array_size - 1);
    for (int i = array_size - 1; i >= 1; i--) {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}