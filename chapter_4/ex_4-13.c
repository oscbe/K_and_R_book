#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

void reverse(char s[]);

int main(void) {
    char s[MAXLEN] = "testing testing";
    
    reverse(s);
    printf("%s", s);
    return 0;
}

void reverse(char s[]) {
    static int i = 0;
    int len, d;
    len = strlen(s) - 1;

    if (i < (len/2)) {
        d = s[i];
        s[i] = s[len - i];
        s[len - i] = d;
        i++;
        reverse(s);
    }

}
