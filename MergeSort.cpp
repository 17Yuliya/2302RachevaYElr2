#include "def.h"

void Merge(int* arr, int left, int mid, int right) {
    int sizeA, sizeB;

    sizeA = mid - left + 1;
    sizeB = right - mid;

    int* A = new int[sizeA];
    int* B = new int[sizeB];

    int i = 0, j = 0, ind = left;

    for (i = 0; i < sizeA; i++) A[i] = arr[left + i];
    for (j = 0; j < sizeB; j++) B[j] = arr[mid + 1 + j];

    i = j = 0;

    while (i < sizeA && j < sizeB) {
        if (A[i] > B[j]) arr[ind] = B[j++];
        else arr[ind] = A[i++];
        ind++;
    }

    while (i < sizeA) arr[ind++] = A[i++];
    while (j < sizeB) arr[ind++] = B[j++];

    delete[] A;
    delete[] B;
}

void MergeSort(int* arr, int first, int last) {
    if (first >= last) return;

    int mid = first + (last - first) / 2;
    MergeSort(arr, first, mid);
    MergeSort(arr, mid + 1, last);
    Merge(arr, first, mid, last);
}