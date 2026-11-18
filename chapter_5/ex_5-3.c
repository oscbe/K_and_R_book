#include <stdio.h>
#define MAXLINE 100

void mystrcat(char *s, char *t);

int main(void) {
    char s1[MAXLINE] = "hello there";
    char s2[MAXLINE] = ", how are you?";

    mystrcat(&s1[0], &s2[0]);
    printf("%s", s1);
    return 0;
}

void mystrcat(char *s, char *t) {
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}