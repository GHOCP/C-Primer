/*
    Write a function called transform() that takes four arguments: the name of a source
    array containing type double data, the name of a target array of type double , an int
    representing the number of array elements, and the name of a function (or, equivalently,
    a pointer to a function). The transform() function should apply the indicated function
    to each element in the source array, placing the return value in the target array. For
    example, the call

    transform(source, target, 100, sin);

    would set target[0] to sin(source[0]) , and so on, for 100 elements. Test the function
    in a program that calls transform() four times, using two functions from the math.h
    library and two suitable functions of your own devising as arguments to successive calls
    of the transform() function.
*/

#include <stdio.h>
#include <math.h>
#define LEN 10

void transform(const double [], double [], int, double (*)(double));

int main(void) {

    const double source[LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double target[LEN];

    printf("The source array is:\n");
    for (int i = 0; i < LEN; i++)
        printf("%.2lf ", source[i]);
    putchar('\n');

    printf("After function 1(sin):\n");
    transform(source, target, LEN, sin);
    for (int i = 0; i < LEN; i++)
        printf("%.2lf ", target[i]);
    putchar('\n');

    printf("After function 2(sqrt):\n");
    transform(source, target, LEN, sqrt);
    for (int i = 0; i < LEN; i++)
        printf("%.2lf ", target[i]);
    putchar('\n');

    return 0;
}

void transform(const double src[], double trg[], int n, double (* pf)(double m)) {
    for (int i = 0; i < n; i++)
        trg[i] = (*pf)(src[i]);
}
