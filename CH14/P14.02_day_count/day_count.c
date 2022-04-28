/* Write a function that, when given the month name, returns the total days in the year
up to and including that month. Assume that the structure template of question 3 and
an appropriate array of such structures are declared externally. */

#include <stdio.h>
#include <string.h> // for strcmp()
#define NUM 12
#define LEN 10

char * s_gets(char *, int);

struct month {
    char name[10];      // the name of a month
    char abbr[4];       // a three-letter abbreviation for the month
    int days;           // the number of days in the month
    int month_num;      // the month number
};


int main(void) {

    char temp[LEN];
    int j;
    int total_days = 0;

    /* initialize the array of month structures */
    struct month months[NUM] = {
        {"January", "Jan", 31, 1},
        {"Febrary", "Feb", 28, 2},
        {"March", "Mar", 31, 3},
        {"April", "Apr", 30, 4},
        {"May", "May", 31, 5},
        {"June", "Jun", 30, 6},
        {"July", "Jul", 31, 7},
        {"August", "Aug", 31, 8},
        {"September", "Sep", 30, 9},
        {"October", "Oct", 31, 10},
        {"November", "Nov", 30, 11},
        {"December", "Dec", 31, 12}
    };

    /* ask and give back the info */
    printf("Please input the name of a month(empty line to quit): ");
    while (s_gets(temp, LEN) != NULL && temp[0] != '\0') {
        for (j = 0; j < NUM; j++) {
            if (strcmp(months[j].name, temp) == 0) {
                /* count the total days up to that month */
                for (int i = 0; i <= j; i++)
                    total_days = total_days + months[i].days;

                /* info dislay */
                printf("%s(%s) has %d days and is the %dth month of the year\n",
                       months[j].name, months[j].abbr, months[j].days, months[j].month_num);
                printf("The total days in the year up to and including that month is: %d\n", total_days);

                /* restore the value and jump to next input */
                total_days = 0;
                break;
            }
        }
        if (j != 12)
            printf("Please input the next name of a month(empty line to quit): ");
        else
            printf("Invalid input! Please input the name of a month again(empty line to quit): ");
    }

    return 0;
}

char * s_gets(char * st, int n) {
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}
