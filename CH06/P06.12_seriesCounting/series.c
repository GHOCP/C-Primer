/* two given series calculation */
#include <stdio.h>

int main(void) {

    int limit;
    double sum_1, sum_2;
    int flag, status;

    flag = -1;
    sum_1 = 0;
    sum_2 = 0;

    printf("enter the number of terms you want: ");
    status = scanf("%d", &limit);
    while (status == 1 && limit > 0) {
        for (int i = 1; i <= limit; i++) {
            double div = i;
            flag = flag * (-1);
            sum_1 = sum_1 + 1.0/div;
            sum_2 = sum_2 + 1.0/div*flag;
        }
        printf("The sum of the first series is %f\n", sum_1);
        printf("The sum of the second series is %f\n", sum_2);

        printf("enter next number of terms you want(enter 0 or a negative to quit): ");
        status = scanf("%d", &limit);
    }

    printf("Done!");

    return 0;
}
