/* Write a program that takes two command-line arguments. The first is a string; the
second is the name of a file. The program should then search the file, printing all lines
containing the string. Because this task is line oriented rather than character oriented,
use fgets() instead of getc() . Use the standard C library function strstr() (briefly
described in exercise 7 of Chapter 11 ) to search each line for the string. Assume no lines
are longer than 255 characters. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 256

int main(int argc, char * argv[]) {

    char line[LEN];
    FILE * fp;

    if (argc != 3) {
        fprintf(stderr, "Please enter a string and a name of a file");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Fail to open the file: %s", argv[2]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, LEN, fp)) {
        if (strstr(line, argv[1]) != NULL)
            fputs(line, stdout);
        else
            putchar('\n');
    }

    return 0;
}
