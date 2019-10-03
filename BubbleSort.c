#include <stdio.h>

// sort the array
void bubbleSort(int array[], int size) {
    // go through the entire array multiple times to switch adjacent elements
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                // swap adjacent elements when necessary
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// print the array
void print(int array[], int size) {
    // linearly go through every element
    for(int i = 0; i < size - 1; i++) {
        printf("%d, ",array[i]);
    }
    printf("%d\n",array[size - 1]);
}


int main(void) {
    int a[3] = {2,4,1};
    int size = sizeof(a)/sizeof(a[0]);
    bubbleSort(a, size);
    print(a, size);

    int b[10] = {223,4,1,4,5,2};
    size = sizeof(b)/sizeof(int);
    bubbleSort(b, size);
    print(b, size);

    int c[7] = {2,6,1,-11,4,2,6}; // algorithm should ignore the last element, which is nto in the range of elements
    size = sizeof(c)/sizeof(int);
    bubbleSort(c, size);
    print(c, size);
    return 0;
}
