#include <stdio.h>

#define IN  1
#define OUT 0

int main(void) {
    int c, i, j, state, tally;
    int narray[20];

    tally = 0;
    state = IN;
    for (i = 0; i < (sizeof(narray)/sizeof(narray[1])); ++i) {
        narray[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if ((c == '\n') || (c == '\t') || (c == ' ')) {
            if (state == IN) {
                ++narray[tally - 1];
                tally = 0;
            }
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++tally;
        }
        else if (state == IN) {
            ++tally;
        }
    }

    for (i = 0; i < (sizeof(narray)/sizeof(narray[0])); ++i) {
        printf("%3d: ", i+1);
        for (j = 0; j < narray[i]; ++j) {
            printf("#");
        }
        printf("\n");
    }
}