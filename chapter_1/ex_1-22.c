#include <stdio.h>
#define MAXLINE  1000
#define COLWIDTH 10

void cleanarray(char array[], int len);
int getline(char line[], int maxline);
void wrapline(char to[], char from[], int len);

int main(void) {
    int len, max;
    char line[MAXLINE];
    char folded[MAXLINE];

    max = 0;
    cleanarray(line, MAXLINE);
    cleanarray(folded, MAXLINE);
    while ((len = getline(line, MAXLINE)) > 0) {
        wrapline(folded, line, len);
        printf("%s", folded);
        cleanarray(folded, MAXLINE);
    }
    return 0;
}

void cleanarray(char s[], int len) {
    int i;
    for (i = 0; i < len; ++i) {
        s[i] = 0;
    }
}

int getline(char s[], int lim) {
    int c, i;
    c = 0;

    for (i = 0; (i < lim-1) && ((c = getchar()) != EOF) && (c != '\n'); ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void wrapline(char into[], char from[], int len) {
    /* How to deal with len? */
    int i, j, start, out;

    start = 0;
    out = 0;

    while (len - start > COLWIDTH) {
        for (i = start + COLWIDTH;  (i > start) && (from[i] != ' '); --i)
            ;

        if (i > start) {
            for (j = start; j < i; ++j) {
                into[out++] = from[j];
            }
            into[out++] = '\n';
            start = i + 1;
        } else {
            for (j = start; j < start + COLWIDTH; ++j) {
                into[out++] = from[j];
            }
            into[out++] = '\n';
            start = i + COLWIDTH;
        }
    }

    for (j = start; j < len; ++j)
        into[out++] = from[j];
    into[out] = '\0'; 
}