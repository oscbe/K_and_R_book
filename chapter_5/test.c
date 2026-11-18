#include <stdio.h>
#include <string.h>

int main(void) {
    int i;
    char s[] = "hello";
    char *p;

    p = &s[0];

    printf("%d\n", p);
    printf("%d\n", s);
    printf("%c\n", *s);
    
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));

    for (i = 0; i < strlen(s); i++) {
        printf("%c\n", *(p++));
    }
    return 0;
}