#include <stdio.h>

unsigned rightrot(unsigned x, int n);
void printbits(int num);

int main(void) {
    unsigned a, b;
    a = 100051;
    printbits(a);
    
    b = rightrot(a, 4);
    printbits(b);
    return 0;
}

unsigned rightrot(unsigned x, int n) {
    unsigned bitlen;

    bitlen = sizeof(x) * 8;
    return (x >> n) | (x << bitlen - n); 
}

void printbits(int num) {
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" "); // Group by 4 bits for readability
    }
    printf("\n");
}