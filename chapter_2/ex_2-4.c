#include <stdio.h>
#include <string.h>


void squeeze(char s[], char c[]);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Input two strings. Characters in the second will be removed from the first.");
        return 0;
    }

    squeeze(argv[1], argv[2]);
    printf("%s\n", argv[1]);
    return 0;
}

void squeeze(char s[], char c[]) {
    int i, j, k, lim, indic;

    lim = strlen(c);
    indic = 0;
    for (i = j = 0; s[i] != '\0'; i++) {
        indic = 0;
        for (k = 0; (k < lim) && (indic == 0); ++k) {
            if (s[i] == c[k]) {
                indic = 1;
            }
        }

        if (indic == 0) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}