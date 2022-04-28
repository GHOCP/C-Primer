/*
    The Colossus Airlines fleet consists of one plane with a seating capacity of 12. It makes
    one flight daily. Write a seating reservation program with the following features:

        a. The program uses an array of 12 structures. Each structure should hold a seat
        identification number, a marker that indicates whether the seat is assigned, the last
        name of the seat holder, and the first name of the seat holder.

        b. The program displays the following menu:
        To choose a function, enter its letter label:
        a) Show number of empty seats
        b) Show list of empty seats
        c) Show alphabetical list of seats
        d) Assign a customer to a seat assignment
        e) Delete a seat assignment
        f) Quit

        c. The program successfully executes the promises of its menu. Choices d) and e)
        require additional input, and each should enable the user to abort an entry.

        d. After executing a particular function, the program shows the menu again, except
        for choice f).

        e. Data is saved in a file between runs. When the program is restarted, it first loads in
        the data, if any, from the file.

    Colossus Airlines (from exercise 8) acquires a second plane (same capacity) and expands
    its service to four flights daily (Flights 102, 311, 444, and 519). Expand the program to
    handle four flights. Have a top-level menu that offers a choice of flights and the option
    to quit. Selecting a particular flight should then bring up a menu similar to that of
    exercise 8. However, one new item should be added: confirming a seat assignment. Also,
    the quit choice should be replaced with the choice of exiting to the top-level menu. Each
    display should indicate which flight is currently being handled. Also, the seat assignment
    display should indicate the confirmation status.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SEATS_NUM 12
#define FLIGHT_NUM 4    // numebr of flights
#define PSR 4           // number of passengers
#define NAME_LEN 12


/***************** || parameters initialization *****************/
enum flights {F102, F311, F444, F519};
const char * flight_array[4] = {"102", "311", "444", "519"};

struct name {
    char first_name[NAME_LEN];
    char last_name[NAME_LEN];
};
struct seat {
    int id;                          // 1~12
    char flights_id[FLIGHT_NUM];     // 102(1000), 311(0100), 444(0010), 519(0001)
    struct name passengers[PSR];     // maximum number of passengers for one seat: 4
};
static int size = sizeof(struct seat);      // size of a struct seat



/***************** || function prototypes *****************/
enum flights flight_menu(void);
char plane_menu(enum flights);
void flights_info (struct seat, FILE *);
void empty_seats_num(FILE *, enum flights);
void empty_seats_show(FILE *, enum flights);
void customer_assignment(FILE *, enum flights);
void seat_assignment_delete(FILE *, enum flights);
char * s_gets(char *, int);
void clear(void);



