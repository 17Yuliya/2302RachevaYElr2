#include "def.h"

void BubbleSort(int* arr, int size) {

    bool swap;

    for (int i = 0; i < size - 1; i++) {

        swap = false;

        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                Swap(&arr[j], &arr[j + 1]);
                swap = true;
            }
        }

        if (!swap) break;
    }
}