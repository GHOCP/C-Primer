#include <stdio.h>

int main(void) {

    int n;
    printf("Please enter an ASCII code value:\n");
    scanf("%d", &n);
    printf("The character which has ASCII code %d is %c", n, n);

    return 0;
}
