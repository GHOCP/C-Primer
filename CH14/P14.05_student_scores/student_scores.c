/*
Write a program that fits the following recipe:

    a. Externally define a name structure template with two members: a string to hold the
    first name and a string to hold the second name.

    b. Externally define a student structure template with three members: a name
    structure, a grade array to hold three floating-point scores, and a variable to hold
    the average of those three scores.

    c. Have the main() function declare an array of CSIZE (with CSIZE = 4 ) student
    structures and initialize the name portions to names of your choice. Use functions
    to perform the tasks described in parts d., e., f., and g.

    d. Interactively acquire scores for each student by prompting the user with a student
    name and a request for scores. Place the scores in the grade array portion of the
    appropriate structure. The required looping can be done in main() or in the
    function, as you prefer.

    e. Calculate the average score value for each structure and assign it to the proper
    member.

    f. Print the information in each structure.

    g. Print the class average for each of the numeric structure members.

*/

#include <stdio.h>
#include <string.h>
#define CSIZE 4
#define LEN 12

struct name {
    char first[LEN];
    char last[LEN];
};

struct student {
    struct name stu_name;
    float grades[3];
    float average;
};

void scores_input(struct student stu[], int n);
void show_info(const struct student stu[], int n);

int main(void) {

    struct student students[CSIZE] = {
        {.stu_name = {"Monica", "Chole"}},
        {.stu_name = {"James", "Hardon"}},
        {.stu_name = {"Stephen", "Curry"}},
        {.stu_name = {"Perry", "Loran"}}
    };
    scores_input(students, CSIZE);
    show_info(students, CSIZE);

    return 0;
}

void scores_input(struct student stu[], int n) {
    for (int i = 0; i < n ; i++) {
        printf("Please enter three scores for student %s %s (seperated by space:)\n",
               stu[i].stu_name.first, stu[i].stu_name.last);
        while (scanf("%f %f %f", &stu[i].grades[0], &stu[i].grades[1], &stu[i].grades[2]) != 3) {
            printf("Invalid input, please enter again:");
            while (getchar() != '\n')
                continue;
        }
        while (getchar() != '\n')
                continue;
    }
    for (int i = 0; i < n ; i++)
        stu[i].average = (stu[i].grades[0] + stu[i].grades[1] + stu[i].grades[3]) / 3;
}

void show_info(const struct student stu[], int n) {
        printf("The info of students as follow:\n");
        printf("      NAME               SCORE1   SCORE2   SCORE3   AVERAGE\n");
    for (int i = 0; i < n; i++) {
        printf("%-10s %-10s    %-4.2lf    %-4.2lf    %-4.2lf    %-4.2lf\n",
               stu[i].stu_name.first, stu[i].stu_name.last,
               stu[i].grades[0], stu[i].grades[1], stu[i].grades[2],
               stu[i].average);
    }
}
