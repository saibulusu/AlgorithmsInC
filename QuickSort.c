#include <stdio.h>

void print(int array[], int size) {
    for(int i = 0; i < size - 1; i++) {
        printf("%d, ",array[i]);
    }
    printf("%d\n",array[size - 1]);
}

int partition(int array[], int lo, int hi) {
    // pivot around the last element
    int pivot = array[hi];
    // go through all of the elements and keep the ones lower than the pivot to the left
    int i = lo - 1;
    // everything to the left of i+1 has to be less than the pivot
    for (int j = lo; j < hi; j++) {
        if (array[j] < pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    // swap the values at i+1 and temp
    int temp = array[i + 1];
    array[i + 1] = array[hi];
    array[hi] = temp;
    // everything has been partitioned around i+1
    return i + 1;
}

void divide(int array[], int lo, int hi) {
    if (lo < hi) {
        int p = partition(array, lo, hi);
        // partition around p
        divide(array, lo, p - 1);
        divide(array, p + 1, hi);
    }
}

void quickSort(int array[], int size) {
    divide(array, 0, size - 1);
}

int main() {
    int a[] = {2,4,1};
    int aSize = sizeof(a) / sizeof(a[0]);
    quickSort(a, aSize);
    print(a, aSize);

    int b[] = {4,5,6,7,0,1,2,3};
    int bSize = sizeof(b) / sizeof(b[0]);
    quickSort(b, bSize);
    print(b, bSize);

    int c[] = {10,9,8,7,6,5,4,3,2,1,0};
    int cSize = sizeof(c) / sizeof(c[0]);
    quickSort(c, cSize);
    print(c, cSize);

    return 0;
}

