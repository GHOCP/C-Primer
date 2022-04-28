/* binbit.c -- using bit operations to display binary */
#include <stdio.h>
#include <limits.h> // for CHAR_BIT, # of bits per char

char * itobs(int, char *);
void show_bstr(const char *);

int main(void) {
    char bin_str[CHAR_BIT * sizeof(int) + 1];       // The sizeof operator returns the size in terms of char, so the expression
                                                    // CHAR_BIT * sizeof(int) is the number of bits in an int.
                                                    // plus 1 to allow for the terminating null character
    int number;
    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    while (scanf("%d", &number) == 1) {
        itobs(number,bin_str);
        printf("%d is ", number);
        show_bstr(bin_str);
        putchar('\n');
    }
    puts("Bye!");

    return 0;
}

char * itobs(int n, char * ps) {
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0'; // assume ASCII or similar
                                // The term 01 is the octal representation of a mask with all but the zero
                                // bit set to 0. Therefore, 01 & n is just the value of the final bit in n .
    ps[size] = '\0';
    return ps;
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
