/* stack.c -- the stack type implementation*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/** || local functions prototypes**/
static void CopyToNode(ITEM, NODE *);
static void CopyToItem(NODE *, ITEM *);

/**  || interface functions definitions  **/
void InitializeStack(STACK * p_stack) {
    p_stack->top = NULL;
    p_stack->num_of_items = 0;
}

bool StackIsEmpty(const STACK * p_stack) {
    return p_stack->num_of_items == 0;
}

bool StackIsFull(const STACK * p_stack) {
    return p_stack->num_of_items == MAXSTACK;
}

int StackItemCount(const STACK * p_stack) {
    return p_stack->num_of_items;
}

bool EnStack(ITEM item, STACK * p_stack) {
    NODE * p_new;

    if (StackIsFull(p_stack))
        return false;
    p_new = (NODE*) malloc(sizeof(NODE));
    if (p_new == NULL) {
        fprintf(stderr,"Unable to allocate memory!\n");
        exit(1);
    }
    /* elements within the stack update */
    CopyToNode(item, p_new);
    if (!StackIsEmpty(p_stack))
        p_new->next = p_stack->top;
    /* pointer to stack update */
    p_stack->top = p_new;
    p_stack->num_of_items++;
    return true;
}

bool DeStack(ITEM * item, STACK * p_stack) {
    NODE * temp;
    if (StackIsEmpty(p_stack))
        return false;
    CopyToItem(p_stack->top, item);
    temp = p_stack->top;
    /* pointer to stack update */
    p_stack->top = p_stack->top->next;
    p_stack->num_of_items--;
    free(temp);
    // if (p_stack->num_of_items == 0)
    //    p_stack->top == NULL;
    return true;
}

void EmptyStack(STACK * p_stack) {
    ITEM dummy;
    while (!StackIsEmpty(p_stack))
        DeStack(&dummy, p_stack);
}

/**  || local functions definitions  **/
static void CopyToNode(ITEM item, NODE * p_node) {
    p_node->item = item;
    // p_node->next = NULL; // is it necessary?
}

static void CopyToItem(NODE * p_node, ITEM * item) {
    *item = p_node->item;
}
