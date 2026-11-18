#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Two string inputs required.");
        return 0;
    }
    printf("%d\n", any(argv[1], argv[2]));
    return 0;
}

int any(char s1[], char s2[]) {
    int i, j, lim;
    lim = strlen(s2);

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; j < lim; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;
}