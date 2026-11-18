#include <stdio.h>

int main(void) {
    int c, i, j, n_chars;
    int charray[150];
    
    n_chars = sizeof(charray) / sizeof(charray[0]);
    for (i = 0; i < n_chars; ++i) {
        charray[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if ((c != ' ') && (c != '\t') && (c != '\n'))
            ++charray[c];
    }

    for (i = 0; i < n_chars; ++i) {
        if (charray[i] != 0) {
            printf("%c: ", i);
            for (j = 0; j < charray[i]; ++j) {
                printf("#");
            }
            printf("\n");
        }
    }

    return 0;
}