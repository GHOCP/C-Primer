/* list.h -- header file for a simple list type */
#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdbool.h>    // C99 feature

/** || program-specific declarations **/
#define TSIZE 45    // size of array to hold title
struct film {
    char title[TSIZE];
    int rating;
};
typedef struct film Item;

/** || general type definitions **/
typedef struct node {
    Item item;
    struct node * next;
} Node;
typedef Node * List;    // used typedef to make List the name for a pointer of this type

/*
    another definition of List:
    typedef struct list {
        Node * head; // pointer to head of list
        int size; // number of entries in list
    } List; // alternative definition of list
*/

/** || interface functions prototypes **/
/*
    Only the InitializeList() , AddItem() , and EmptyTheList() functions modify
    the list, so, technically, they are the only methods requiring a pointer argument.
    However, it can get confusing if the user has to remember to pass a List argument
    to some functions and an address of a List as the argument to others. So, to
    simplify the user¡¯s responsibilities, all the functions use pointer arguments.
*/

// operation:       initialize a list
// preconditions:   plist points to a list
// postconditions:  the list is initialized to empty
void InitializeList(List * plist);

// operation:       determine if list is empty
//                  plist points to an initialized list
// postconditions:  function returns True if list is empty
//                  and returns False otherwise
bool ListIsEmpty(const List * plist);

// operation:       determine if list is full
//                  plist points to an initialized list
// postconditions:  function returns True if list is full
//                  and returns False otherwise
bool ListIsFull(const List * plist);

// operation:       determine number of items in list
//                  plist points to an initialized list
// postconditions:  function returns number of items in list
unsigned int ListItemCount(const List * plist);

// operation:       add item to end of list
// preconditions:   item is an item to be added to list
//                  plist points to an initialized list
// postconditions:  if possible, function adds item to end
//                  of list and returns True; otherwise the
//                  function returns False
bool AddItem(Item item, List * plist);

// operation:       apply a function to each item in list
//                  plist points to an initialized list
//                  pfun points to a function that takes an
//                  Item argument and has no return value
// postcondition:   the function pointed to by pfun is
//                  executed once for each item in the list
void Traverse (const List * plist, void (* pfun)(Item item) );

// operation:       free allocated memory, if any
//                  plist points to an initialized list
// postconditions:  any memory allocated for the list is freed
//                  and the list is set to empty
void EmptyTheList(List * plist);

#endif // LIST_H_INCLUDED
