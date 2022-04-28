#include <stdio.h>

void to_base_n(int, int);

int main(void) {

    int n;
    int base;

    printf("please input a number and a base(input 'q' to quit):");
    while (scanf("%d %d", &n, &base) == 2) {
        printf("the number %d in base %d is: ", n, base);
        to_base_n(n, base);
        printf("\nplease input a number and a base(input 'q' to quit):");
    }
    printf("DONE!");

    return 0;
}


void to_base_n(int n, int base) {

    int m = n % base;
    if (n >= base) {
        int flag = n / base;
        to_base_n (flag, base);
    }
    printf("%d", m);
}
