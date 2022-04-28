// addresses.c -- addresses of strings
#define MSG "I'm special."
#include <stdio.h>

int main() {

    char ar[] = MSG;
    const char *pt = MSG;
    printf("address of \"I'm special\": %p \n", "I'm special");
    printf(" address ar: %p\n", ar);
    printf(" address pt: %p\n", pt);
    printf(" address of MSG: %p\n", MSG);
    printf("address of \"I'm special\": %p \n", "I'm special");

    return 0;
}

/* What does this show? First, pt and MSG are the same address, while ar is a different address,
just as promised. Second, although the string literal "I'm special." occurs twice in the
printf() statements, the compiler chose to use one storage location, but not the same address
as MSG . The compiler has the freedom to store a literal that¡¯s used more than once in one or
more locations. Another compiler might choose to represent all three occurrences of "I'm
special." with a single storage location. Third, the part of memory used for static data is
different from that used for dynamic memory, the memory used for ar . Not only are the values
different, but this particular compiler even uses a different number of bits to represent the two
kinds of memory.*/

/* In short, initializing the array copies a string from static storage to the array, whereas initializing
the pointer merely copies the address of the string. */
