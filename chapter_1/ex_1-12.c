#include <stdio.h>

#define IN  1
#define OUT 0

int main(void) {
    int c, nl, nw, nc, state;

    state = IN;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        if ((c == '\n') || (c == '\t') || (c == ' ')) {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            putchar('\n');
            putchar(c);
        } else if (state == IN) {
            putchar(c);
        }
    }

    return 0;
}