#include <stdio.h>

// prototype the functions
void print(int array[], int size);
void quickSort(int array[], int size);
void sort(int array[], int size, int low, int high);
int partition(int array[], int size, int start, int end);

// test code
main() {
    int a[3] = {2,4,1};
    int size = sizeof(a)/sizeof(int);
    quickSort(a, size);
    print(a, size);

    int b[10] = {23,4,1,4,5,2,0,0,0,0};
    size = sizeof(b)/sizeof(int);
    quickSort(b, size);
    print(b, size);

    int c[7] = {2,6,1,-11,4,2,6};
    size = sizeof(c)/sizeof(int);
    quickSort(c, size);
    print(c, size);
}

// sort the array
void quickSort(int array[], int size) {
    sort(array, size, 0, size - 1);
}

// create bounds to sort the array
void sort(int array[], int size, int low, int high) {
    // don't have to do anything if the bounds meet
    if (low >= high) return;
    int pivot = partition(array, size, low, high);
    sort(array, size, low, pivot);
    sort(array, size, pivot + 1, high);
}

// actually sort the array
int partition(int array[], int size, int start, int end) {
    int l = start;
    int h = end;
    int pivot = l + (h - l) / 2;
    // counter boolean to always continue this loop
    while (1) {
        // find the first values from the left and right respectively to swap, so that eventually everyting
        // to the left of the pivot is less than the pivot, and everything to the right of the pivot is greater
        // than the pivot
        while (array[l] < array[pivot]) {
            l++;
        }
        while (array[h] > array[pivot]) {
            h--;
        }
        if (l >= h) {
            break;
        } else {
            int temp = array[l];
            array[l] = array[h];
            array[h] = temp;
            l++;
            h--;
        }
    }
    return h;
}

// print the array
void print(int array[], int size) {
    // linearly go through every element
    for(int i = 0; i < size - 1; i++) {
        printf("%d, ",array[i]);
    }
    printf("%d\n",array[size - 1]);
}
