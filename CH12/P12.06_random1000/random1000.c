/*
    a program that generates 1,000 random numbers in the range 1¨C10
    print how many times each number was produced
    (Have the program do this for 10 different seed values)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    int result[10];
    unsigned int seed[9];

    /* initialize the result and seed array */
    for (int i = 0; i <= 9; i++)
        result[i] = 0;

    seed[0] = (unsigned int) time(0);   // use time() to refresh the seed
    for (int i = 1; i <= 9; i++)
        seed[i] = seed[i-1] + 1;

    /* generate 10000 numbers */
    for (int k = 0; k <= 9; k++) {
        srand(seed[k]);
        for (int j = 1; j <= 100; j++)
            result[rand() % 10]++;
    }

    /* display the result */
        printf("number    count\n");
    for (int i = 0; i <= 9; i++)
        printf("%3d:     %5d\n", i+1, result[i]);

    return 0;
}

