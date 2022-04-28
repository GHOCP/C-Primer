#include<stdio.h>

#define TAX_RATE_1 0.15
#define TAX_RATE_2 0.2
#define TAX_RATE_3 0.25
#define PAY_RATE_1 8.75
#define PAY_RATE_2 9.33
#define PAY_RATE_3 10.00
#define PAY_RATE_4 11.20

int main(void) {

    double gross, pay_rate, tax;
    int inp, hour, over_time;
    char ch;


    printf("\n*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr                        2) $9.33/hr\n");
    printf("3) $10.00/hr                       4) $11.20/hr\n");
    printf("5) quit\n");
    printf("*****************************************************************\n");

    while (scanf("%d", &inp) == 1) {
        if (inp > 5 || inp < 1) {
            printf("%d is an invalid value. Try again(input 1, 2, 3, 4, or 5 to select): ", inp);
            continue;       // jumps to while loop test condition
        }
        else if (inp == 5){
            break;
        }
        else {
            switch (inp) {
            case 1:
                pay_rate = PAY_RATE_1;
                break;
            case 2:
                pay_rate = PAY_RATE_2;
                break;
            case 3:
                pay_rate = PAY_RATE_3;
                break;
            case 4:
                pay_rate = PAY_RATE_4;
                break;
            }

            printf ("Please enter the hours you work in a week:");
            scanf("%d", &hour);

            over_time = hour > 40 ? (hour - 40) : 0;
            gross = hour * pay_rate + (over_time + 0.5);
            tax = (gross <= 300)*gross*TAX_RATE_1 + (gross > 300 && gross <=450)*(300*TAX_RATE_1 + (gross-300)*TAX_RATE_2) + (gross > 450)*(300*TAX_RATE_1+150*TAX_RATE_2+(gross-450)*TAX_RATE_3);

            printf("Your gross pay is $%4.2lf, the taxes are $%4.2lf, the net pay is $%4.2lf\n", gross, tax, gross-tax);
        }

        printf("Keep select your desired pay rate or enter 'q' to quit:");
    }

    printf("Done!");

    return 0;
}
