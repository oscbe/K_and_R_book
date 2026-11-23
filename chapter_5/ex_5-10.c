#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP   100
#define NUMBER '0'
#define MAXVAL  100
#define BUFSIZE 100



/*  This should simply be a modification of the Polish calculator from before.
    We just need to push everything in reverse to the register, and then invoke the calculator.
    This requires modification of getch() to not use getchar().
    In fact, we should just fully replace getop() to run through the register.
    Or, I could just point getch at argv? No.

    It would probably be easier to completely rework getop() and do away with reg.
    */

int getop(char [], char []);
void push(double);
double pop(void);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int main(int argc, char *argv[]) {
    int type;
    double op2;
    char reg[MAXOP];
    char s[MAXOP];
    int i = 0, j;

    while (--argc > 0) {
        argv++;
        for (j = 0; (*argv)[j] != '\0'; j++)
            if (i < MAXOP - 2)
                reg[i++] = (*argv)[j];
        if (i < MAXOP - 2)
            reg[i++] = ' ';
    }
    reg[i++] = '\n';
    reg[i] = '\0';

    while ((type = getop(s, reg)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case 'x':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                push(fmod(pop(), op2));
                break;
            case '\n':
                printf("\t%g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}


void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[], char from[]) {
    int i, c, sgn;
    static int j = 0;

    while ((s[0] = c = from[j++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (c == '\0') {
        j--;
        return EOF;
    }

    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = from[j++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = from[j++]))
            ;
    s[i] = '\0';
    j--;
    return NUMBER;
}