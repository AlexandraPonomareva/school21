#include <stdio.h>
#include <math.h>

int Npd(int a) {

    int b = 2;

    while(a >= b * b) {
        if(a % b == 0){
            a = a / b;
        }else{
            b += 1;
        }
    }
    return a;



}

int main() {

    int a;
    if (scanf("%d", &a) != 1) {
        printf("n/a");
        return 0;
    }
    if(a < 0){
        a = a * -1;
        int rez = Npd(a);
        printf("%d\n", rez);
    } else{
        int rez = Npd(a);
        printf("%d\n", rez);
    }
}

