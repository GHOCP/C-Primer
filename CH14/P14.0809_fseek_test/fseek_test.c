/* test the function fseek() with struct data storage */

#include <stdio.h>
#include <stdlib.h>
#define NUM 3
#define NAME_LEN 12

struct seat {
    int id;
    int flag_assigned;
    char first_name[NAME_LEN];
    char last_name[NAME_LEN];
};

int main (void) {

    /* initialization */
    struct seat seats[NUM] = {
        {1, 1, "Michael", "Jordon"},
        {2, 1, "Philips", "Starck"},
        {3, 1, "Peter", "Convee"},
    };
    struct seat seats_empty[NUM];       // store the data from the file
    struct seat temp;
    struct seat temp1;
    int size = sizeof(struct seat);

    /* open the file */
    FILE * fp;
    if ((fp = fopen("test.dat", "r+b")) == NULL) {
        fprintf(stderr, "Cannot open the file test.dat");
        exit(1);
    }
    /* store the data in the file */
    for (int i = 0; i < NUM; i++)
        fwrite(&seats[i], size, 1, fp);
    rewind(fp);

    /* test the read-out(normal) */
    for (int i = 0; i < NUM; i++)
        fread(&seats_empty[i], size, 1, fp);
    rewind(fp);

    for (int i = 0; i < NUM; i++)
        printf("%d, %d, %s, %s\n",
               seats_empty[i].id, seats_empty[i].flag_assigned,
               seats_empty[i].first_name, seats_empty[i].last_name);

    /* test the read-out */
    printf("***************\n");
    printf("Test the read-out(using fseek()):\n");
    printf("Now the seats_empty[0] becomes the second struct: ");
    fseek(fp, size, SEEK_SET);      // move the file pointer to the 2nd struct, and assign that value to seats_empty[0]
    fread(&temp, size, 1, fp);        // load the struct at present fp(2nd struct) to the seats_empty[0]
    printf("%d, %d, %s, %s\n",
               temp.id, temp.flag_assigned,
               temp.first_name, temp.last_name);
    /* test the write-in */
    printf("Test the write-in(using fseek()):\n");
    strncpy(temp.first_name, "Cheungpui", NAME_LEN-1);
    strncpy(temp.last_name, "Ou", NAME_LEN-1);

    fseek(fp, -size, SEEK_CUR);
    fwrite(&temp, size, 1, fp);

    fseek(fp, -size, SEEK_CUR);
    fread(&temp1, size, 1, fp);

    printf("Now the first member of the file is: ");
    printf("%d, %d, %s, %s\n",
           temp1.id, temp1.flag_assigned,
           temp1.first_name, temp1.last_name);

    return 0;
}
