#include <stdio.h>
#define TABSTOPS 8


int main(void) {
    int c, i, j;

    i = 1;
    while ((c = getchar()) != EOF) {
        
        if (c == '\t') {
            for (j = TABSTOPS - i; j >= 0; --j) {
                putchar(' ');
            }
            i = 1;
        }

        else if (c == '\n') {
            putchar(c);
            i = 1;
        }
        else {
            putchar(c);
            if (i == TABSTOPS) {
                i = 1;
            }
            else {
                ++i;
            }
        }
    }


    return 0;
}