#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void swap(int *arr, int i, int j);
void buildHeap(int *arr, int start, size_t end, size_t size);

#endif
