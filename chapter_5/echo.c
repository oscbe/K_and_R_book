#include <stdio.h>

// int main(int argc, char *argv[]) {
//     int i;
//     for (i = 1; i < argc; i++) {
//         printf("%s%s", argv[i], (i < argc-1) ? " ": "");
//     }
//     putchar('\n');
//     return 0;
// }


int main(int argc, char *argv[]) {
    while (--argc > 0) {
        printf("%s%s", *++argv, (argc > 0) ? " ": "");
    }
    putchar('\n');
    return 0;
}