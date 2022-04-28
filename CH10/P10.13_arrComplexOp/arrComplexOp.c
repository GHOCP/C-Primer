#include <stdio.h>
#define ROWS 3
#define COLS 5

void arr_store (double [][COLS], int);      // prompt the user to type and store the information
void var_display (int, int, const double [*][*]);       // display a 2d array

double arr_average_1d (double *, int);     // compute the average of a 1d array
double arr_average_all (double [][COLS], int);      // Compute the average of all the values of a 2d array
double arr_largest (double [][COLS], int);


int main(void) {

    double arr[ROWS][COLS];

    /* store and display */
    printf("STORE AND DISPLAY:\n");
    arr_store(arr, ROWS);
    printf("The array you enter is:\n");
    var_display(ROWS, COLS, arr);
    printf("\n");

    /* compute the average of each set of five values */
    printf("COMPUTE THE AVERAGE OF EACH SET OF FIVE VALUES:\n");
    double ave;
    for (int i = 0; i < ROWS; i++) {
        ave = arr_average_1d (*(arr+i), COLS);
        printf("Average of line %d: %4.2lf\n", i+1, ave);
    }
    printf("\n");

    /* compute the average of all the values */
    printf("COMPUTE THE AVERAGE OF ALL THE VALUES:\n");
    double ave_all;
    ave_all = arr_average_all(arr, ROWS);
    printf("The average of all the values in your array is: %4.2lf\n", ave_all);
    printf("\n");

    /* determine the largest value of the 15 values. */
    printf("DETERMINE THE LARGEST VALUE OF THE 15 VALUES:\n");
    printf("The largest of all the values in your array is: %4.2lf\n", arr_largest(arr, ROWS));

    return 0;
}



/* prompt the user to type and store the information */
void arr_store (double arr[][COLS], int rows) {
    int i = 0;
    while (i < rows) {
        printf("Please enter a row of 5 elements:");
        for (int j = 0; j < COLS; j++)
            scanf("%lf", &arr[i][j]);
        i++;
    }
}

/* display a 2d array */
void var_display (int row, int col, const double arr[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%2.2lf ", arr[i][j]);
        printf("\n");
    }
}

/* compute the average of a 1d array */
double arr_average_1d (double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum = sum + arr[i];
    return (sum / size);
}

/* compute the average of all the values of a 2d array */
double arr_average_all (double arr[][COLS], int rows) {
    double sum = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < COLS; j++)
            sum = sum + arr[i][j];
    }
    return (sum / (rows*COLS));
}

/* finding the largest of all the values of a 2d array */
double arr_largest (double arr[][COLS], int rows) {
    double * lar;
    lar = *arr;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] > *lar)
                lar = &arr[i][j];
        }
    }
    return *lar;
}


