#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *line, int max);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int found = 0;

    if (argc != 2)
        printf("Usage: find pattern\n");
    else
        while (getline(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }
    return found;
}

int getline(char *line, int max) {
    int i, c;
    for (i = 0; (i < max) && ((c = getchar()) != EOF) && (c != '\n'); i++)
        *line++ = c;
    if (c == '\n')
        *line++ = '\n';
    *line = '\0';

    return i;
}