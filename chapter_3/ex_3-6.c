#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

void reverse(char s[]);
void itoa(int n, char s[], int w);

int main(void) {
    printf("printing something\n");
    int i = 12;
    // int i = 1<<31;
    int w = 5;
    char c[MAXLEN];

    itoa(i, c, w);
    printf("%s", c);
    return 0;
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[], int w) {
    int i, sign;
    i = 0;

    if (n > 0) {
        sign = 1;
    } else {
        sign = -1;
    }
    do {
        s[i++] = sign * (n % 10) + '0';
    } while (((n /= 10) != 0) || (i < w));

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}