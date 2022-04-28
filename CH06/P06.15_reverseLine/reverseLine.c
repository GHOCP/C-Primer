/* read a line and print it reversely */
#include <stdio.h>

int main(void) {

    char arr[255];
    int i = 0;
    int num = i;

    printf("Please input a line:(no more than 255 characters, included space)\n");

    scanf("%c", &arr[i]);
    while (arr[i] != '\n') {
        i++;
        scanf("%c", &arr[i]);
    }

    printf("the reverse line is:");
    for (int k = i-1; k >= 0; k--)
        printf("%c", arr[k]);

    return 0;
}
