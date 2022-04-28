#include <stdio.h>

double larger_of(double *, double *);

int main(void) {

    double a, b;

    printf("please input two doubles a and b(input 'q' to quit): ");
    while (scanf("%lf %lf", &a, &b) == 2) {
        printf("after the function execuation, a and b become %4.4lf\n", larger_of(&a, &b));
        printf("a becomes %4.4lf, ", a);
        printf("b becomes %4.4lf\n", b);
        printf("please input two doubles a and b(input 'q' to quit): ");
    }
    printf("DONE!");

    return 0;
}

double larger_of(double * a, double * b) {
    double larger;
    larger = (*a > *b)? *a : *b;
    *a = larger;
    *b = larger;
    return larger;
}
