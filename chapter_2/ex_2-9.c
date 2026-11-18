#include <stdio.h>

int bitcount(unsigned x);

int main(void) {
    unsigned a;
    a = 2000;
    printf("%d", bitcount(a));

    return 0;
}

int bitcount(unsigned x) {
    int i;

    while (x != 0) {
        i++;
        x &= (x-1);
    }
    
    return i;
}