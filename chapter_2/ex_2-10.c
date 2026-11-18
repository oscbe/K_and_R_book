#include <stdio.h>
#include <string.h>

char lowerchar(char c);
void lowerstring(char s[]);


int main(int argc, char *argv[]) {

    lowerstring(argv[1]);
    printf("%s", argv[1]);
    return 0;
}

char lowerchar(char c) {
    return ((c >= 'A') && (c <= 'Z')) ? c - 'A' + 'a' : c;
}


void lowerstring(char s[]) {
    int len, i;

    len = strlen(s);
    for (i = 0; i < len; ++i) {
        s[i] = lowerchar(s[i]);
    }
}
