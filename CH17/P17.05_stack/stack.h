/* stack.h -- header file for a simple stack type */
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdbool.h>    // C99 feature

/** || program-specific declarations **/
#define MAXSTACK 20     //  maximum size of the stack
typedef char ITEM;


/** || general type definition **/
typedef struct node {
    ITEM item;
    struct node * next;
} NODE;

typedef struct Stack {
    NODE * top;
    int num_of_items;
} STACK;


/** || interface functions prototypes **/
/*
    The stack is another data form from the list family. In a stack, additions and deletions
    can be made from only one end of the list. Items are said to be "pushed onto" the top of
    the stack and to be "popped off" the stack. Therefore, the stack is a LIFO structure (that
    is, last in, first out ).
*/

// operation:       initialize a stack
// preconditions:   p_stack points to a stack
// postconditions:  the stack is initialized to empty
void InitializeStack(STACK * p_stack);

// operation:       check if the stack is empty
// precondtions:    p_stack points to a stack
// postconditions:  returns True if stack is empty, else False
bool StackIsEmpty(const STACK * p_stack);

// operation:       check if the stack is full
// precondtions:    p_stack points to a stack
// postconditions:  returns True if stack is full, else False
bool StackIsFull(const STACK * p_stack);

// operation:       check out the number of items in the stack
// precondtions:    p_stack points to a stack
// postconditions:  returns the number of items in the stack
int StackItemCount(const STACK * p_stack);

// operation:       add item to rear of stack
// precondtions:    p_stack points to a stack;
//                  item is the ITEM you want to add
// postconditions:  if the stack is not empty, item is placed
//                  on top of the stack and function returns
//                  true; otherwise the stack is unchanged and
//                  function returns false
bool EnStack(ITEM item, STACK * p_stack);

// operation:       remove item front rear of stack
// precondtions:    p_stack points to previously initialized stack;
//                  item here is a pointer, the item being removed is
//                  to be copied to *item
// postconditions:  if the stack is not empty, item on top of the stack
//                  is copied to *item, and functions returns true;
//                  if the stack is empty to begin with, stack is unchanged
//                  and the function returns false
bool DeStack(ITEM * item, STACK * p_stack);

// operation:       empty the stack
// precondtions:    p_stack points to previously initialized stack
// postconditions:  the stack is empty
void EmptyStack(STACK * p_stack);


#endif // STACK_H_INCLUDED
