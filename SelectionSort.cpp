#include "def.h"

void SelectionSort(int* arr, int size) {
    int min;

    for (int i = 0; i < size - 1; i++) {
        min = i;

        for (int j = i + 1; j < size; j++)
            if (arr[min] > arr[j]) min = j;

        if (min != i) Swap(&arr[i], &arr[min]);
    }

}