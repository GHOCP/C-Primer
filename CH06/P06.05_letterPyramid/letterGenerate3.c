/* a char pyramid generating */
#include <stdio.h>
#include <string.h>

void space_print (int i);

int main(void) {

    int i, num, num_r;
    char inp;
    char start, starter;

    printf("Please enter a character to form the pyramid:");
    scanf("%c", &inp);

    /* check out the input character to originate the started character */
    if (isupper(inp))
        starter = 'A';
    else
        starter = 'a';

    start = starter;
    num = inp - start + 1;        // number of rows
    num_r = num*2 - 1;            // number of letters per row (including spaces)

    for (i = 1; i <= num; i++) {     // i is the NO. of row

        /* generate the spaces on the left */
        space_print(num-i);

        /* generate the letters */
        for (int k = 1; k <= i; k++, start++)
            printf("%c", start);    // ascending order
        start = start - 2;
        for (int k = 1; k < i; k++, start--)
            printf("%c", start);    // descending order

        /* generate the spaces on the right */
        space_print(num-i);

        printf("\n");
        start = starter;        // recover the start
    }

    return 0;
}

/* space generator */
void space_print (int j) {
    for (int i = 1; i <= j; i++)
        printf(" ");
}
