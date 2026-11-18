#include <stdio.h>

// int main(void) {
//     int bc, nlc, tc;
//     int c;

//     while ((c = getchar()) != EOF) {
//         if (c == ' ') {
//             ++bc;
//         }
//         if (c == '\n') {
//             ++nlc;
//         }
//         if (c == '\t') {
//             ++tc;
//         }
//     }
//     printf("Blank count: %d\n", bc);
//     printf("Newline count: %d\n", nlc);
//     printf("Tab count: %d\n", tc);

//     return 0;
// }

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar ('\\');
            putchar('\\');
        } else {
            putchar(c);
        }

    }

    return 0;
}