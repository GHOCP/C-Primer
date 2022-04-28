// variadic.c -- variadic macros
#include <stdio.h>
#include <math.h>
#define PR(X, ...) printf("Message " #X ": " __VA_ARGS__) // _ _VA_ARGS_ _ is invalid

int main(void) {

    double x = 48;
    double y;
    y = sqrt(x);
    PR(1, "x = %f\n", x);
    PR(2, "x = %.2f, y = %.4f\n", x, y);

    return 0;
}
