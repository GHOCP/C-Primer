#include <stdio.h>
#define SIZE 5

void copy_arr(double target[], double source[], int);      // copy the array using array notation
void copy_ptr(double * trg, double * src, int);        // copy the array using pointers(1)
void copy_ptrs(double * trg, double * src, double * end);       // copy the array using pointers(2)
void array_printf(double ar[], int);       // print out the array

int main(void) {

    double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[SIZE];
    double target2[SIZE];
    double target3[SIZE];

    copy_arr(target1, source, SIZE);
    copy_ptr(target2, source, SIZE);
    copy_ptrs(target3, source, source+SIZE);

    printf("source array: ");
    array_printf(source, SIZE);
    printf("target1:      ");
    array_printf(target1, SIZE);
    printf("target2:      ");
    array_printf(target2, SIZE);
    printf("target3:      ");
    array_printf(target3, SIZE);

    return 0;
}


/* copy the array using array notation */
void copy_arr(double target[], double source[], int size) {
    for (int i = 0; i < SIZE; i++) {
        target[i] = source[i];
    }
}

/* copy the array using pointers(1) */
void copy_ptr(double * trg, double * src, int size) {
    int i = 0;
    while (i < SIZE) {
        *(trg + i) = *(src + i);
            i++;
    }
}

/* copy the array using pointers(2) */
void copy_ptrs(double * trg, double * src, double * end) {      // end points to the next after the last element
    int i = 0;
    while ((src + i) < end) {
        *(trg + i) = *(src + i);
        i++;
    }
}

/* print out the array */
void array_printf(double ar[], int size) {
    for (int i = 0; i < SIZE; i++) {
        printf("%2.2lf ", ar[i]);
    }
    printf("\n");
}
