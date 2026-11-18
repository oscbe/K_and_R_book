#include <stdio.h>

// unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
void printbits(int num);

int main(void) {
    unsigned a, b, c;
    a = 77;
    b = 22;

    printbits(a);
    printbits(b);

    c = setbits(a, 27, 3, b);
    printbits(c);
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned len, indic;
    len = 8 * sizeof(x);

    indic = (~0 << len - p) | ~(~0 << len - p - n);
    return (x & indic) | (y & ~indic);
}

void printbits(int num) {
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" "); // Group by 4 bits for readability
    }
    printf("\n");
}
