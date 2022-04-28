/* a program that reads input until end-of-file and echoes it to the display */
/* the program recognize and implement 3 command-line arguments */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int command_find(char * str);
void str_upper_show(const char * str);
void str_lower_show(const char * str);

int main(int argc, char *argv[]) {
    int command;

    if (argc < 2) {
        printf("nothing's been entered!");
    }
    else if (argc == 2) {
        if (command_find(argv[1]) == 0)
            puts(argv[1]);
        else
            printf("You didn't entered the string(s)!");
    }
    else {
        command = command_find(argv[1]);
        if (command == 0)
            for (int i = 1; i < argc; i++)
                puts(argv[i]);
        else if (command == 1)
            for (int i = 2; i < argc; i++)
                puts(argv[i]);
        else if (command == 2)
            for (int i = 2; i < argc; i++) {
                str_upper_show (argv[i]);
                // putchar('\n');
            }
        else if (command == 3)
            for (int i = 2; i < argc; i++) {
                str_lower_show (argv[i]);
                // putchar('\n');
            }
        else
            printf("Something wrong happens");
    }

    return 0;
}

void str_upper_show(const char * str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        putchar(toupper(str[i]));
}

void str_lower_show(const char * str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        putchar(tolower(str[i]));
}

int command_find(char * str) {
    if (strcmp(str, "-p") == 0)
        return 1;
    else if (strcmp(str, "-u") == 0)
        return 2;
    else if (strcmp(str, "-l") != 0)
        return 3;
    else
        return 0;
}
