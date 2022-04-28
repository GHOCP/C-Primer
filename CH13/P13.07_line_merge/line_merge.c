/* Write a program that opens two files. You can obtain the filenames either by using
command-line arguments or by soliciting the user to enter them.
a. Have the program print line 1 of the first file, line 1 of the second file, line 2 of the
first file, line 2 of the second file, and so on, until the last line of the longer file (in
terms of lines) is printed.
b. Modify the program so that lines with the same line number are printed on the
same line. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    FILE *file1, *file2;
    char ch1, ch2;
    int flag_of_EOF_1 = 0, flag_of_EOF_2 = 0;

    /* peps */
    if (argc < 3) {
        fprintf(stderr, "Please enter names of two files.\n");
        exit(EXIT_FAILURE);
    }
    if ((file1 = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Cannot open file1: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((file2 = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Cannot open file2: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    /*
    if ((ch1 = getc(file1)) == EOF)
        flag_of_EOF_1 = 1;
    if ((ch2 = getc(file2)) == EOF)
        flag_of_EOF_2 = 1;

    while (!(flag_of_EOF_1 && flag_of_EOF_2)) {
        putchar(ch1);
        while (!flag_of_EOF_1 && (ch1 = getc(file1)) != '\n')
            putchar(ch1);

        putchar(' ');

        putchar(ch2);
        while (!flag_of_EOF_2 && (ch2 = getc(file2)) != '\n')
            putchar(ch2);
        putchar('\n');

        if ((ch1 = getc(file1)) == EOF)
            flag_of_EOF_1 = 1;
        if ((ch2 = getc(file2)) == EOF)
            flag_of_EOF_2 = 1;
    }
    */
    while ((ch1 = getc(file1)) != EOF && (ch2 = getc(file2)) != EOF) {
        putchar(ch1);
        while ((ch1 = getc(file1)) != EOF && ch1 != '\n')
            putchar(ch1);
        putchar(' ');
        putchar(ch2);
        while ((ch2 = getc(file2)) != EOF && ch2 != '\n')
            putchar(ch2);
        putchar('\n');
    }

    return 0;
}
