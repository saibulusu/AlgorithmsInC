#include <stdio.h>

// prototype the functions
void print(int array[], int size);
int* merge(int* left, int leftSize, int* right, int rightSize);
void mergeSort(int array[], int size);
int* sort(int* array, int size, int low, int high);

main() {
    int a[3] = {2,4,1};
    int size = sizeof(a)/sizeof(int);
    mergeSort(a, size);
    print(a, size);

    int b[10] = {23,4,1,4,5,2,0,0,0,0};
    int size = sizeof(b)/sizeof(int);
    mergeSort(b, size);
    print(b, size);

    int c[7] = {2,6,1,-11,4,2,6};
    size = sizeof(c)/sizeof(int);
    mergeSort(c, size);
    print(c, size);
}

// sort the array
void mergeSort(int array[], int size) {
    // have to individually alter elements in this array
    int* temp = sort(array, size, 0, size);
    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
    }
    free(temp);
}

// divide method to break the element into 1-element arrays
int* sort(int* array, int size, int low, int high) {
    if (low == high) {
        int* temp = malloc(sizeof(int));
        temp[0] = array[low];
        // free(temp);
        return temp;
    } else {
        // dividing mechanism
        int mid = low + (high - low) / 2;
        int* left = sort(array, size, low, mid);
        int* right = sort(array, size, mid+1, high);
        // merge the left and right arrays
        return merge(left, mid - low + 1, right, high - mid);
    }
}

// merge two arrays
int* merge(int* left, int leftSize, int* right, int rightSize) {
    int* temp = malloc(sizeof(int) * (leftSize + rightSize));

    int l = 0;
    int r = 0;

    int i = 0;
    // actually sort the array
    while (l < leftSize && r < rightSize) {
        if (left[l] < right[r]) {
            temp[i] = left[l];
            l++;
        } else {
            temp[i] = right[r];
            r++;
        }
        i++;
    }
    
    while (l < leftSize) {
        temp[i] = left[l];
        l++;
        i++;
    }

    while (r < rightSize) {
        temp[i] = right[r];
        r++;
        i++;
    }

    free(left);
    free(right);
    
    // free(temp);
    return temp;
}

// print the array
void print(int array[], int size) {
    // linearly go through every element
    for(int i = 0; i < size - 1; i++) {
        printf("%d, ",array[i]);
    }
    printf("%d\n",array[size - 1]);
}
