#include <stdio.h>


#define LOWER 0
#define UPPER 300
#define STEP  20
/* Print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

int main(void) {

    int fahr;

    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32.0));
    }

    return 0;
}