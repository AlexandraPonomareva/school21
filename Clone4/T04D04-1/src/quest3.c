#include <stdio.h>
int fib(int n) {
    if (n < 2) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
        
}

int main() {
    int num;
    scanf("%d",&num );
    num = fib(num);
    printf("%d\n", num);
    return 0;
}