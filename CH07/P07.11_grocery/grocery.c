#include<stdio.h>

#define ARTICHOKE 2.05
#define BEET 1.15
#define CARROT 1.09
#define DISCOUNT 0.05
#define SAH_1 6.5
#define SAH_2 14.00
#define SAH_EX 0.5


int main(void) {

    double total, shipping, discount, grand_total;      // info about the money
    double pounds, pound_arti, pound_beet, pound_carr;      // info about the weight
    double cost_arti, cost_beet, cost_carr;     // info about the cost of each plant
    double cost_per_pound;      //  const per pound
    double temp;       // temporary input of pounds for each buying

    char temp_nl;

    pounds = pound_arti = pound_beet = pound_carr = 0;

    char inp;
    printf("\n*****************************************************************\n");
    printf("Enter the character corresponding to the groceries or action:\n");
    printf("a) Artichokes --- $2.05/p             b) Beets --- $1.15/p\n");
    printf("c) Carrots --- $1.09/p                d) quit\n");
    printf("*****************************************************************\n");

    while (scanf("%c", &inp) == 1) {
        if (inp > 'd' || inp < 'a') {
            printf("%c is an invalid value. Try again(input a, b, c, or d to select): ", inp);
            while ((temp_nl = getchar()) != '\n')
                continue;
            continue;       // jumps to while loop test condition
        }
        else if (inp == 'd')
            break;
        else {
            switch (inp) {
            case 'a':
                printf("Please enter how many pounds of artichokes you buy:");
                scanf("%lf", &temp);
                pound_arti = pound_arti + temp;
                break;
            case 'b':
                printf("Please enter how many pounds of beets you buy:");
                scanf("%lf", &temp);
                pound_beet = pound_beet + temp;
                break;
            case 'c':
                printf("Please enter how many pounds of carrots you buy:");
                scanf("%lf", &temp);
                pound_carr = pound_carr + temp;
                break;
            }
        }
        printf("You can keep entering the character corresponding to the groceries or action:\n");

        getchar();      // skip the newline input
    }


    cost_arti = pound_arti * ARTICHOKE;
    cost_beet = pound_beet * BEET;
    cost_carr = pound_carr * CARROT;

    pounds = pound_arti + pound_beet + pound_carr;
    total = cost_arti + cost_beet + cost_carr;
    shipping = (pounds <= 5) * SAH_1 + (pounds > 5 && pounds < 20) * SAH_2 + (pounds >= 20) * (14 + (pounds - 20) * SAH_EX);
    discount = total * (total > 100) * DISCOUNT;

    grand_total = total + shipping - discount;
    cost_per_pound = grand_total / pounds;

    printf("\n*****************************************************************\n");
    printf("All the purchase information as follows:\n");
    printf("The pounds ordered:     %6.2lf\n", pounds);
    printf("The total:              %6.2lf\n", total);
    printf("The shipping:           %6.2lf\n", shipping);
    printf("The grand total:        %6.2lf\n", grand_total);
    printf("The cost perpound:      %6.2lf\n", cost_per_pound);

    printf("*****************************************************************\n");
    printf("Detailed information for each groceries:\n");
    printf("             Artichoke          Beet          Carrot\n");
    printf("Pound(s):    %6.2lf             %6.2lf        %6.2lf\n", pound_arti, pound_beet, pound_carr);
    printf("Cost:        %6.2lf             %6.2lf        %6.2lf\n", cost_arti, cost_beet, cost_carr);

    return 0;
}

