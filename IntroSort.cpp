#include "def.h"
#include <algorithm>

using namespace std;


int* MedianOfThree(int* a, int* b, int* c) {
	if (*b <= *a && *a < *c || *c <= *a && *a < *b)
		return (a);

	if (*a < *b && *b < *c || *c <= *b && *b <= *a)
		return (b);

	if (*a < *c && *c <= *b || *b < *c && *c <= *a)
		return (c);
}


void IntrosortUtil(int* arr, int* first, int* last, int maxdepth) {
	int size = last - first + 1;

	if (size <= 16) {
		InsertionSort(arr, first - arr, size);
		return;
	}

	if (maxdepth == 0) {
		make_heap(first, last + 1);
		sort_heap(first, last + 1);
		return;
	}


	int* pivot = MedianOfThree(first, first + size / 2, last);
	Swap(pivot, last);

	int tmp = Partition(arr, first - arr, last - arr);
	int* piv_ind = arr + tmp;
	IntrosortUtil(arr, first, piv_ind - 1, maxdepth - 1);
	IntrosortUtil(arr, piv_ind + 1, last, maxdepth - 1);
}


void Introsort(int* arr, int* first, int* last) {
	int maxdepth = 2 * log(last - first);
	IntrosortUtil(arr, first, last, maxdepth);
}


