/*
    The ANSI library features a clock() function with this description:
    #include <time.h>

    clock_t clock (void);

    Here, clock_t is a type defined in time.h . The function returns the processor time,
    which is given in some implementation-dependent units. (If the processor time is
    unavailable or cannot be represented, the function returns a value of -1 .) However,
    CLOCKS_PER_SEC , also defined in time.h , is the number of processor time units per
    second. Therefore, dividing the difference between two return values of clock() by
    CLOCKS_PER_SEC gives you the number of seconds elapsed between the two calls.

    Typecasting the values to double before division enables you to get fractions of a second.
    Write a function that takes a double argument representing a desired time delay and
    then runs a loop until that amount of time has passed. Write a simple program that tests
    the function.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int time_elapse(double);

int main(void) {

    double time;
    int flag;
    printf("Please enter a time: ");
    while (scanf("%lf", &time) == 1) {
        if ((flag = time_elapse(time)) == -1)
            exit(EXIT_FAILURE);
        else
            continue;
    }

    return 0;
}

int time_elapse(double time) {
    clock_t start = clock();
    clock_t mark = clock();
    if (start == -1 || mark == -1)
        return -1;
    while (((double)(mark - start)) / CLOCKS_PER_SEC < time)
        mark = clock();
    printf("start time: %lf end time: %lf\n", (double)start, (double)mark);
    return 1;
}
