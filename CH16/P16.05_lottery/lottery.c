/*
    Write a function that takes as arguments the name of an array of type int elements, the
    size of an array, and a value representing the number of picks. The function then should
    select the indicated number of items at random from the array and prints them. No
    array element is to be picked more than once. (This simulates picking lottery numbers or
    jury members.) Also, if your implementation has time() (discussed in Chapter 12 ) or a
    similar function available, use its output with srand() to initialize the rand() randomnumber
    generator. Write a simple program that tests the function.
*/

#include <stdio.h>
#include <stdlib.h> // for library srand()
#include <time.h> // for time()
#define SIZE 100

void lottery(const int [], int, int);
int find(const int[], int, int);       // see if an integer is with an array of integers

int main(void) {

    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
        arr[i] = i;
    lottery(arr, SIZE, 10);

    return 0;
}

void lottery(const int arr[], int size, int select) {
    if (select > size) {
        fprintf(stderr, "the number of picks shouldn't exceed the size of array!");
        exit(1);
    }
    int index[SIZE] = {-1};       // represents the index of corresponding elements(same col)
                                  // in the orginal ar
    int ind;
    for (int i = 0; i < select; i++) {
         srand((unsigned int) time(0)); // randomize seed
         ind = rand() % size;
         while (find(index, select, ind) == 1) {    // when the element has been selected
            srand((unsigned int) time(0));
            ind = rand() % size;
         }
         index[i] = ind;
    }
    printf("The elements selected are:\n");
    for (int i = 0; i < select; i++)
        printf("%d ", arr[index[i]]);
}

int find(const int arr[], int size, int num) {
    int flag = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] == num)
            flag = 1;
    return flag;
}
