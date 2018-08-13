#ifndef SEARCH_ALGOS
#define SEARCH_ALGOS

#include <stdio.h>
#include <stddef.h>

int advanced_binary(int *array, size_t size, int value);
int binary_search(int *array, int val, int left, int right);
void print_array(int *array, int start, int stop);

#endif
