
/* Test a function that reads the first word from a line of input into an array and
discards the rest of the line. It should skip over leading whitespace. */
/* it accepts a second parameter specifying the maximum number of characters that can be read. */

#include <stdio.h>
#include <string.h>
#define LEN 10
#define LIMIT 40

void read_a_word(char *, int);

int main(void) {

    char word[LEN] = "";
    printf("Please input a sentence:\n");
    read_a_word(word, 3);
    puts(word);
    printf("Done!");

    return 0;
}


void read_a_word(char * str, int n) {
    int i = 0;
    int after_word = 0;       // decide whether the whitespace is after a word
    int flag_of_success = 0;        // when the word complies with the requirement of length
    char ch = 0;
    char temp[LIMIT] = "";

    /* read a line with \n as sign of ending */
    while ((ch = getchar()) != '\n') {
        if (!isalpha(ch)) {       // meeting with whitespace or punctuations
            if (after_word && i <= n && i > 1)
                break;      // word being found, turn to string copy
            else if (after_word && (i > n || i == 1)) {
                i = 0;
                after_word = 0;
            }
            else {        // skip
                after_word = 0;
                continue;
            }
        }
        else {      // meeting with alphabet
            temp[i] = ch;
            after_word = 1;       // the next whitespace or punctuation is after a word
            i++;
        }
    }
    if (i <= n && i > 1) {      // a judge returning 1 either when the word found is within the sentence or at the end
        strncpy(str, temp, i);
        flag_of_success = 1;
    }
    if (flag_of_success)
        printf("Find the word successfully:\n");
    else
        printf("Fail to find the word\n");
}

