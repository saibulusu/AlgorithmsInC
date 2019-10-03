#include <stdio.h>

int linearSearch(int array[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int a[] = {2,3,4,10,40};
    int aSize = sizeof(a)/sizeof(a[0]);
    int res = linearSearch(a, aSize, 10);
    printf("%d\n", res);
}
