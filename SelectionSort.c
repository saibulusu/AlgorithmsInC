#include <stdio.h>

// prototype the void functions
void selectionSort(int array[], int size);
void print(int array[], int size);
void shift(int array[], int i, int j);

main() {
    int a[3] = {2,4,1};
    int size = sizeof(a)/sizeof(int);
    selectionSort(a, size);
    print(a, size);

    int b[10] = {223,4,1,4,5,2};
    size = sizeof(b)/sizeof(int);
    selectionSort(b, size);
    print(b, size);

    int c[7] = {2,6,1,-11,4,2,6};
    size = sizeof(c)/sizeof(int);
    selectionSort(c, size);
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

// determine the smallest value at any time and place it into the sorted portion of the array at the end
void selectionSort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        // get the smallest unsorted element
        int min = i;
        for (int j = i; j < size; j++) {
            if (*(array + min) > *(array + j)) {
                min = j;
            }
        }
        // append that element to the end of the sorted portion of the array
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}
