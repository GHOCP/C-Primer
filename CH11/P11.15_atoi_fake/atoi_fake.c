/* an implementation of atoi() */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define LEN 5

int atoi_fake(char * str);

int main() {

    char str[LEN];
    int n;
    printf("Please input a string(using EOF to quit):\n");
    while (scanf("%s", str) == 1) {
        n = printf("%d\n", atoi_fake(str)) - 1;
        printf("n = %d\n", n);
        printf("Please input a string(using EOF to quit):\n");
    }
    printf("Done!");

    return 0;
}

int atoi_fake(char * str) {
    double num = 0;
    int i, dig;
    int n_flag = 0;

    int len = strlen(str);

    for (i = 0; i < len; i++) {
        if (i == 0 && str[i] == '-') {
            n_flag = 1;
            continue;
        }
        if (!isdigit(str[i]))
            break;
        else {
            dig = str[i] - 48;
            num = num + pow(10, len-i-1) * dig;
        }
    }
    if (i != len)
        return 0;
    else {
        num = num * (n_flag == 1? -1 : 1);
        return num;
    }

}