/***************** || main() *****************/
int main(void) {

    /* initialization */
    struct seat f_seat;
    enum flights flight;
    char choice;

    /* open the file */
    FILE * fp;
    if ((fp = fopen("plane.dat", "r+b")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }

    /* if the file is empty, we have to initialize the seats info in it */
    if (fread(&f_seat, size, 1, fp) != 1) {
        /* initialize the seats array and other parameters */
        struct seat flight_seats[SEATS_NUM];
        for (int i = 0; i < SEATS_NUM; i++) {
            flight_seats[i].id = i + 1;
            strncpy(flight_seats[i].flights_id, "0000", FLIGHT_NUM-1);
            for (int j = 0; j < PSR; j++) {     // initialize the name of each passenger
                strncpy(flight_seats[i].passengers[j].first_name, "\0", NAME_LEN-1);
                strncpy(flight_seats[i].passengers[j].last_name, "\0", NAME_LEN-1);
            }
        }
        int j = 0;
        while (fwrite(&flight_seats[j], size, 1, fp) == 1 && j < SEATS_NUM)
            j++;
        printf("The data file is empty. We have initialized it.\n");
    }

    /* display the current seat info of all 4 flights */
    flights_info(f_seat, fp);

    /* prompt the user the select from the menu */
    putchar('\n');
    flight = flight_menu();
    choice = plane_menu(flight);
    while (1) {
        switch (choice) {
            case 'a':
                empty_seats_num(fp, flight);
                break;
            case 'b':
                empty_seats_show(fp, flight);
                break;
            case 'c':
                customer_assignment(fp, flight);
                break;
            case 'd':
                seat_assignment_delete(fp, flight);
                break;
            case 'e':
                flight = flight_menu();
                break;
        }
        choice = plane_menu(flight);
    }

    return 0;
}



/***************** || functions definition *****************/

/* display the current seat info of all 4 flights */
void flights_info (struct seat temp, FILE * fp) {
    /* load in the data */
    rewind(fp);     // back to the top
    int k = 0;
    puts("Current information of seats assignment:");
    for (int i = 0; i < FLIGHT_NUM; i++) {
        printf("FLIGHT %s **************** \n", flight_array[i]);
        while (fread(&temp, size, 1, fp) == 1 && k < SEATS_NUM) {
            if (temp.flights_id[i] == '1')
                printf ("Seat %d in flight %s is assigned by %s %s\n",
                        temp.id, flight_array[i],
                        temp.passengers[i].first_name,
                        temp.passengers[i].last_name);
            else
                printf("Seat %d in flight %s has no assignment\n", temp.id, flight_array[i]);
            k++;
        }
        k = 0;
        rewind(fp);     // back to the top
    }
    rewind(fp);
}

/* display the flights menu */
enum flights flight_menu(void) {
    char ch;
    printf("Please select a flight:\n");
    printf("a) FLIGHT 102         b) FLIGHT 311\n");
    printf("c) FLIGHT 444         d) FLIGHT 519\n");
    printf("q) quit\n");
    printf("Enter your choice: ");

    while (strchr("abcdq", (ch = getchar())) == NULL) {
        clear();
        printf("Please enter the right choice(a, b, c, d or q): ");
    }
    clear();

    switch(ch) {
        case 'a':
            return F102;
        case 'b':
            return F311;
        case 'c':
            return F444;
        case 'd':
            return F519;
        case 'q':
            printf("Quit the system.");
            exit(3);
    }
}

/* display the plane menu */
char plane_menu (enum flights flight) {
    char ch;
    printf("**************** Current FLIGHT: %s ****************\n", flight_array[flight]);
    printf("To choose a function, enter its letter label:\n");
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Assign a customer to a seat assignment\n");
    printf("d) Delete a seat assignment\n");
    printf("e) Back to the flights menu\n");
    printf("**************** Current FLIGHT: %s ****************\n", flight_array[flight]);
    printf("Enter your choice: ");
    while (strchr("abcde", (ch = getchar())) == NULL) {
        clear();
        printf("Please enter the right choice(a, b, c, d or e): ");
    }
    clear();
    return ch;
}

/* show number of empty seats of the selected flight */
void empty_seats_num(FILE * fp, enum flights flight) {
    rewind(fp);     // back to top
    struct seat temp;
    int i = 0;
    int count = 0;
    while (fread(&temp, size, 1, fp) == 1 && i < SEATS_NUM) {
        if (temp.flights_id[flight] == '0')
            count++;
        i++;
    }
    printf("The number of empty seats in FLIGHT %s is: %d\n", flight_array[flight], count);
    printf("Keep choosing:\n");
    rewind(fp);     // back to top
}

/* Show list of empty seats */
void empty_seats_show(FILE * fp, enum flights flight) {
    rewind(fp);     // back to top
    struct seat temp;
    int i = 0;
    printf("The empty seat(s) of FLIGHT %s: ", flight_array[flight]);
    while (fread(&temp, size, 1, fp) == 1 && i < SEATS_NUM) {
        if (temp.flights_id[flight] == '0')
            printf("%3d", temp.id);
    }
    printf("\nKeep choosing:\n");
    rewind(fp);     // back to top
}

/* Assign a customer to a seat assignment */
void customer_assignment(FILE * fp, enum flights flight) {
    rewind(fp);     // back to top
    struct seat temp;
    // struct seat temp1;
    char first_name[NAME_LEN];
    char last_name[NAME_LEN];
    char confirm;
    int seat;
    int succeed = 0;

    while (!succeed) {
        /* enter the seat number(stored in seat) */
        printf("Please enter the seat number to assgin(1~12): ");
        while (scanf("%d", &seat) != 1 || (seat < 1 || seat > 12)) {
            printf("Please enter a correct seat number(1~12): ");
            clear();
        }
        clear();
        /* go to the targeted struct seat in the file */
        fseek(fp, size * (seat-1), SEEK_SET);
        fread(&temp, size, 1, fp);

        /* renew the seat info of flight */
        if (temp.flights_id[flight] == '1') {
            printf("Seat %d has been assigned, please enter another seat number.\n", seat);
            rewind(fp);     // back to top
        } else {
            strncpy(temp.passengers[flight].first_name, "\0", NAME_LEN-1);
            strncpy(temp.passengers[flight].last_name, "\0", NAME_LEN-1);

            printf("Please enter the first name: ");
            s_gets(temp.passengers[flight].first_name, NAME_LEN);
            printf("Please enter the last name: ");
            s_gets(temp.passengers[flight].last_name, NAME_LEN);

            /* entry confirmation */
            printf("You are assigning the Seat# %d in FLIGHT %s to Mr/Ms %s %s.\n",
                   temp.id, flight_array[flight],
                   temp.passengers[flight].first_name, temp.passengers[flight].last_name);
            printf("Sure to make this assignment?('y' to confirm; 'n' to abandon): ");
            while ((confirm = getchar()) != 'y' && confirm != 'n') {
                clear();
                printf("Please enter 'y' or 'n'. Enter again: ");
            }
            clear();

            if (confirm == 'y') {
                temp.flights_id[flight] = '1';  // renew the passenger state
                fseek(fp, -size, SEEK_CUR);     // set the FILE * back to the targeted struct seat
                fwrite(&temp, size, 1, fp);     // renew the seat info
                printf("You have successfully made the assignment(Seat# %d in FLIGHT %s, Mr/Ms %s %s)\n",
                       temp.id, flight_array[flight],
                       temp.passengers[flight].first_name, temp.passengers[flight].last_name);
                printf("Now back to the menu.\n");
                succeed = 1;
            } else {
                printf("Assignment aborted, back to the menu.\n");
                break;
            }
        }
    }
    rewind(fp);     // back to top
}

/* Delete a seat assignment */
void seat_assignment_delete(FILE * fp, enum flights flight) {
    rewind(fp);     // back to top
    struct seat temp;
    struct seat temp_empty = {        // empty seat
        0,
        "0000",
        {{"", ""}, {"", ""}, {"", ""}}
    };
    int seat;
    char confirm;
    int succeed = 0;

    while (!succeed) {
        /* enter the seat number(stored in seat) */
        printf("Please enter the seat number of which you want to delete the assignment(1~12): ");
        while (scanf("%d", &seat) != 1 || (seat < 1 || seat > 12)) {
            printf("Please enter a correct seat number(1~12): ");
            clear();
        }
        clear();

        /* go to the targeted struct seat in the file */
        fseek(fp, size * (seat-1), SEEK_SET);
        fread(&temp, size, 1, fp);

        /* renew the seat info of flight */
        if (temp.flights_id[flight] == '0') {
            printf("Seat %d is not assigned, please enter another seat number.\n", seat);
            rewind(fp);     // back to top
        } else {
            /* entry confirmation */
            printf ("Seat %d in flight %s is assigned by %s %s\n",
                        temp.id, flight_array[flight],
                        temp.passengers[flight].first_name,
                        temp.passengers[flight].last_name);
            printf("Sure to delete this assignment?('y' to confirm; 'n' to abandon): ");
            while ((confirm = getchar()) != 'y' && confirm != 'n') {
                clear();
                printf("Please enter 'y' or 'n'. Enter again: ");
            }
            clear();

            if (confirm == 'y') {
                temp_empty.id = seat;                   // set the id for the empty seat
                fseek(fp, -size, SEEK_CUR);             // set the FILE * back to the targeted struct seat
                fwrite(&temp_empty, size, 1, fp);       // renew the seat info

                printf("You have successfully deleted the assignment.\n");
                printf("Now back to the menu.\n");
                succeed = 1;

            } else {
                printf("Deletion aborted, back to the menu.\n");
                break;
            }
        }
    }
    rewind(fp);     // back to top
}


/* get the input string */
char * s_gets(char * st, int n) {
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}

/* abandon the unused input */
void clear(void) {
    while (getchar() != '\n')
        continue;
}














