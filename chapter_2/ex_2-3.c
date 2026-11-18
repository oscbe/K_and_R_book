#include <stdio.h>
#include <string.h>
#include <math.h>

int htoi(char hex[]);
int intpow(int num, int exp);
int chtoi(char c);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s hex_string\n", argv[0]);
        return 1;
    }

    printf("%d\n", htoi(argv[1]));
    return 0;
}

int htoi(char hex[]) {
    int lim, i, j, total;

    lim = strlen(hex);
    total = 0;

    j = 0;
    if (hex[0] == '0') {
        if ((hex[1] == 'x') || (hex[1] == 'X')) {
            j = 2;
        }
    }

    for (i=lim; i>j; --i) {
        total += chtoi(hex[i-1]) * intpow(16, lim-i);
    }
    return total;
}

int intpow(int num, int exp) {
    int result;
    result = 1;

    for (exp; exp > 0; --exp) {
        result *= num;
    }
    return result;
}

int chtoi(char c) {
    if ((c >= 'A') && (c <= 'F')) {
        return 10 + (c - 'A');
    } else if ((c >= 'a') && (c <= 'f')) {
        return 10 + (c - 'a');
    }
    return c - '0';
}