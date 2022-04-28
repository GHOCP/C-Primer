#include <stdio.h>

void chline(char, int, int);

int main(void) {

    char ch;
    int row, col;

    printf("please input a character:");
    ch = getchar();
    while (getchar() != '\n')
        continue;       // skip the left input characters


    printf("Enter a pair of integers (q to quit):\n");
    while (scanf("%d %d", &row, &col) == 2) {
        if (row >= 1 && col >= 1){
            chline(ch, row, col);
            printf("Enter a pair of integers (q to quit):\n");
        } else {
            printf("both two integers must be equal or greate than one, please input again:");
        }

    }
    printf("BYE!");

    return 0;
}

void chline(char ch, int row, int col){
    for (int i = 1; i <= row; i++){
        for (int j = 1; j <= col; j++){
            printf("%c", ch);
        }
        printf("\n");
    }
}
