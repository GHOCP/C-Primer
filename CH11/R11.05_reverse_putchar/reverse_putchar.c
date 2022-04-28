/* testing the reverse_putchar() */
#include <stdio.h>
#include <string.h>

char * pr(char *);
char * pr_new(char *);

int main(void) {

    char * x, y;
    x = pr("Ho Ho Ho!");
    putchar('\n');
    y = pr_new("Ho Ho Ho!");

    putchar('\n');
    printf("&x = %p  &y = %p", x, y);

    return 0;
}


char * pr(char *str) {
    char *pc;
    pc = str;
    while (*pc)
        putchar(*pc++);
    do {
        putchar(*--pc);
    } while (pc - str);
    return (pc);
}

char * pr_new(char *str) {
    char *pc;
    pc = str;
    while (*pc)
        putchar(*pc++);
    do {
        putchar(*pc--);
    } while (pc - str);
    return (pc);
}
