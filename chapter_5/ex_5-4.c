#include <stdio.h>

#define MAXLEN 100


int mystrend(char *s, char *t);
int mystrlen(char *s);

int main(void) {
    char s[] = "hello";
    char t[] = "lo";
    printf("%d", mystrend(s, t));

    return 0;
}

int mystrend(char *s, char *t) {
    int i = mystrlen(s);
    int j = mystrlen(t);
    int diff = i - j;
    if (j > i) {
        printf("String `t' longer than `s'.");
        return 0;
    }
    s += diff;
    while ((*s++ == *t++) && (*s != '\0'))
        ;
    if (*s == '\0')
        return 1;
    return 0;
}


int mystrlen(char *s) {
    char *p = s;
    int i = 0;

    while (*s++)
        i++;
    
    s = p;
    return i;
}