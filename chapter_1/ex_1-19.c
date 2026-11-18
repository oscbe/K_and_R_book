#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void clean_array(char array[]);
void copy_reverse(char to[], char from[], int len);


int main(void) {
    int len, max;
    char line[MAXLINE];
    char reversed[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        clean_array(reversed);
        copy_reverse(reversed, line, len);
        printf("%s\n", reversed);
    }

    return 0;
}

int getline(char s[], int lim) {
    int c, i;

    for (i = 0; (i < lim-1) && ((c = getchar()) != EOF) && (c != '\n'); ++i) {
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}

void clean_array(char array[]) {
    int c, i;

    i = 0;
    while (c != '\0') {
        array[i] = 0;
        ++i;
        c = array[i];
    }
}

void copy_reverse(char to[], char from[], int len) {
    int i;
    for (i = 0; i < len; ++i) {
        to[len - 1 - i] = from[i];
    }
}