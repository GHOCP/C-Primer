/* Takes two string pointers as arguments. */
/* If the second string is contained in the first string,
have the function return the address at which the contained
string begins. Otherwise, have the function return the null pointer. */

#include <stdio.h>
#include <string.h>
#define LEN 10

char * string_in(char *, char *);

int main(void) {
    char s1[] = "This is the mother sentence!";
    char s2[] = "sen";

    char temp;
    temp = *(string_in(s1, s2));
    printf("%c", temp);
    return 0;
}

char * string_in(char * s_mother, char * s1) {

    int len_m = strlen(s_mother);
    int len = strlen(s1);
    int i, j;

    if (len_m < len)
        return NULL;
    else {
        for (i = 0; i <= len_m - len; i++) {
            for (j = 0; j < len; j++) {
                if (s_mother[j+i] != s1[j])
                    break;
            }
            if (j == len)
                return &s_mother[i];
        }
        return NULL;
    }
}
