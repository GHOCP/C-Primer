/* a personal version of strncpy(s1, s2, n) */

#include <stdio.h>
#include <string.h>
#define LEN 30


char * mystrncpy(char *, const char *, int);

int main(void) {
    char target[LEN];
    char str_scr1[] = "This is the target 1";
    char str_scr2[] = "This is the target 2";

    puts(mystrncpy(target, str_scr1, 5));
    puts(mystrncpy(target, str_scr2, 25));

    return 0;
}

char * mystrncpy(char * s1, const char * s2, int n) {
    int len_src = strlen(s2);
    size_t len_des = sizeof(s1);
    int i, j;

    // if (len_des < n)
    //    return NULL;

    if (len_src >= n) {     // length of source is n or more; target string is not null-terminated
        for (int i = 0; i < n; i++)
            s1[i] = s2[i];
    } else {        // length of source is less then n; paddin '\0'
        for (i = 0; i < n; i++)
            s1[i] = s2[i];
        for (j = i; j < len_des; j++)
            s1[j] = '\0';
    }
    return s1;
}
