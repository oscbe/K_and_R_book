#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define MAXSTOR 100 * MAXLINES

char *lineptr[MAXLINES];

int getline(char *, int);
int readlines(char *lineptr[], char *linestor, int maxlines, int maxstor);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

int main(void) {
    int nlines;
    char linestor[MAXSTOR];

    if ((nlines = readlines(lineptr, linestor, MAXLINES, MAXSTOR)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int getline(char line[], int maxlen) {
    int i, c;

    i = 0;
    while ((i < maxlen) && (((c = getchar()) != EOF) && (c != '\n'))) {
        line[i++] = c;
    }
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}


int readlines(char *lineptr[], char *linestor, int maxlines, int maxstor) {
    int len, nlines;
    char line[MAXLEN];
    char *p = linestor;
    char *linestop = linestor + MAXSTOR;

    nlines = 0;
    while ((len = getline(line, MAXLEN - 1)) > 0)
        if (nlines >= maxlines || p + len > linestop)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}