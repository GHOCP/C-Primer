/* Write a program that prompts the user to enter the day, month, and year. The month
can be a month number, a month name, or a month abbreviation. The program then
should return the total number of days in the year up through the given day. (Do take
leap years into account.) */

#include <stdio.h>
#include <stdlib.h>     // for atoi()
#include <string.h>     // for strcmp()
#include <ctype.h>      // for isdigit(), isalpha()
#define NUM 12
#define LEN 10

char * s_gets(char *, int);              // get the string
_Bool leap_year(int);                    // judge if leap year or not
int int_get(int, int, int);              // get the integer, with or without interval limit(flagged by limit's value)
int pure_digit_alpha(char array[]);      // all digit or all alpha or mixed (4 modes)

struct month {
    char name[10];      // the name of a month
    char abbr[4];       // a three-letter abbreviation for the month
    int days;           // the number of days in the month
    int month_num;      // the month number
};

int main(void) {

    char temp[LEN];
    int year = 0, mon = 0, day = 0;
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

    /* get the info and display the answer */
    printf("Please enter the month:(a month's number, name or abbreviation; empty line to quit): ");
    while (s_gets(temp, LEN) != NULL && temp[0] != '\0') {
        /* get the month */
        if (pure_digit_alpha(temp) == 1) {      // month's name or abbreviation
            for (int i = 0; i < NUM; i++) {
                if (strcmp(months[i].name, temp) == 0 || strcmp(months[i].abbr, temp) == 0) {
                    mon = i + 1;
                    break;
                }
            }
            if (mon == 0) {
                printf("There's no month called %s, please input again: ", temp);
                continue;
            }
        }
        else if (pure_digit_alpha(temp) == 2) {      // month's number
            int n;
            n = atoi(temp);
            if (n > 12 || n < 0) {
                printf("Please input the number 1~12!: ");
                continue;
            } else {
                mon = n;
            }
        }
        else {
            printf("Invalid month input, please input again: ");
            continue;
        }
        /* get the year */
        printf("Please input the year: ");
        year = int_get(0, 0, 0);        // no interval requirement
        if (leap_year(year))
            months[1].days = 28;
        /* get the day */
        printf("Please input the day: ");
        day = int_get(1, months[mon-1].days, 1);
        /* display the counted days */
        for (int i = 0; i < mon-1; i++)
            total_days = total_days + months[i].days;
        total_days = total_days + day;
        printf("the total number of days in the year up through %s %d, %d is: %d\n",
               months[mon-1].name, day, year, total_days);
        /* restore the data */
        months[1].days = 28;
        year = 0;
        mon = 0;
        day = 0;
        total_days = 0;

        printf("****************************\n");
        printf("Next phase of input begin:\n");
        printf("Please enter the month:(a month's number, name or abbreviation; empty line to quit): ");
    }

    // printf("%d %d %d", mon, day, year);
    printf("Done!");
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

_Bool leap_year(int year) {
    if (year > 1582) {
        if ( (year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0) )
            return 1;
        else
            return 0;
    }
    else if (year >= 0 && year <= 1582) {
        if (year % 4 == 0)
            return 1;
        else
            return 0;
    }
    else {
        if (year * (-1) % 4 == 1)
            return 1;
        else
            return 0;
    }
}

int int_get(int low, int high, int limit) {
    int input;
    if (limit == 1) {
        while (scanf("%d", &input) != 1 || (input < low || input > high)) {
            while (getchar() != '\n')
                continue;
            printf("(You entered a non-integer value, or you didn't enter an integer between %d and %d)\n", low, high);
            printf("Invalid input, please enter again: ");
        }
    } else {
        while (scanf("%d", &input) != 1) {
            while (getchar() != '\n')
                continue;
            printf("Invalid input, please enter again: ");
        }
    }
    return input;
}

int pure_digit_alpha(char array[]) {
    int flag_of_digit = 0;
    int flag_of_alpha = 0;
    int flag_of_other = 0;
    int i = 0;
    while (array[i] != '\0') {
        if (isdigit(array[i]))
            flag_of_digit = 1;
        else if (isalpha(array[i]))
            flag_of_alpha = 1;
        else
            flag_of_other = 1;
        i++;
    }
    if (flag_of_alpha == 1 && flag_of_digit == 0 && flag_of_other == 0)
        return 1;
    else if (flag_of_alpha == 0 && flag_of_digit == 1 && flag_of_other == 0)
        return 2;
    else if (flag_of_alpha == 1 && flag_of_digit == 1 && flag_of_other == 0)
        return 3;
    else
        return 4;
}
