#include "search_algos.h"


/**
 * print_array - print the array
 * @array: array to print
 * @start: start index
 * @stop: end index
 */
void print_array(int *array, int start, int stop)
{
	int i;

	printf("Searching in array: ");
	for (i = start; i < stop - 1; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}


/**
 * binary_search - binary search helper for recursion
 * @array: array
 * @start: start index
 * @stop: stop index
 * @value: value to search
 * Return: index found
 */
int binary_search(int *array, int start, int stop, int value)
{
	int mid;

	print_array(array, start, stop);
	if (array[start] != value && start == (stop - 1))
                return (-1);
	mid = start + (stop - start) / 2;
	if (array[start] == value)
		return (start);
	if (array[mid] > value)
		return (binary_search(array, start, mid, value));
	if (array[mid] < value)
		return (binary_search(array, mid, stop, value));
	if (array[mid] == value) 
		return (mid);
	return (-1);
}


/**
 * advanced_binary - binary search using recursion
 * @array: array
 * @size: array size
 * @value: value to search
 * Return: index found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size <= 0)
		return (-1);
	return (binary_search(array, 0, (int)size, value));
}
