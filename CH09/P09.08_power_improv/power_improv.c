#include <stdio.h>

double power (double, int);

int main(void) {

    double inp;
    int pow;

    printf("please input a double number and a power(input 'q' to quit):");
    while (scanf("%lf %d", &inp, &pow) == 2) {
        printf(" %lf ^ %d is %lf\n", inp, pow, power(inp, pow));
        printf("please input a double number and a power(input 'q' to quit):");
    }
    printf("DONE!");

    return 0;
}

double power (double inp, int pow) {

    if (inp != 0 && pow == 0)
        return 1;
    else if (inp == 0 && pow != 0 )
        return 0;
    else if (inp == 0 && pow == 0)
        return 1;
    else {
        double result;
        int flag;
        flag = (pow > 0)? pow : pow*(-1) ;

        if (flag > 0)
            return result = inp * power(inp, flag-1);
        else {
            return inp;
        }
    }
}
