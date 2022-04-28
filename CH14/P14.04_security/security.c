/*
    Write a program that creates a structure template with two members according to the
    following criteria:

        a. The first member is a social security number. The second member is a structure
        with three members. Its first member contains a first name, its second member
        contains a middle name, and its final member contains a last name. Create and
        initialize an array of five such structures. Have the program print the data in this
        format:
        Dribble, Flossie M. ¨C¨C 302039823

    Only the initial letter of the middle name is printed, and a period is added. Neither the
    initial (of course) nor the period should be printed if the middle name member is empty.
    Write a function to do the printing; pass the structure array to the function.

        b. Modify part a. by passing the structure value instead of the address.
 */

#include <stdio.h>
#include <string.h>
#define LEN 12
#define NUM 5

struct name {
    char first[LEN];
    char last[LEN];
    char middle[LEN];
};

struct member {
    char security_num[LEN];
    struct name person;
};

void show_info(const struct member people[], int n);

int main(void) {

    struct member people[NUM] = {
        {"302039823", {"Dribble", "Flossie", "Menson"}},
        {"333337001", {"Dribble", "Flossie", "\0"}},
        {"123540554", {"Yooohs", "Flossie", "Ohenim"}},
        {"546877524", {"Dribble", "Flossie", "\0"}},
        {"145120230", {"Dribble", "Flossie", "Jenson"}},
    };
    show_info(people, NUM);

    return 0;
}

void show_info(const struct member people[], int n) {
    for (int i = 0; i < n; i++)
        printf("%s, %s %c%c --- %s\n",
               people[i].person.first,
               people[i].person.last,
               people[i].person.middle[0],
               (people[i].person.middle[0] == '\0' ? '\0' : '.'),
               people[i].security_num);
}
