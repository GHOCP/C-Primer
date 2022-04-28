#include<stdio.h>
#define STOP '#'

int main(void) {

    int num_nl, num_space, num_other;
    char ch;

    num_nl = num_space = num_other = 0;

    printf("Enter some text; enter # to quit.\n");
    while ((ch = getchar()) != '#') {
            switch (ch) {
                case ' ' :
                    num_space++;
                    break;
                case '\n' :
                    num_nl++;
                    break;
                default :
                    num_other++;
            }
    }
    printf("space(s): %d \n newline(s): %d \n other character(s): %d", num_space, num_nl, num_other);

    return 0;
}
