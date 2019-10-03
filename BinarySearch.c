#include <stdio.h>

int binarySearch(int array[], int size, int key) {
    int lo = 0;
    int hi = size;
    while (hi >= lo) {
        int mid = (lo + hi) / 2;
        if (*(array + mid) == key) {
            return mid;
        } else if (*(array + mid) < key) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    int a[] = {1,2,3,4,5};
    int aSize = sizeof(a) / sizeof(a[0]);
    int res = binarySearch(a, aSize, 4);
    printf("%d\n",res);
    int b[] = {1,3,2,7,-1};
    int bSize = sizeof(b) / sizeof(b[0]);
    res = binarySearch(b, bSize, -1);
    printf("%d\n", res);
    res = binarySearch(b, bSize, 1);
    printf("%d\n", res);
    return 0;
}
