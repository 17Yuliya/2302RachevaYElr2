#include "def.h"

int Partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        //0 1 2 3 4 5
        if (arr[j] <= pivot) {               //1 2 3 4 5 6 -i=0 -> 1 2 3 4 5 6 -i=1-> 1 2 3 4 5 6 -i=2-> 1 2 3 4 5 6 -i=3-> 1 2 3 4 5 6
            i++;                            //2a 2b 3 1 -> 1 2b 3 2a    piv = 2b
            Swap(&arr[i], &arr[j]);         //3 2a -> 2a 3 => 1 2b 2a 3
        }

    }
    Swap(&arr[i + 1], &arr[high]);
    return i + 1;
}


void QuickSort(int* arr, int low, int high) {
    int piv;

    if (low < high) {
        piv = Partition(arr, low, high);
        QuickSort(arr, low, piv - 1);
        QuickSort(arr, piv + 1, high);
    }
}