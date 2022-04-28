/* Write a program that takes two command-line arguments. The first is a character, and
the second is a filename. The program should print only those lines in the file containing
the given character. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 257

int main(int argc, char *argv[]) {

    FILE *fp;
    char ch;
    char line[LEN];     // store a line from the file

    if (argc < 3) {
        fprintf(stderr, "Please input two command-line arguemtns,\n"
                "the first is a character, and"
                " the second is a filename.\n");
        exit(EXIT_FAILURE);
    }
    ch = *argv[1];      // extract the character input
    if ((fp = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Cannot open the file \"%s\"\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, 257, fp) != NULL) {
        /* abandon the characters not being read into our string
        if (strchr(line, '\n') == NULL) {
            while (getc(fp) != '\n')
                continue;
        }*/
        /* search for the character input in each line */
        if (strchr(line, ch))
            fputs(line, stdout);
        else
            putchar('\n');
    }

    if (fclose(fp) != 0)
        fprintf(stderr, "Cannot close the file you've opened!");

    return 0;
}
