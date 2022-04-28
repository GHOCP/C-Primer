/*
Create a text file consisting of 20 rows of 30 integers. The integers should be in the range
0¨C9 and be separated by spaces. The file is a digital representation of a picture, with
the values 0 through 9 representing increasing levels of darkness. Write a program that
reads the contents of the file into a 20-by-30 array of ints. In a crude approach toward
converting this digital representation to a picture, have the program use the values
in this array to initialize a 20-by-31 array of chars, with a 0 value corresponding to a
space character, a 1 value to the period character, and so on, with each larger number
represented by a character that occupies more space. For example, you might use # to
represent 9. The last character (the 31st) in each row should be a null character, making
it an array of 20 strings. Have the program display the resulting picture (that is, print the
strings) and also store the result in a text file. For example, suppose you start with this
data:
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 5 2 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 1 9 8 5 4 5 2 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 0 4 5 2 0 0 0 0 0 0 0 0
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 4 5 2 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 1 8 5 0 0 0 4 5 2 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 4 5 2 0 0 0 0 0
5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
9 9 9 9 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 3 9 9 9 9 9 9 9
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
0 0 0 0 2 2 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
0 0 0 0 3 3 0 0 0 0 0 0 5 8 9 9 8 5 0 5 6 1 1 1 1 6 5 0 0 0
0 0 0 0 4 4 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
0 0 0 0 5 5 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
For one particular choice of output characters, the output looks like this:
(pass)
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ROW 20
#define COL 30

void show_arr(int [][COL], int);
void show_arr1(float [][COL], int);
void show_arr2(char [][COL+1], int);

int main(void) {

    int num_array[ROW][COL];
    char char_array[ROW][COL+1];
    float num_array_deglitch[ROW][COL];

    char convert[10] = {' ', '.', ':', ';', '?', '%', '$', '#', '&', '@'};      // mapping the number and the chars
    char ch;
    FILE *fp;
    int up, down, left, right;      // the neighbors of the element in the 2-dimensional array
    int n;
    float average;

    if ((fp = fopen("20_30_char.txt", "r")) == NULL) {
        fprintf(stderr, "Cannot open the file: 20_30_char.txt.");
        exit(EXIT_FAILURE);
    }
    /* int array read from the file */
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            ch = getc(fp);
            while (!isdigit(ch)) {
                ch = getc(fp);
                continue;
            }
            num_array[i][j] = ch - '0';
        }
    }
    printf("The int array in the file is:\n");
    show_arr(num_array, ROW);
    putchar('\n');

    /* mapping the int array to the char array */
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            char_array[i][j] = convert[num_array[i][j]];
    for (int k = 0; k < ROW; k++)       // set the last element of each line as '\0'
        char_array[k][COL] = '\0';
    printf("The char array in the file is:\n");
    show_arr2(char_array, ROW);
    putchar('\n');

    /* deglitch the int array */
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            up = ((i-1) < 0 ? 0 : num_array[i-1][j]);
            down = ((i+1) == ROW ? 0 : num_array[i+1][j]);
            left = ((j-1) < 0 ? 0 : num_array[i][j-1]);
            right = ((j+1) == COL ? 0 : num_array[i][j+1]);

            n = num_array[i][j];
            average = (up + down + left + right) / 4;
            //
            if (i > 0 && i < ROW-1 && j < COL-1 && j > 0)
                num_array_deglitch[i][j] = (abs(n-left) > 1 && abs(n-right) > 1 && abs(n-down) > 1 && abs(n-up) > 1) ?
                                            average : num_array[i][j];
            //
            else if (i == 0 && j < COL-1 && j > 0)
                num_array_deglitch[i][j] = (abs(n-left) > 1 && abs(n-right) > 1 && abs(n-down) > 1) ?
                                            average : num_array[i][j];
            //
            else if (i == ROW-1 && j < COL-1 && j > 0)
                num_array_deglitch[i][j] = (abs(n-left) > 1 && abs(n-right) > 1 && abs(n-up) > 1) ?
                                            average : num_array[i][j];
            //
            else if (j == 0 && i < ROW-1 && i > 0)
                num_array_deglitch[i][j] = (abs(n-up) > 1 && abs(n-down) > 1 && abs(n-right) > 1) ?
                                            average : num_array[i][j];
            //
            else if (j == COL-1 && i < ROW-1 && i > 0)
                num_array_deglitch[i][j] = (abs(n-up) > 1 && abs(n-down) > 1 && abs(n-left) > 1) ?
                                            average : num_array[i][j];
            //
            else if (i == 0 && j == 0)
                num_array_deglitch[i][j] = (abs(n-right) > 1 && abs(n-down) > 1) ?
                                            average : num_array[i][j];
            //
            else if (i == 0 && j == COL-1)
                num_array_deglitch[i][j] = (abs(n-left) > 1 && abs(n-down) > 1) ?
                                            average : num_array[i][j];
            //
            else if (i == ROW-1 && j == 0)
                num_array_deglitch[i][j] = (abs(n-right) > 1 && abs(n-up) > 1) ?
                                            average : num_array[i][j];
            //
            else if (i == ROW-1 && j == COL-1)
                num_array_deglitch[i][j] = (abs(n-left) > 1 && abs(n-down) > 1) ?
                                            average : num_array[i][j];
            else
                continue;
        }
    }
    printf("The int array after deglitching is:\n");
    show_arr1(num_array_deglitch, ROW);

    return 0;
}

/* print a 2-dimensional int array */
void show_arr(int array[][COL], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d", array[i][j]);
            if (j == COL-1)     // newline added to the last element
                putchar('\n');
            else        // space between elements
                putchar(' ');
        }
    }
}

/* print a 2-dimensional float array */
void show_arr1(float array[][COL], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%.1lf", array[i][j]);
            if (j == COL-1)     // newline added to the last element
                putchar('\n');
            else        // space between elements
                putchar(' ');
        }
    }
}

/* print a 2-dimensional char array */
void show_arr2(char array[][COL+1], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < COL; j++) {
            putchar(array[i][j]);
            if (j == COL-1)     // newline added to the last element
                putchar('\n');
            else        // space between elements
                putchar(' ');
        }
    }
}
