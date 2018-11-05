#include "sort.h"

/**
 * helper - recursive function for merging
 * @start: index of first element in array
 * @size: length of array
 * @array: pointer to array
 * @temp: pointer to first ele in new array
 * Return: void
 */
void helper(size_t start, size_t size, int *array, int *temp)
{
        size_t mid;

        if (size - start >= 2)
        {
                mid = (start + size) / 2;
                helper(start, mid, array, temp);
                helper(mid, size, array, temp);
                merge(start, mid, size, array, temp);
                for (mid = start; mid < size; mid++)
                        temp[mid] = array[mid];
        }
}

/**
 * merge - merges arrays together
 * @start: first ele in subarray
 * @mid: center ele in subarray
 * @size: last ele in subarray
 * @array: sorted array
 * @temp: array
 * Return: nothing
 */
void merge(size_t start, size_t mid, size_t size, int *array, int *temp)
{
        size_t i, j, k;

        printf("Merging...\n[left]: ");
        print_array(temp + start, mid - start);
        printf("[right]: ");
        print_array(temp + mid, size - mid);
        i = start;
        j = mid;
        for (k = start; k < size; k++)
        {
                if (i < mid && (j >= size || temp[i] <= temp[j]))
                        array[k] = temp[i++];
                else
                        array[k] = temp[j++];
        }
        printf("[Done]: ");
        print_array(array + start, size - start);
}

/**
 * merge_sort - sorts array using merge sort algo
 * @array: pointer to array
 * @size: length of array
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	int i, *temp;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	for (i = 0; i < (int) size; i++)
		temp[i] = array[i];
	helper(0, size, array, temp);
	free(temp);
}
