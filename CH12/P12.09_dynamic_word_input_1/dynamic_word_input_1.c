/* prompt the user to enter words, then store and display, using malloc() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10     // set the maximun size of a word

void show_word(char *, int);

int main(void) {

    int count, input_count;      // the number of words input
    int i = 0;      //
    int len = 0;    // number of characters in a word
    char ** ptr;

    printf("how many words do you wish to enter? ");
    scanf("%d", &count);
    printf("enter %d words now:\n", count);

    ptr = (char **) malloc(count * sizeof(char *));

    while (i < count) {
        /* initialize the temporary character array with \0 */
        char temp[SIZE];
        for (int i = 0; i < SIZE; i++)
            temp[i] = '\0';
        /* read a word, store it into our temporary character array */
        scanf("%s", temp);

        /* len - 1 is the number of characters in the word read */
        while (temp[len++] != '\0')
            continue;
        len--;

        char * temp_ptr;
        temp_ptr = (char *) malloc(len * sizeof(char));
        for (int i = 0 ; i < len; i++)
            *(temp_ptr + i) = temp[i];

        *(ptr + i) = temp_ptr;

        show_word(*(ptr + i), len);

        free(temp_ptr);
        len = 0;
        i++;
    }

    free(ptr);
    printf("Done!");

    return 0;
}

void show_word(char * arr, int n) {
    for (int i = 0; i < n; i++)
        putchar(*(arr + i));
    putchar('\n');
}
