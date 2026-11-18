#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

void reverse(char s[]);
void itob(int n, char s[], int b);
char modb(int n, int b);


/* How do I do this? Do I want to say mod(16) or mod(h)? mod(h) is not intuitive, so do mod(16).
Then we need to implement a special mod function that does:
compute x = n mod base;
convert x from int to char (correctly);
return x;
*/

int main(void) {
    printf("printing something\n");
    int i = -55;
    // int i = 1<<31;
    char c[MAXLEN];

    itob(i, c, 16);
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

void itob(int n, char s[], int b) {
    int i, sign;

    i = 0;
    if (n > 0) {
        sign = 1;
    } else {
        sign = -1;
    }
    do {
        s[i++] = modb(n, b);
    } while ((n /= b) != 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}


char modb(int n, int b) {
    int sign, x;
    if (n < 0) {
        sign = -1;
    } else {
        sign = 1;
    }

    x = (n % b);

    if (x < 10) {
        return sign * x + '0';
    } else {
        return sign * (x % 10) + 'a';
    }
}