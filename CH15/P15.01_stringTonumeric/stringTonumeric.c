/*
    Write a function that converts a binary string to a numeric value. That is, if you have
    char * pbin = "01001001";

    you can pass pbin as an argument to the function and have the function return an int
    value of 25 .
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int convert(char *, int);

int main(void) {
    char * string1 = "01001001";
    char * string2 = "11111111";

    printf("%s: %d\n", string1, convert(string1, strlen(string1)));
    printf("%s: %d\n", string2, convert(string2, strlen(string2)));

    return 0;
}

int convert(char * string, int n) {
    int result = 0;
    int num;
    for (int i = 0; i < n; i++ ) {
        num = *(string + i) - '0';
        if (num > 1) {
            fprintf (stderr, "The string you input is not binary.");
            exit(1);
        }
        result = result + (int)num * pow(2, (n-1-i));
    }
    return result;
}
