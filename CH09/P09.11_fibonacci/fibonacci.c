#include <stdio.h>

unsigned long Fibonacci_recur (unsigned);
unsigned long Fibonacci_loop (unsigned);

int main(void) {

    unsigned n;

    printf("Please input a number and I will show you the corresponding Fibonacci number('q') to quit:");
    while (scanf("%lu", &n) == 1) {
        printf ("The Fibonacci number of %u is %lu (recursion counting)\n",
                n, Fibonacci_recur(n));
        printf ("The Fibonacci number of %u is %lu (loop counting)\n",
                n, Fibonacci_loop(n));
        printf("Please input a number and I will show you the corresponding Fibonacci number('q') to quit:");
    }


    return 0;
}

unsigned long Fibonacci_recur (unsigned n) {
    if (n > 2)
        return Fibonacci_recur(n-1) + Fibonacci_recur(n-2);
    else
        return 1;
}

unsigned long Fibonacci_loop (unsigned n) {

    unsigned long prev = 1;
    unsigned long now = 1;
    unsigned long result;

    if (n == 1) {
        result = 1;
    }
    else if (n == 2) {
        result = 1;
    }
    else {
        for (int i = 1; i < n-1; i++) {
            result = prev + now;
            prev = now;
            now = result;
        }
    }

    return result;
}
