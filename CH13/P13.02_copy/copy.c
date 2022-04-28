/* Write a file-copy program that takes the original filename and the copy file from the
command line. Use standard I/O and the binary mode, if possible. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    FILE *origin, *copy;
    char ch;

    if (argc < 3) {
        fprintf(stderr, "Please enter the original filename and the copy file name!\n");
        exit(EXIT_FAILURE);
    }
    if ((origin = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Cannot opent the original file you input!\n");
        exit(EXIT_FAILURE);
    }
    if ((copy = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Can't create output file.\n");
        exit(EXIT_FAILURE);
    }
    /* copy the characters to the destination file */
    while ((ch = getc(origin)) != EOF)
        putc(ch, copy);

    if (fclose(origin) !=0 || fclose(copy) != 0)
        fprintf(stderr,"Error in closing files\n");

    return 0;
}
