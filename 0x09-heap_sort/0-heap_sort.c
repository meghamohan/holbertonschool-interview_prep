#include "sort.h"

/**
 * swap - swaps two array elemeents
 * @arr: array
 * @i: first element
 * @j: second elemt
 * Return: nothing
 */
void swap(int *arr, int i, int j)
{
	int temp;

	temp = arr[j];
	arr[j] = arr[i];
	arr[i] = temp;
}


/**
 * buildHeap - sifts down the array and build heap
 * @arr: array
 * @start: root index
 * @end: index of last element
 * @size: length of array
 * Return: nothing
 */
void buildHeap(int *arr, int start, size_t end, size_t size)
{
	int child, val1, val2, val3;

	while ((start * 2) + 1 <= (int) end)
	{
		child = (start * 2) + 1;
		val1 = arr[child];
		val2 = arr[child + 1];
		val3 = arr[start];

		if (((child + 1) <= (int) end) && (val1 < val2))
			child++;
		if (val1 > val3)
		{
			swap(arr, start, child);
			print_array(arr, size);
			start = child;
		}
		else
			return;
	}
}

/**
* heap_sort - to sort an array of elements using heap sort algotihtm
* @array: array to be sorted
* @size: size of array
* Return: nothing
*/
void heap_sort(int *array, size_t size)
{
	int start, end;

	end = size - 1;
	start = ((int)size - 2) / 2;
	while (start >= 0)
	{
		buildHeap(array, start, size - 1, size);
		start--;
	}
	while (end)
	{
		swap(array, end, 0);
		print_array(array, size);
		end--;
		buildHeap(array, 0, end, size);
	}
}
