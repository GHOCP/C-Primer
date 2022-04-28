/* find the Dunbar Number */
#include <stdio.h>
#define DUNBAR 150

int main(void) {

    int week = 0;
    int friend_num = 5;
    int i = 0;

    while (friend_num <= DUNBAR) {
        week++;
        friend_num = (friend_num - week) * 2;
        printf("Week %d: %5d\n", week, friend_num);
    }

    return 0;
}
