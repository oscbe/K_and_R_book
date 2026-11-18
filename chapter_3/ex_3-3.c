#include <stdio.h.>

#define MAXLEN 10000

void expand(char s1[], char s2[]);

int isnum(char c);
int islower(char c);
int isupper(char c);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Input a string.");
        return 0;
    }
    char s2[MAXLEN];
    int i = 0;
    while (s2[i] != '\0') {
        s2[i++] = 0;
    }

    expand(argv[1], s2);
    printf("%s", s2);
    return 0;
}



void expand(char s1[], char s2[]) {
    int i, j, k;

    s2[0] = s1[0];
    for (i=1, j=1; s1[i+1] != '\0'; ++i) {
        if (s1[i] == '-') {
            if ((isnum(s1[i-1]) && isnum(s1[i+1]))
                || (islower(s1[i-1]) && islower(s1[i+1]))
                || (isupper(s1[i-1]) && isupper(s1[i+1]))) {

                if (s1[i-1] > s1[i+1]) {
                    for (k = s1[i-1]-1; k > s1[i+1]; --k) {
                        s2[j++] = k;
                    }
                } else if (s1[i-1] < s1[i+1]) {
                    for (k = s1[i-1]+1; k < s1[i+1]; ++k) {
                        s2[j++] = k;
                    }
                } else {
                    ++i;
                }
            } else {
                s2[j++] = s1[i];
            }
        } else {
            s2[j++] = s1[i];
        }
    }
    s2[j] = s1[i];
}


int isnum(char c) {
    if (('0' <= c) && (c <= '9')) {
        return 1;
    }
    return 0;
}

int islower(char c) {
    if (('a' <= c) && (c <= 'z')) {
        return 1;
    }
    return 0;
}

int isupper(char c) {
    if (('A' <= c) && (c <= 'Z')) {
        return 1;
    }
    return 0;
}