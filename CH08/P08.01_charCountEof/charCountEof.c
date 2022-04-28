#include <stdio.h>

int main(void) {

    int num;
    char ch;

    num = 0;

    printf("Please input some characters and I will return the number of them:\n");
    while ((ch = getchar()) != EOF) 
        num++;
    printf ("The total number is: %d", num);

    return 0;
}
