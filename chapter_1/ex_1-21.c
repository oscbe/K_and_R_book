#include <stdio.h>
#define TABSTOPS 8

/*  Have two different indexers, i and j. i follows the current position. Should we use a state? Sounds sensible.
    If we encounter a blank, flip the state and set j to i. When we encounter a non-blank, flip the state and 
    compute i - j.
    If i - j >= TABSTOPS, use (i - j) / TABSTOPS * '\t' + (i - j) % TABSTOPS * ' '.
    Else, use (i - j) * ' '.

    THIS IS WRONG. Needs to take into account where we start in relation to the tab stops.
*/

void print_blanks(int start, int stop);

int main(void) {
    int c, col, start;
    int in_blanks = 0;

    col = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!in_blanks) {
                start = col;
                in_blanks = 1;
            }
        } else {
            if (in_blanks) {
                in_blanks = 0;
                print_blanks(start, col);
            }
            putchar(c);
        }
        if (c == '\n') {
            col = 0;
        } else if (c == '\t')
            col += TABSTOPS - (col % TABSTOPS);
        else
            col++;
    }
    if (in_blanks)
        print_blanks(start, col);

    return 0;
}



void print_blanks(int start, int stop) {
    
    while (start / TABSTOPS != stop / TABSTOPS) {
        putchar('\t');
        start += TABSTOPS - (start % TABSTOPS);
    }
    while (start < stop) {
        putchar(' ');
        start++;
    }
}