#ifndef NAMES_ST_H_INCLUDED
#define NAMES_ST_H_INCLUDED

// names_st.h -- names_st structure header file
// constants
#include <string.h>
#define SLEN 32

// structure declarations
struct names_st {
    char first[SLEN];
    char last[SLEN];
};

// typedefs
typedef struct names_st names;

// function prototypes
void get_names(names *);
void show_names(const names *);
char * s_gets(char * st, int n);


#endif // NAMES_ST_H_INCLUDED
