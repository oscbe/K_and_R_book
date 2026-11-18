#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getfloat(float *pn);

// int main(void) {
//     int *x;
//     getint(x);

//     printf("%d", *x);
//     return 0;
// }

int main(void) {
    int i;
    float n;

    while (getfloat(&n) != EOF && i < 1)
        printf("%d\n", n);
        i++;

    return 0;
}


int getfloat(float *pn) {
    int c, sign;
    float dec_mul;
    dec_mul = 1.0;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.') {
        while (isdigit(c = getch())) {
            dec_mul /= 10;
            *pn = *pn + (c - '0') * dec_mul;
        }
    }
    
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}