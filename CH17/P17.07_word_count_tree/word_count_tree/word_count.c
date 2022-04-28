/*
    Write a program that opens and reads a text file and records how many times each word
    occurs in the file. Use a binary search tree modified to store both a word and the number
    of times it occurs. After the program has read the file, it should offer a menu with three
    choices. The first is to list all the words along with the number of occurrences. The
    second is to let you enter a word, with the program reporting how many times the word
    occurred in the file. The third choice is to quit.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "tree.h"

#define MAXLEN 20

/** || function prototypes **/
char menu(void);
void get_text_words(FILE * fp, Tree * p_tree);
void show_words(const Item item);
void some_word(Tree * p_tree);
int seek_word_occ(Item item, Tree * p_tree);
static void lower_case(char * str);
static char * s_gets(char * st, int n);

/** || main function **/
int main(void) {

    Tree myTree;
    FILE * fp;
    char choice;

    InitializeTree(&myTree);

    /* when failed to open the file */
    if ((fp = fopen("test.txt", "r")) == NULL) {
        fputs("Can't open test.txt file\n", stderr);
        exit(1);
    }
    /* extract words from the file to the tree */
    get_text_words(fp, &myTree);
    /* when the file has no words */
    if (TreeIsEmpty(&myTree)) {
        fputs("No words in the file!\n", stderr);
        exit(2);
    }
    /* menu selection */
    while ((choice = menu()) != 'q') {
        switch (choice) {
        case 'a':
            printf("The occurances of each word is:\n");
            Traverse(&myTree, show_words);
            break;
        case 'b':
            some_word(&myTree);
            break;
        }
    }
    printf("DONE!");
    return 0;
}

/** || function definitions **/
/* menu for the user to choose an action */
char menu(void) {
    int ch;
    puts("Please enter your choice(a, b or q): ");
    puts("a):  list all the words along with the number of occurrences");
    puts("b):  enter a word and see its number of occrruences");
    puts("q):  quit");
    while ((ch = getchar()) != EOF) {
        while (getchar() != '\n') // discard rest of line
            continue;
        ch = tolower(ch);
        if (strchr("abq", ch) == NULL)
            puts("Please enter an a, b or q:");
        else
            break;
    }
    if (ch == EOF) // make EOF cause program to quit
        ch = 'q';
    return ch;
}

/* read each word in a file into a previously initialized tree */
void get_text_words(FILE * fp, Tree * p_tree) {
    char arr[MAXLEN] = {'\0'};
    char ch;
    int flag = 1;
    int index = 1;
    Item temp;
    temp.num = 1;

    while (flag) {
        /* get to the start of the word */
        while (!isalpha(ch = getc(fp)) && ch != EOF)
            continue;
        // when the file ends with an alpha before EOF,
        // the starter meets EOF
        if (ch == EOF)
            break;

        /* store the word into our char string, char by char */
        arr[0] = tolower(ch);
        while (isalpha(ch = getc(fp)) || ch == '\'') {
            arr[index] = tolower(ch);
            index++;
        }
        // a testing module
        // printf("%s\n", arr);
        // when the file ends with an alpha before EOF,
        // the ender meets EOF
        if (ch == EOF)
            break;

        /* add the word to our tree */
        strncpy(temp.word, arr, MAXLEN);
        AddItem(&temp, p_tree);

        /* reset the char array and the index */
        for (int i = 0; i < MAXLEN; i++)
            arr[i] = '\0';
        index = 1;
    }
}

/* tip the user to enter a word, then to see if it's in the text file(using tree); */
/* if in, show its number of occurrences */
void some_word(Tree * p_tree) {
    char arr[MAXLEN];
    int count;
    Item temp;
    temp.num = 1;

    /* read the entered word and build out Item */
    printf("Please enter a word: ");
    s_gets(arr, MAXLEN);
    lower_case(arr);    // lower each input alpha
    strncpy(temp.word, arr, MAXLEN);
    /* give feedback */
    if (arr[0] == '\0')
        printf("No word has been input!");
    else {
        if (InTree(&temp, p_tree)) {
            count = seek_word_occ(temp, p_tree);
            printf("The number of occurances of \"%s\" is: %d\n", arr, count);
        } else
            printf("\"%s\" is not in the file\n", arr);
    }
}

/* find a word in the tree, return its number of occurrences */
int seek_word_occ(const Item item, Tree * p_tree) {
    int count = 0;
    int comp;
    Trnode * p_node;
    p_node = p_tree->root;

    while (p_node != NULL) {
        if ((comp = strcmp(item.word, p_node->item.word)) < 0)
            p_node = p_node->left;
        else if ((comp = strcmp(item.word, p_node->item.word)) > 0)
            p_node = p_node->right;
        else
            break;
    }
    if (p_node != NULL)
        count = p_node->item.num;
    return count;
}

/* (funciton for the Traverse) show the info of item */
void show_words(const Item item) {
    printf("%15s: %2d\n", item.word, item.num);
}

/* lower a char string */
static void lower_case(char * str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

/* read string input */
static char * s_gets(char * st, int n) {
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
