#include <stdio.h>

#define MAXLEN 1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Input string.");
        return 0;
    }
    char out[MAXLEN];

    unescape(out, argv[1]);
    printf("%s", out);
    return 0;
}


void escape(char s[], char t[]) {
    int i, j;
    j = 0;

    for (i = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[]) {
    int i, j;
    j = 0;

    for (i = 0; t[i] != '\0'; ++i) {
        if (t[i] == '\\') {
            switch (t[i + 1]) {
                case 'n':
                    s[j++] = '\n';
                    i++;
                    break;
                case 't':
                    s[j++] = '\t';
                    i++;
                    break;
                default:
                    s[j++] = t[i];
                    break;
            }
        } else {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}