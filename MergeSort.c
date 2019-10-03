#include <stdio.h>

void print(int array[], int size) {
    for(int i = 0; i < size - 1; i++) {
        printf("%d, ",array[i]);
    }
    printf("%d\n",array[size - 1]);
}

void merge(int array[], int size, int lo, int mid, int hi) {
    int leftSize = mid - lo + 1;
    int left[leftSize];
    for (int i = 0; i < mid - lo + 1; i++) {
        left[i] = array[lo + i];
    }
    int rightSize = hi - mid;
    int right[rightSize];
    for (int i = 0; i < hi - mid; i++) {
        right[i] = array[i + mid + 1];
    }

    int lTemp = 0;
    int rTemp = 0;
    int i = lo;
    while (lTemp < leftSize && rTemp < rightSize) {
        if (left[lTemp] <= right[rTemp]) {
            array[i] = left[lTemp];
            lTemp++;
        } else {
            array[i] = right[rTemp];
            rTemp++;
        }
        i++;
    }

    while (lTemp < leftSize) {
        array[i] = left[lTemp];
        lTemp++;
        i++;
    }

    while (rTemp < rightSize) {
        array[i] = right[rTemp];
        rTemp++;
        i++;
    }
}

void divide(int array[], int size, int lo, int hi) {
    if (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        divide(array, size, lo, mid);
        divide(array, size, mid + 1, hi);
        merge(array, size, lo, mid, hi);
    }
}

void mergeSort(int array[], int size) {
    divide(array, size, 0, size - 1);
}

int main() {
    int a[] = {2,4,1};
    int aSize = sizeof(a) / sizeof(a[0]);
    mergeSort(a, aSize);
    print(a, aSize);

    int b[] = {4,5,6,7,0,1,2,3};
    int bSize = sizeof(b) / sizeof(b[0]);
    mergeSort(b, bSize);
    print(b, bSize);

    int c[] = {10,9,8,7,6,5,4,3,2,1,0};
    int cSize = sizeof(c) / sizeof(c[0]);
    mergeSort(c, cSize);
    print(c, cSize);

    return 0;
}
