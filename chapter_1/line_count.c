#include <stdio.h>
#define MAXLINNE 1000

int main(void) {
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        }
    }
    printf("%d\n", nl);
    
    return 0;
}