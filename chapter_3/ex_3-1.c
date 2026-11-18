#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void) {
    int i, arr[1000];
    for (i = 0; i < 1000; ++i) {
        arr[i] = i - 3;
    }

    printf("%d", binsearch(10, arr, 1000));
    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    if (v[low] == x) {
        return low;
    }

    return -1;
}