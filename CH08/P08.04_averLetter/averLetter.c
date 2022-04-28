#include <stdio.h>
#include <ctype.h>

int main(void) {

	int char_count = 0;
	int word_count = 0;
	double ave;
	int ch, ch_s;
	int flag = 1;       // 1 means the last characater is a space

	while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            if (flag == 0) {
                word_count++;
                flag = 1;
            }
            else
                continue;
        }
        else if (ch == '\n') {
            if (flag == 0) {
                word_count++;
                flag = 1;
            }
            else
                continue;
        }
        else if (ispunct(ch)) {
            continue;
        }
        else {
            flag = 0;
            char_count++;
        }
	}

	ave = char_count / word_count;

	printf("Number of words: %d, number of letters: %d, average number of letters per word: %f", word_count, char_count, ave);

	return 0;
}

