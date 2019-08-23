#include <stdio.h>

// prototype the void functions
void insertionSort(int array[], int size);
void print(int array[], int size);
void shift(int array[], int i, int j);

main() {
    int a[3] = {2,4,1};
    int size = sizeof(a)/sizeof(int);
    insertionSort(a, size);
    print(a, size);

    int b[10] = {223,4,1,4,5,2};
    size = sizeof(b)/sizeof(int);
    insertionSort(b, size);
    print(b, size);

    int c[7] = {2,6,1,-11,4,2,6};
    size = sizeof(c)/sizeof(int);
    insertionSort(c, size);
    print(c, size);
}

// print the array
void print(int array[], int size) {
    // linearly go through every element
    for(int i = 0; i < size - 1; i++) {
        printf("%d, ",array[i]);
    }
    printf("%d\n",array[size - 1]);
}

// move all elements of the unsorted portion of the array into the sorted portion of the array
void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        // for each element, determine where to rotate
        for (int j = 0; j < i; j++) {
            if (array[i] < array[j]) {
                shift(array, i, j);
            }
        }
    }
}

// rotate the array indices once the rotation locations are found
void shift(int array[], int i, int j) {
    int temp = array[i];
    for (int k = i; k >= j; k--) {
        array[k] = array[k-1];
    }
    array[j] = temp;
}
