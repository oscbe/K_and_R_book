#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *pn);

// int main(void) {
//     int *x;
//     getint(x);

//     printf("%d", *x);
//     return 0;
// }

int main(void) {
    int n, i;

    while (getint(&n) != EOF && i < 1)
        printf("%d\n", n);
        i++;

    return 0;
}


int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    // if (c == '+' || c == '-')
    //     c = getch();
    while (isspace(c = getch()))
        ;
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}