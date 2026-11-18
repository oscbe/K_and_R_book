#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
void printbits(int num);

int main(void) {
    unsigned a, b;
    a = 100051;
    printbits(a);
    
    b = invert(a, 24, 4);
    printbits(b);
    return 0;
}

unsigned invert(unsigned x, int p, int n) {
    int numbits;
    unsigned indic;
    numbits = 8 * sizeof(x);

    indic = (~0 << numbits - p) | ~(~0 << numbits - p - n);
    return (x & indic) | (~x & ~indic);
}

void printbits(int num) {
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" "); // Group by 4 bits for readability
    }
    printf("\n");
}