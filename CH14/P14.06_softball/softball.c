/*
    A text file holds information about a softball team. Each line has data arranged as
    follows:

     4                 Jessie      Joybat       5      2      1       1
    (player's number) (first name) (last name) (bats) (hits) (walks) (RBIs)

    The first item is the player's number, conveniently in the range 0~18. The second item
    is the player's first name, and the third is the player's last name. Each name is a single
    word. The next item is the player's official times at bat, followed by the number of hits,
    walks, and runs batted in (RBIs). The file may contain data for more than one game,
    so the same player may have more than one line of data, and there may be data for
    other players between those lines. Write a program that stores the data into an array of
    structures. The structure should have members to represent the first and last names, the
    at bats, hits, walks, and RBIs (runs batted in), and the batting average (to be calculated
    later). You can use the player number as an array index. The program should read to endof-
    file, and it should keep cumulative totals for each player.

    The world of baseball statistics is an involved one. For example, a walk or reaching base
    on an error doesn't count as an at-bat but could possibly produce an RBI. But all this
    program has to do is read and process the data file, as described next, without worrying
    about how realistic the data is.

    The simplest way for the program to proceed is to initialize the structure contents to
    zeros, read the file data into temporary variables, and then add them to the contents of
    the corresponding structure. After the program has finished reading the file, it should
    then calculate the batting average for each player and store it in the corresponding
    structure member. The batting average is calculated by dividing the cumulative number
    of hits for a player by the cumulative number of at-bats; it should be a floating-point
    calculation. The program should then display the cumulative data for each player along
    with a line showing the combined statistics for the entire team.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>     // for strncpy()
#define LEN 12
#define NUM 19

struct player {
    int player_number;
    char first_name[LEN];
    char last_name[LEN];
    int bats;
    int hits;
    int walks;
    int RBIs;
};

int main(void) {

    /* initialize the array */
    struct player member[NUM];
    for (int i = 0; i < NUM; i++) {
        member[i].player_number = i;
        member[i].bats = 0;
        member[i].hits = 0;
        member[i].walks = 0;
        member[i].RBIs = 0;
        // strncpy(member[i].first_name, " ", LEN-1);
        // strncpy(member[i].last_name, " ", LEN-1);
    }

    /* open the file */
    FILE * fp;
    if ((fp = fopen("players.txt", "r")) == NULL) {
        fputs("Cannot open the file", stderr);
        exit(1);
    }
    rewind(fp);

    /* read data from the file */
    int num;
    char first_na[LEN];
    char last_na[LEN];
    int bat;
    int hit;
    int walk;
    int RBI;

    printf("The data from the file are:\n");
    while (fscanf(fp, "%d %s %s %d %d %d %d", &num, first_na, last_na, &bat, &hit, &walk, &RBI) != EOF)
        printf("%d %s %s %d %d %d %d\n", num, first_na, last_na, bat, hit, walk, RBI);
    printf("******************************************************\n");

    rewind(fp);
    while (fscanf(fp, "%d %s %s %d %d %d %d", &num, first_na, last_na, &bat, &hit, &walk, &RBI) != EOF) {
        member[num].bats = member[num].bats + bat;
        member[num].hits = member[num].hits + hit;
        member[num].walks = member[num].walks + walk;
        member[num].RBIs = member[num].RBIs + RBI;

        strncpy(member[num].first_name, first_na, LEN-1);
        strncpy(member[num].last_name, last_na, LEN-1);
        /*
        printf("%d %s %s %d %d %d %d\n",
               num, member[num].first_name, member[num].last_name,
               member[num].bats, member[num].hits, member[num].walks, member[num].RBIs);
        */
    }


        printf("player#   player name            bats   hits   walks  RBIS\n");
    for (int i = 0; i < NUM; i++) {
        printf("%-2d        %-12s%-10s %-3d    %-3d    %-3d    %-3d\n",
               member[i].player_number,
               member[i].first_name, member[i].last_name,
               member[i].bats, member[i].hits, member[i].walks, member[i].RBIs);
    }

    return 0;
}
