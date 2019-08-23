#include <stdio.h>

main() {
    int a[10] = {0,5,2,4,-1,4,2,5,2,0};
    int size = sizeof(a)/sizeof(a[0]);
    printf("%d\n", linearSearch(a, 4, size)); // expect 3
    printf("%d\n", linearSearch(a, 1, size)); // expect -1
}

// find the index at which the desired element exists
int linearSearch(int array[], int value, int size) {
    // go through the whole array
    for (int i = 0; i < size; i++) {
        // if the current value is the desired value, then break out of the loop
        if (array[i] == value) {
            return i;
        }
    }
    // if the value does not exist in this array, then return -1
    return -1;
}
