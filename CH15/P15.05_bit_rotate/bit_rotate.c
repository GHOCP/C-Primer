/*
    Write a function that rotates the bits of an unsigned int by a specified number of bits
    to the left. For instance, rotate_l(x,4) would move the bits in x four places to the left,
    and the bits lost from the left end would reappear at the right end. That is, the bit moved
    out of the high-order position is placed in the low-order position. Test the function in a
    program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // for CHAR_BIT, # of bits per char

void rotate(unsigned int, int);
void show_bstr(const char *);

int main(void) {

    unsigned int n = 1254145789;
    int position = 5;
    rotate(n, position);

    return 0;
}

void rotate(unsigned int num, int pos) {
    int m = num;
    int count = pos;
    const int bit_num = CHAR_BIT * sizeof(unsigned int);
    char bit_form[bit_num + 1];             // binary form of num
    char bit_form_rotated[bit_num + 1];     // binary form of num after being rotated
    char bit_form_pushed[pos + 1];            // the bits being pushed

    /* if the bit position is invalid */
    if (pos < 0 || pos > bit_num) {
        fprintf(stderr, "Invalid number of rotated place(s)!");
        exit(1);
    }

    /* convert the num to binary form(char array) */
    printf("The binary form of %d is:\n", num);
    for (int i = bit_num -1 ; i >= 0; i--) {
        bit_form[i] = (num & 01) + '0';
        num >>= 1;
    }
    bit_form[bit_num] = '\0';
    show_bstr(bit_form);
    putchar('\n');

    /* rotate to the left for n bits */
    strncpy(bit_form_pushed, bit_form, pos);
    bit_form_pushed[pos] = '\0';
        /* moving left */
    printf("The binary form of %d after moveing left for %d bits is:\n", m, pos);
    m <<= pos;
    for (int i = bit_num -1 ; i >= 0; i--) {
        bit_form_rotated[i] = (m & 01) + '0';
        m >>= 1;
    }
    bit_form_rotated[bit_num] = '\0';
    show_bstr(bit_form_rotated);
    putchar('\n');
        /* recover the pushed out */
    printf("Recover the pushed out:\n");
    for (int i = bit_num - 1; i > bit_num - pos; i--, count--)
        bit_form_rotated[i] = bit_form_pushed[count - 1];
    show_bstr(bit_form_rotated);
}

/* show binary string in blocks of 4 */
void show_bstr(const char * str) {
    int i = 0;
    while (str[i]) { /* not the null character */
        putchar(str[i]);
        if(++i % 4 == 0 && str[i])
            putchar(' ');
    }
}
