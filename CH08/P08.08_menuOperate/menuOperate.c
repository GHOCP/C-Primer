#include <stdio.h>

void menu (void);
float get_float(void);

int main(void) {

    char ch, temp_ch;
    float a, b;

    menu();
    while ((ch = getchar()) != 'q') {
        if (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd') {
            printf("Please choose a valid input from a, s, m, d or q:");
            getchar();      // skip the newline input
            continue;
        }
        else if (ch == 'a' || ch == 's' || ch == 'm'){
            printf ("Enter the first number:");
            a = get_float();
            printf ("Entert the second number:");
            b = get_float();

            switch (ch) {
            case 'a':
                printf("%f + %f = %f\n\n", a, b, a+b);
                break;
            case 's':
                printf("%f - %f = %f\n\n", a, b, a-b);
                break;
            case 'm':
                printf("%f * %f = %f\n\n", a, b, a*b);
                break;
            }
        }
        else {
            printf ("Enter the first number:");
            a = get_float();
            printf ("Entert the second number:");
            b = get_float();
            while (b == 0) {
                printf("Enter a number other than 0:");
                b = get_float();
            }
            printf("%f / %f = %f\n\n", a, b, a/b);
        }

        menu();
        getchar();      // skip the newline input
    }
    printf("Bye.\n");

    return 0;
}

void menu(void) {
    printf("Enter the operation of your choice:\n");
    printf("a. add              s. subtract\n");
    printf("m. multiply         d. divide\n");
    printf("q. quit\n");
}

float get_float(void) {
    char ch;
    float inp;

    while (scanf("%f", &inp) != 1) {
        while ((ch = getchar()) != '\n') {
            putchar(ch);
        }
        printf(" is not a number.\nPlease enter a number, such as 2.5, -1.78E8, or 3:");
    }

    return inp;
}

