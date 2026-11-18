#include <stdio.h>

#define MAXLEN 1000

void mystrncpy(char *s, char *t, int n);
void mystrncat(char *s, char *t, int n);
int mystrncmp(char *s, char *t, int n);
int mystrlen(char *s);

int main(void) {
    char s1[] = "but soft, what light through yonder window breaks?";
    char s2[MAXLEN];

    mystrncpy(s2, s1, 12);
    printf("%s\n", s2);

    char s3[100] = "bingle";
    char s4[100] = "bongle";
    mystrncat(s3, s4, 10);
    printf("%s\n", s3);


    char s5[100] = "testingabcdefg";
    char s6[100] = "testinghijklmn";
    printf("%d\n", mystrncmp(s5, s6, 8));
    return 0;
}

void mystrncpy(char *s, char *t, int n) {
    while ((n-- > 0) && (*t != '\0'))
        *s++ = *t++;
    *s = '\0';
}

void mystrncat(char *s, char *t, int n) {
    while (*s)
        s++;
    while ((n-- > 0) && (*t != '\0'))
        *s++ = *t++;
    *s = '\0';
}

int mystrncmp(char *s, char *t, int n) {
    int i = mystrlen(s);
    int j = mystrlen(t);


    while ((n-- > 0) && (i-- > 0) && (j-- > 0)) {
        if (*s++ != *t++)
            return 0;
    }
    return 1;

}

int mystrlen(char *s) {
    char *p = s;
    int i = 0;

    while (*s++)
        i++;
    
    s = p;
    return i;
}