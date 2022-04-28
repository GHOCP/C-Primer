/* reads in up to 10 strings or to EOF , whichever comes first */
/* select manipulations on the strings from the menu */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 81     // string length limit, including \0
#define LIM 10      //maximum number of lines to be read


char get_choice(void);
char get_first(void);
char * s_gets(char *, int);
int first_word_length(char *);      // returns the length of the first word in a string

void arrstr_print(char *strings[], int num);     // a. printing arrays of strings
void strsrt_ASCII(char *strings[], int num);        // b. string-pointer-sorting function(in ASCII collating sequence)
void strsrt_length(char *strings[], int num);      // c. string-pointer-sorting function(in order of increasing length)
void strsrt_word(char *strings[], int num);        // d. string-pointer-sorting function(in order of the length of the first word)

int main(void) {

    int count = 0;      // number of strings input
    char choice;
    char arr_str[LIM][SIZE];        // array to store input
    char *ptstr[LIM];       // array of pointer variables
    char *ptstr_origin[LIM];        // storing the original array

    printf("Input up to %d lines, and then you can choose the manipulation.\n", LIM);
    printf("To stop, press the Enter key at a line's start.\n");
    while (count <= LIM &&
           s_gets(arr_str[count], SIZE) != NULL
           && arr_str[count][0] != '\0') {
        ptstr[count] = arr_str[count];
        ptstr_origin[count] = arr_str[count];
        count++;
    }

    while ((choice = get_choice()) != 'q') {
        switch (choice) {
        case 'a':
            arrstr_print(ptstr_origin, count);
            break;
        case 'b':
            strsrt_ASCII(ptstr, count);
            arrstr_print(ptstr, count);
            break;
        case 'c':
            strsrt_length(ptstr, count);
            arrstr_print(ptstr, count);
            break;
        case 'd':
            strsrt_word(ptstr, count);
            arrstr_print(ptstr, count);
        }
    }

    return 0;
}


/* menu displaying and choice getting */
char get_choice(void) {
    int ch;
    printf("Enter the letter of your choice:\n");
    printf("a. print the original list of strings                   b. print the strings in ASCII collating sequence\n");
    printf("c. print the strings in order of increasing length      d. print the strings in order of the length of the first word\n");
    printf("q. quit\n");
    ch = get_first();
    while ( (ch < 'a' || ch > 'd') && ch != 'q') {
        printf("Please respond with a, b, c, d or q.\n");
        ch = get_first();
    }
    return ch;
}

char get_first(void) {
    int ch;
    ch = getchar();
    while (getchar() != '\n')
        continue;
    return ch;
}

/* read the input as string */
char * s_gets(char * st, int n) {
    char * ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else // must have words[i] == '\0'
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

/* returns the length of the first word in a string */
int first_word_length(char * string) {
    int len = strlen(string);
    int start = 0;
    int end;
    while (!isalpha(string[start]) && start < len)
        start++;
    if (start == len)
        return 0;
    end = start + 1;
    while (isalpha(string[end]) && end < len)
        end++;
    return (end - start);
}

/*************** functions in the choice ******************/

/* a. arrays of strings printing */
void arrstr_print(char *strings[], int num) {
    for (int i = 0; i < num; i++)
        puts(strings[i]);
    putchar('\n');
}

/* b. string-pointer-sorting function(in ASCII collating sequence) */
void strsrt_ASCII(char *strings[], int num) {
    char *temp;
    int top, seek;
    for (top = 0; top < num-1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(strings[top],strings[seek]) > 0) {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}

/* c. string-pointer-sorting function(in order of increasing length) */
void strsrt_length(char *strings[], int num) {
    char *temp;
    int top, seek;
    for (top = 0; top < num-1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strlen(strings[top]) > strlen(strings[seek])) {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}


/* d. string-pointer-sorting function(in order of the length of the first word) */
void strsrt_word(char *strings[], int num) {
    char *temp;
    int top, seek;
    int len_top, len_seek;
    for (top = 0; top < num-1; top++)
        for (seek = top + 1; seek < num; seek++) {
            len_top = first_word_length(strings[top]);
            len_seek = first_word_length(strings[seek]);
            if (len_top > len_seek) {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
}
