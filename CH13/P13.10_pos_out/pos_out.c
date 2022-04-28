/* Write a program that opens a text file whose name is obtained interactively. Set up a
loop that asks the user to enter a file position. The program then should print the part of
the file starting at that position and proceed to the next newline character. Let negative
or nonnumeric input terminate the user-input loop. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 17

char * s_gets(char * str, int n);

int main(void) {

    FILE * fp;
    char file_name[LEN];
    char ch;
    long position;

    printf("Enter the name of the file to be processed(empty line to quit): ");
    while (s_gets(file_name, LEN) && file_name[0] != '\0') {
        /* when unable to open the file input */
        if ((fp = fopen(file_name, "r")) == NULL) {
            printf("Cannot open the file: %s, Please enter again(empty line to quit): ", file_name);
            continue;
        }
        /* begin to receive position input */
        else {
            printf("Please enter a file position(negative or nonnumeric input to terminate): ");
            if (scanf("%ld", &position) == 0)
                break;
            else {
                printf("The part starting at position %ld and to the newline is:\n", position);
                fseek(fp, position, SEEK_SET);
                while ((ch = getc(fp)) != '\n' && ch != EOF)
                    putchar(ch);
                putchar('\n');
                printf("Enter the name of next file to be processed(empty line to quit): ");
            }
            fclose(fp);
            getchar();      // skip the newline caused by long input
        }
    }

    puts("Done!");
    return 0;
}

char * s_gets(char * str, int n) {
    char * re_val;
    char * find;
    re_val = fgets(str, n, stdin);
    if (re_val) {
        find = strchr(re_val, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return re_val;
}

