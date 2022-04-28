/*
    Write a program that lets you input a string. The program then should push the
    characters of the string onto a stack, one by one (see review question 5), and then pop
    the characters from the stack and display them. This results in displaying the string in
    reverse order.
*/
#include <stdio.h>
#include <string.h>
#include "stack.h"

char * s_gets(char * st, int n);

int main(void) {
    char arr[MAXSTACK];
    ITEM ch;
    int i = 0;
    /* initialize the stack */
    STACK myStack;
    InitializeStack(&myStack);

    /* let the user input the string */
    printf("Please input a string(<20 chars, empty line to quit): ");
    while (s_gets(arr, MAXSTACK) != NULL && arr[0] != '\0') {
        while (arr[i] != '\0') {
            EnStack(arr[i], &myStack);
            i++;
        }
        EnStack(arr[i], &myStack);
        printf("Your string is: ");
        while (!StackIsEmpty(&myStack)) {
            DeStack(&ch, &myStack);
            printf("%c", ch);
        }
        /* recover the stack and index */
        EmptyStack(&myStack);
        i = 0;
        printf("\nPlease input next string(<20 chars, empty line to quit): ");
    }

    return 0;
}

char * s_gets(char * st, int n) {
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}
