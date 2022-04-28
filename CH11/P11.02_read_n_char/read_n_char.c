
/* test function 1: fetches the next n characters from input
(including blanks, tabs, and newlines), storing the results in an array; */
/* test function 2: stops after n characters or after the first blank,
tab, or newline, whichever comes first */

#include <stdio.h>
#include <string.h>
#define LEN 20

void read(char *, int);

int main(void) {

    char words[LEN];

    printf("Please print some characters:\n");
    read(words, 10);
    fputs(words, stdout);
    return 0;
}

void read(char *str, int n) {
    char ch;
    int count = 0;      // record the number of character being read
    int j = 0;

    while ((ch = getchar()) != EOF) {
        *(str + count) = ch;
        count++;
    }

    while (str[j] != ' ' && str[j] != '\n' && str[j] != '\t' && j < n)
        j++;
    while (j < count) {      // abandon the remaining characters
        str[j] = '\0';
        j++;
    }
}

