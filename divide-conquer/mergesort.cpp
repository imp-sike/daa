#include <iostream>

namespace ms {
    void Merge(int*, int, int, int);
    void MergeSort(int*, int, int);
    void Traverse(int*, int);
}

void ms::Merge(int* A, int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = 0;

    int newArr[r - l + 1];

    while (i <= m && j <= r) {
        if (A[i] < A[j]) {
            newArr[k++] = A[i++];
        } else {
            newArr[k++] = A[j++];
        }
    }

    while (i <= m) {
        newArr[k++] = A[i++];
    }

    while (j <= r) {
        newArr[k++] = A[j++];
    }

    // Copy back to the original array
    for (int m = 0; m < r - l + 1; ++m) {
        A[m + l] = newArr[m];
    }
}

void ms::MergeSort(int* array, int left, int right) {
    if (left < right) {
        int m = (left + right) / 2; // Divide
        ms::MergeSort(array, left, m);
        ms::MergeSort(array, m + 1, right);
        ms::Merge(array, left, m, right);
    }
}

void ms::Traverse(int* arr, int l) {
    for (int i = 0; i < l; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Example array
    int arr[] = {5, 4, 3, 8, 11, 2, 89, 23, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Perform merge sort
    ms::MergeSort(arr, 0, size - 1);

    // Print the sorted array
    ms::Traverse(arr, size);

    return 0;
}

