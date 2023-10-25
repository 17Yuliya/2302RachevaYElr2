#include "def.h"

void InsertionSort(int* arr, int first, int size) {
    int i, j;
    int cur;

    for (i = first; i < size + first; i++) {
        cur = arr[i];
        j = i - 1;

        while (j >= first && arr[j] > cur) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = cur;
    }
}