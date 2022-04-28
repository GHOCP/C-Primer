// pe12-8.c
#include <stdio.h>

int * make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void) {

    int * pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0) {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa) {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");

    return 0;
}
/*
    The make_array() function takes two arguments. The first is the number
    of elements of an int array, and the second is a value that is to be assigned to each
    element.
*/
int * make_array(int elem, int val) {
    int * ptr;
    ptr = (int *) malloc(elem * sizeof(int));
    for (int i = 0; i < elem; i++)
        *(ptr + i) = val;
    return ptr;
}

/*
    The function uses malloc() to create an array of a suitable size, sets each
    element to the indicated value, and returns a pointer to the array.
*/
void show_array(const int ar[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", ar[i-1]);
        if (i%8 == 0 && i != 0)
            putchar('\n');
    }
    putchar('\n');
}
