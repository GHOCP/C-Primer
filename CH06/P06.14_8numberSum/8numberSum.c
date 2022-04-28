/* read 8 values and calculate the sum step by step */
#include <stdio.h>

int main(void) {

    double arr[8];
    double arr_sum[8];

    printf("Please enter 8 values:\n");
    for (int i = 0; i <= 7; i++)
        scanf("%lf", &arr[i]);

    arr_sum[0] = arr[0];
    for (int i = 1; i <= 7; i++)
        arr_sum[i] = arr_sum[i-1] + arr[i];

    printf("the 8 values you input is:\n");
    for (int i = 0; i <= 7; i++)
        printf("%10.2lf ", arr[i]);

    printf("\n");
    printf("the sum array is:\n");
    for (int i = 0; i <= 7; i++)
        printf("%10.2lf ", arr_sum[i]);

    return 0;
}
