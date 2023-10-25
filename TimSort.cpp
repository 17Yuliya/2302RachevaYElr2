#include "def.h"
#include "stack.h"

int GetMinrun(int size) {
    int r = 0;
    while (size >= 64) {
        r |= size & 1;
        size >>= 1;
    }
    return size + r;
}

void Reverse(int* arr, int first, int size) {
    int mid = first + size / 2 - 1;
    int last = first + size - 1;
    int tmp;
    for (int i = first; i < mid; i++) {
        tmp = arr[i];
        arr[i] = arr[last - i];
        arr[last - i] = tmp;
    }
}

//> ... > or <= .. <=
//k - индекс начала 
int GetRun(int* arr, int size, int k, int minrun) {
    int n = 1; //размер результата
    bool dec = 0; //0 - последовательность возрастает, 1 - последовательность убывает
    int ind = k;

    while (arr[ind] > arr[ind + 1] && ind < size - 1) {
        n += 1;
        ind += 1;
        dec = 1;
    }

    if (dec == 0) {
        while (arr[ind] <= arr[ind + 1] && ind < size - 1) {
            n += 1;
            ind += 1;
        }
    }
    else {
        Reverse(arr, k, n);
        int size = n;
        while (n < minrun && ind < size - 1) {
            n++; //сортировка вставками
            ind++;
        }
        InsertionSort(arr, k, n);
        return n;
    }

    while (n < minrun && ind < size - 1) {
        n++; //сортировка вставками
        ind++;
    }
    InsertionSort(arr, k, n);

    return n;
}

void MergeT(int* arr, int left, int sizeA, int right, int sizeB) {
    int* A = new int[sizeA];
    int* B = new int[sizeB];

    int i = 0, j = 0, ind = left;

    for (i = 0; i < sizeA; i++) A[i] = arr[left + i];
    for (j = 0; j < sizeB; j++) B[j] = arr[right + j];

    i = j = 0;

    while (i < sizeA && j < sizeB) {
        if (A[i] > B[j]) {
            arr[ind] = B[j++];
        }
        else {
            arr[ind] = A[i++];
        }
        ind++;
    }

    while (i < sizeA) arr[ind++] = A[i++];
    while (j < sizeB) arr[ind++] = B[j++];

    delete[] A;
    delete[] B;
}

//void Merge(int* arr, int left, int mid, int right)
bool CheckStack(stack** top, int arr[]) {
    int mid;
    stack* l1 = *top;
    stack* l2, * l3, * l4;
    l2 = l3 = l4 = NULL;
    if (l1) l2 = l1->prev;

    if (l2) l3 = l2->prev;
    else return true;

    if (l3) l4 = l3->prev;

    if (l1 && l2 && l3 && l4) {

        if ((l3->size <= (l2->size + l1->size)) || (l4->size <= (l2->size + l3->size))) {

            if (l3->size > l1->size) {
                MergeT(arr, l3->ind, l3->size, l1->ind, l1->size);
                l3->size += l1->size;
            }
            else {
                MergeT(arr, l3->ind, l3->size, l2->ind, l2->size);
                l3->size += l2->size;
                l2->ind = l1->ind;
                l2->size = l1->size;
            }

            delete l1;
            *top = l2;

            if ((*top)->ind <= (*top)->prev->ind) {
                MergeT(arr, (*top)->prev->ind, (*top)->prev->size, (*top)->ind, (*top)->size);
                (*top)->prev->size += (*top)->size;
                stack* tmp = (*top);
                *top = (*top)->prev;
                delete tmp;
            }

        }
    }

    else if (l1 && l2 && l3) {

        if (l3->size <= (l2->size + l1->size)) {

            if (l3->size > l1->size) {
                MergeT(arr, l3->ind, l3->size, l1->ind, l1->size);
                l3->size += l1->size;
            }
            else {
                mid = l3->ind + l3->size - 1;
                MergeT(arr, l3->ind, l3->size, l2->ind, l2->size);
                l3->size += l2->size;
                l2->ind = l1->ind;
                l2->size = l1->size;
            }
            delete l1;
            *top = l2;

            if ((*top)->ind <= (*top)->prev->ind) {
                MergeT(arr, (*top)->prev->ind, (*top)->prev->size, (*top)->ind, (*top)->size);
                (*top)->prev->size += (*top)->size;
                stack* tmp = (*top);
                *top = (*top)->prev;
                delete tmp;
            }
        }
    }

    else if (l1 && l2) {

        if (l2->size <= l1->size) {
            MergeT(arr, l2->ind, l2->size, l1->ind, l1->size);
            l2->size += l1->size;
            delete l1;
            *top = l2;
        }

    }

    return false;
}

void TimSort(int* arr, int size) {

    if (size < 65) { InsertionSort(arr, 0, size); return; }

    int minrun = GetMinrun(size);
    //int minrun = 5;
    int ind = 0;
    int size_run = 0;
    bool f_st = false;

    stack* l1, * l2;
    stack* top = NULL;

    while (ind < size) {
        stack* tmp = new stack;

        tmp->ind = ind;
        //GetRun(int* arr, int size, int k, int minrun)
        size_run = GetRun(arr, size, ind, minrun);
        tmp->size = size_run;

        if (top) tmp->prev = top;
        else tmp->prev = NULL;

        top = tmp;
        ind += size_run;

        CheckStack(&top, arr);
    }

    if (f_st == false) {
        while (top) {
            l1 = top;
            l2 = l1->prev;

            if (!l2) break;

            MergeT(arr, l2->ind, l2->size, l1->ind, l1->size);
            l2->size += l1->size;

            delete l1;
            top = l2;
        }
    }
}