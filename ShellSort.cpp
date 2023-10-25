#include "def.h"

void ShellSortPow2(int* arr, int size) {
    for (int d = size / 2; d > 0; d /= 2) {

        for (int i = d; i < size; i++)

            for (int j = i - d; j >= 0 && arr[j] > arr[j + d]; j -= d) Swap(&arr[j], &arr[j + d]);
    }
}

int Increment(int* inc, int size_inc) {
    int i = 0;
    inc[i] = 1;

    do {
        i++;
        if (i % 2 == 0)
            inc[i] = 9 * pow(2, i) - 9 * pow(2, i / 2) + 1;
        else {
            inc[i] = 8 * pow(2, i) - 6 * pow(2, (i + 1) / 2) + 1;
        }
    } while (3 * inc[i] < size_inc);

    return i > 0 ? --i : 0;
}

void ShellSortInc(int arr[], int size) {
    int inc, i, j;
    int* seq = new int[size];
    int s = Increment(seq, size);

    for (; s >= 0; s--) {
        inc = seq[s];

        for (i = inc; i < size; i++) {
            int tmp = arr[i];
            for (j = i - inc; j >= 0 && arr[j] > tmp; j -= inc)
                arr[j + inc] = arr[j];
            arr[j + inc] = tmp;
        }
    }

    if (seq) delete[] seq;
}

int SizeH(int* h, int size_h) {
    int i = 0, k = 1;

    do {
        h[i] = (pow(3, k) - 1) / 2;
        i++; k++;
    } while (3 * h[i - 1] < size_h);

    return i > 0 ? --i : 0;
}

void ShellSortKnuth(int arr[], int size) {
    int d, i, j;
    int* seq = new int[size];
    int s = SizeH(seq, size);

    for (; s >= 0; s--) {
        d = seq[s];

        for (i = d; i < size; i++) {
            int tmp = arr[i];
            for (j = i - d; j >= 0 && arr[j] > tmp; j -= d)
                arr[j + d] = arr[j];
            arr[j + d] = tmp;
        }
    }

    if (seq) delete[] seq;
}