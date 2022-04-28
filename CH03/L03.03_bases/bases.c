/* showing a value in different bases(10, 8, 16) */
#include <stdio.h>

int main(void) {

    int x = 10;
    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);

    return 0;
}
