#include <stdio.h>
#define ROWS 3
#define COLS 5

void var_copy (int, int, const double [*][*], double [*][*]);
void var_display (int, int, const double [*][*]);

int main(void) {

    const double arr[ROWS][COLS] = {
        {1,2,3,4,5},
        {1,2,3,4,5},
        {1,2,3,4,5}
    };
    double tgt[ROWS][COLS];

    var_copy(ROWS, COLS, arr, tgt);
    printf("the source array:\n");
    var_display(ROWS, COLS, arr);
    printf("the target array:\n");
    var_display(ROWS, COLS, tgt);
    return 0;
}

void var_copy (int row, int col, const double source[row][col], double target[row][col]){
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            target[i][j] = source[i][j];
        }
    }
}

void var_display (int row, int col, const double arr[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%2.2lf ", arr[i][j]);
        }
        printf("\n");
    }
}
