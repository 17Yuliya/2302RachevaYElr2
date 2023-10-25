#include "def.h"

// floor((i - 1)/2) - индекс предка по потомку

void Heap(int* arr, int size, int root) {
    int larg = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] > arr[larg])
        larg = left;

    if (right < size && arr[right] > arr[larg])
        larg = right;

    if (larg != root) {
        Swap(&arr[root], &arr[larg]);
        Heap(arr, size, larg);
    }
}

void HeapSort(int* arr, int first, int size) {
    for (int i = size / 2 - 1; i > first - 1; i--)
        Heap(arr, size, i);

    for (int i = size - 1; i > first - 1; i--) {
        Swap(&arr[first], &arr[i]);
        Heap(arr, i, first);
    }
}