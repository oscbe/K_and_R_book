#include <stdio.h>
#define swap(t, x, y) do { \
    t temp = y;         \
    y = x;              \
    x = temp;           \
} while (0)


int main(void) {
    int x, y;
    x = 10;
    y = 13;

    printf("%d, %d\n", x, y);
    swap(int, x, y);
    printf("%d, %d\n", x, y);
    return 0;
}