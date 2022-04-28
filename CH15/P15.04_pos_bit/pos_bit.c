/*
    Write a function that takes two int arguments: a value and a bit position. Have the
    function return 1 if that particular bit position is 1, and have it return 0 otherwise. Test
    the function in a program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // for CHAR_BIT, # of bits per char
#define N 21
#define POS 4

int pos_bit(int, int);

int main(void) {

    printf("position: %d of integer %d is: %d", POS, N, pos_bit(N, POS));

    return 0;
}

int pos_bit(int n, int pos) {
    int m = n;
    static const int bit_num = CHAR_BIT * sizeof(int);
    char bit_form[bit_num + 1];

    /* if the bit position is invalid */
    if (pos < 0 || pos >= bit_num) {
        fprintf(stderr, "Invalid bit position!");
        exit(1);
    }

    /* convert the n to binary form(char array) */
    for (int i = bit_num -1 ; i >= 0; i--) {
        bit_form[i] = (n & 01) + '0';
        n >>= 1;
    }
    bit_form[bit_num] = '\0';
    printf("The binary form of %d is: %s\n", m, bit_form);

    /* judge the particular bit position */
    if (bit_form[bit_num -1 - pos] == '1')
        return 1;
    else
        return 0;
}
