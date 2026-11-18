#include <stdio.h>
/* Remove trailing blanks and tabs from lines of input. Delete blank lines. */
/* What should the pseudocode be? */
/* 
while len > 0
    copy chars
    store blanks and tabs in another array
    when encounter a non-(blank or tab), copy subarray into line
    if not, discard

*/

#define MAXLINE 1000

int main(void) {
    int state, c;
    char line[MAXLINE];
    char blanks[MAXLINE];

    while ((c = getchar()) != EOF) {

    }

    return 0;
}


/* I can't do it like this */
int getline(char s[], int lim) {
    int c, i, j;
    char blanks[MAXLINE];

    j = 0;
    for (i = 0; (i < lim-1) && ((c = getchar()) != EOF) && (c != '\n'); ++i) {
        if ((i == ' ') || (i == '\t')) {
            blanks[j] = c;
            ++j;
        }
        else {
            s[i] = c;
        }
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}