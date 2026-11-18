#include <stdio.h>
#define MAXLEN 1000

void itoa(int num, char s[]);

int main(void) {
    char s[MAXLEN];

    itoa(1234, s);
    printf("%s", s);
    return 0;
}

void itoa(int num, char s[]) {
    static int i = 0;

    if (num / 10 > 0) {
        itoa(num / 10, s);
    }
    s[i++] = num % 10 + '0';

    if ((num / 10) == 0)
        s[i] = '\0';
}