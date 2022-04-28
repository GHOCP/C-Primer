/* Write and test in a loop a function that
returns the number of times it has been called. */

#include <stdio.h>

static int count = 0;
void function_call(void);

int main(void) {
    for (int n = 0; n < 100; n++) {
        function_call();
    }
    printf("The function has been called %d times.", count);

    return 0;
}

void function_call() {
    count++;
}

