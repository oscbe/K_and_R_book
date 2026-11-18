#include <limits.h>
#include <float.h>
#include <stdio.h>


int main(void) {
    printf("%.10e\n", FLT_MIN);
    printf("%.10e\n", FLT_MAX);

    printf("%d\n", CHAR_MAX);
    printf("%d\n", CHAR_MIN);

    printf("%d\n", INT_MIN);
    printf("%d\n", INT_MAX);

    printf("%d\n", SHRT_MIN);
    printf("%d\n", SHRT_MAX);

    printf("%d\n", LONG_MIN);
    printf("%d\n", LONG_MAX);
    return 0;
}