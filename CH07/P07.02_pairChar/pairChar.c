#include<stdio.h>
#define STOP '#'

int main(void) {

    int num;
    char ch;

    num = 0;

    printf("Enter some text; enter # to quit.\n");
    while ((ch = getchar()) != '#') {
            num++;
            printf("%c:%d ", ch, ch);
            if (num % 8 == 0){
                printf("\n");
            }
    }

    printf("\nDone!");

    return 0;
}
