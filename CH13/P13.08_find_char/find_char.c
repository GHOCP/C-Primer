/* Write a program that takes as command-line arguments a character and zero or more
filenames. If no arguments follow the character, have the program read the standard
input. Otherwise, have it open each file in turn and report how many times the character
appears in each file. The filename and the character itself should be reported along with
the count. Include error-checking to see whether the number of arguments is correct and
whether the files can be opened. If a file can¡¯t be opened, have the program report that
fact and go on to the next file. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 17

int char_count(FILE *, char);
char * s_gets(char *, int);

int main(int argc, char *argv[]) {

    char file_name[LEN];       // store the file name entered by the user
    int n;      // the number of the characters in the file
    int num_of_files = 0;
    FILE *fp;

    if (argc < 2) {
        fprintf(stderr, "Please enter at leat a character,\n"
                "also you can add file names following it");
        exit(EXIT_FAILURE);
    }
    /* interactive input of files */
    else if (argc == 2) {
        printf("Please enter the name of the file(empty line to quit): ");
        while (s_gets(file_name, LEN) && file_name[0] != '\0') {
            if ((fp = fopen(file_name, "r")) == NULL) {
                printf("Cannot open the file: %s, Please enter again:", file_name);
                continue;
            } else {
                printf("There is(are) %d %c(s) in the file: %s\n",
                       char_count(fp, *argv[1]), *argv[1], file_name);
                printf("Please enter the name of next file(empty line to quit): ");
            }
        }
    }
    /* file names(s) after the input character */
    else {
        for (int i = 2; i < argc; i++) {
            if ((fp = fopen(argv[i], "r")) == NULL) {
                printf("Cannot open the file #%d: %s\n", i-1, argv[i]);
                continue;
            } else {
                printf("The number of \'%c\' in file #%d: %s --- %d\n",
                       *argv[1], i-1, argv[i], char_count(fp, *argv[1]));
                num_of_files++;     // record the file(s) successfully opened
            }
        }
        printf("%d file(s) entered, %d file(s) successfully opened.\n", argc-2, num_of_files);
    }

    printf("Done!");
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

int char_count(FILE * fp, char ch) {
    int count = 0;
    char ch_get;
    while ((ch_get = getc(fp)) != EOF) {
        if (ch_get == ch)
            count++;
    }
    return count;
}
