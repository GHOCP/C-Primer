#include<stdio.h>

int main(void) {

    char ch_prev, ch;
    int num = 0;

    printf("Please input a text:(enter # to quit):\n");
    ch_prev = getchar();

    /* if the first input is not # */
    if (ch_prev != '#') {
        ch = getchar();

        /* if there is only one character */
        if (ch == '#')
            printf("only one character is input, the number of 'ei' in the text is 0");
        /* noraml situation(two or more characters) */
        else {
            num = num + (ch_prev == 'e' && ch == 'i');
            ch_prev = ch;
            while ((ch = getchar()) != '#') {
                num = num + (ch_prev == 'e' && ch == 'i');
                ch_prev = ch;
            }
            printf("the number of 'ei' in the text is %d", num);
        }
    }
    /* if the first input is # */
    else {
        printf("Nothing has been input!");
    }

    return 0;
}
