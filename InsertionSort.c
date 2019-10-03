#include <stdio.h>

void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j >= 1 && array[j] < array[j - 1]) {
            int temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;
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
    int a[] = {3,1,2};
    int aSize = sizeof(a) / sizeof(a[0]);
    insertionSort(a, aSize);
    print(a, aSize);

    int b[] = {223,4,1,4,5,2};
    int bSize = sizeof(b) / sizeof(b[0]);
    insertionSort(b, bSize);
    print(b, bSize);

    int c[] = {-1, 4, -2, 0, -11};
    int cSize = sizeof(c) / sizeof(c[0]);
    insertionSort(c, cSize);
    print(c, cSize);

    int d[] = {223,4,1,4,5,2};
    int dSize = sizeof(d) / sizeof(d[0]);
    insertionSort(d, dSize);
    print(d, dSize);

    return 0;
}
