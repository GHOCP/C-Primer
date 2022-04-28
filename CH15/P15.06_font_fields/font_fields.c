/*
    Design a bit-field structure that holds the following information:
    Font ID: A number in the range 0¨C255
    Font Size: A number in the range 0¨C127
    Alignment: A number in the range 0¨C2 represented the choices Left, Center, and Right
    Bold: Off (0) or on (1)
    Italic: Off (0) or on (1)
    Underline: Off (0) or on (1)
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* alignment */
#define LEFT 0
#define CENTER 1
#define RIGHT 2

static char * alignment[] = {"left", "center", "right"};
struct font {
    unsigned int font_ID : 8;
    unsigned int font_size : 7;
    unsigned int : 1;
    unsigned int alignment : 2;
    bool bold : 1;
    bool italic : 1;
    bool underline : 1;
    unsigned int : 3;
};

void show_info(const struct font *);
char menu(void);
char align_menu(void);
void clear(void);

int main(void) {
    char ch;
    char align_ch;
    unsigned int input;
    struct font my_font = {1, 16, LEFT, true, true, true};

    /* show original font */
    printf("The orignal fone info is:\n");
    show_info(&my_font);

    /* display menu and allow the user to manipulate the font */
    while ((ch = menu()) != 'q') {
        switch (ch) {
        /* change font */
        case 'f':
            printf("Enter font ID (0-255) to change font: ");
            while (scanf("%u", &input) != 1 || input < 0 || input > 255) {
                printf("Invalid input, please enter an integer (0~255): ");
                clear();
            }
            clear();
            my_font.font_ID = input;
            show_info(&my_font);
            break;
        /* change font-size */
        case 's':
            printf("Enter font size (0-127) : ");
            while (scanf("%u", &input) != 1 || input < 0 || input > 127) {
                printf("Invalid input, please enter an integer (0~127): ");
                clear();
            }
            clear();
            my_font.font_size = input;
            show_info(&my_font);
            break;
        /* change alignment */
        case 'a':
            align_ch = align_menu();
            switch (align_ch) {
            case 'l':
                my_font.alignment = 0;
                break;
            case 'c':
                my_font.alignment = 1;
                break;
            case 'r':
                my_font.alignment = 2;
                break;
            }
            show_info(&my_font);
            break;
        /* change alignment */
        case 'b':
            if (my_font.bold)
                my_font.bold = false;
            else
                my_font.bold = true;
            show_info(&my_font);
            break;
        /* change alignment */
        case 'i':
            if (my_font.italic)
                my_font.italic = false;
            else
                my_font.italic = true;
            show_info(&my_font);
            break;
        /* change alignment */
        case 'u':
            if (my_font.underline)
                my_font.underline = false;
            else
                my_font.underline = true;
            show_info(&my_font);
            break;
        }
    }

    printf("Bye!");
    return 0;
}

/* show info about the font */
void show_info(const struct font * ptr_s) {
    printf("***********************************\n");
    printf("ID   SIZE  ALIGNMENT    B    I    U\n");
    printf("%-3u   %-3u    %-6s     %-3s  %-3s  %-3s\n",
           ptr_s->font_ID,
           ptr_s->font_size,
           alignment[ptr_s->alignment],
           (ptr_s->bold)? "on" : "off",
           (ptr_s->italic)? "on" : "off",
           (ptr_s->underline)? "on" : "off");
    printf("***********************************\n");
}

/* main menu */
char menu(void) {
    char ch;
    printf("f)change font     s)change size     a)change alignment\n");
    printf("b)toggle bold     i)toggle italic   u)toggle underline\n");
    printf("q)quit\n");
    printf("Please enter your choice: ");
    while (strchr("fsabiuq", (ch = getchar())) == NULL) {
        clear();
        printf("Please enter the right choice(f, s, a, b, i, u or q): ");
    }
    clear();
    return ch;
}

/* alignment menu */
char align_menu(void) {
    char ch;
    printf("l)left   c)center   r)right\n");
    printf("Please enter your choice: ");
    while (strchr("lcr", (ch = getchar())) == NULL) {
        clear();
        printf("Please enter the right choice(l, c or r): ");
    }
    clear();
    return ch;
}

/* abandon the unused input */
void clear(void) {
    while (getchar() != '\n')
        continue;
}
