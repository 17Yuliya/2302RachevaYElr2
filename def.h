#pragma once

#include <iostream>
#include <fstream>
#include <chrono>
#include <cmath>

#include "stack.h"

using namespace std;

int ReadFile(ifstream& in);
int* CreateArr(int size, ifstream& in);
void OutArr(int* arr, int size, ofstream& out);
void Swap(int* a, int* b);

void SelectionSort(int* arr, int size);
void InsertionSort(int* arr, int first, int size);
void BubbleSort(int* arr, int size);
void QuickSort(int* arr, int low, int high);
void HeapSort(int* arr, int first, int size);

void Merge(int* arr, int left, int mid, int right);
void MergeSort(int* arr, int first, int last);
void ShellSortPow2(int* arr, int size);
void ShellSortInc(int arr[], int size);
void ShellSortKnuth(int arr[], int size);
void TimSort(int* arr, int size);
int Partition(int* arr, int low, int high);

//void Introsort(int arr[], int first, int last);
void Introsort(int* arr, int* begin, int* end);

void Clear();