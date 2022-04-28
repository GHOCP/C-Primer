/* a function returns the largest value in an int array and its index */
#include <stdio.h>
#define SIZE 7

void arrayLarOp (const int ar[], int size);

int main(void) {

    const int ar1[SIZE] = {1, 3, 12, 34, 43, 10, 19};
    const int ar2[SIZE] = {10, 21, 10, 23, 9, 12, 23};

    printf("for array1:\n");
    arrayLarOp(ar1, SIZE);

    printf("\nfor array2:\n");
    arrayLarOp(ar2, SIZE);

    return 0;
}

void arrayLarOp (const int ar[], int size) {
    int lar;       // store the largest number and its index
    int * ptr;

    ptr = ar;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (ar[i] < ar[j]) {
                ptr = &ar[j];
            }
        }
    }
    lar = *ptr;

    printf("The largest value is %d\n", lar);

    /* check out the number of value that equals the largest */
    for (int k = 0; k < size; k++) {
        if (ar[k] == lar)
            printf("index: %d\n", k);
    }
}

