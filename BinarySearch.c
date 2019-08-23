#include <stdio.h>

main() {
    // ideally the array is sorted
    int a[3] = {1,2,3};
    int size = sizeof(a)/sizeof(a[0]);
    printf("%d\n",binarySearch(a,2,size));
    printf("%d\n",binarySearch(a,6,size)); // 6 does not exist in the array

    int b[4] = {1,4,2,3};
    size = sizeof(b)/sizeof(b[0]);
    printf("%d\n",binarySearch(b,4,size)); // 4 does exist in the array, but it will not be found with binary search
    printf("%d\n",binarySearch(b,1,size)); // 1 does exist in the array and is found at the rigth location
    printf("%d\n",binarySearch(b,4,size)); // 3 does exist in the array, but it will not be foudn at the right location
}

// check some of the elements to know where the desired value is
int binarySearch(int array[], int value, int size) {
    int low = 0;
    int high = size;
    // while there are still values to check, as the bounds have not met
    while (high >= low) {
        // gather the index we will check and compare to the desired value
        int mid = (low + high) / 2;
        if (*(array + mid) == value) {
            return mid;
        } else if (*(array + mid) < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    // if the value does not exist in this array, return -1
    return -1;
}
