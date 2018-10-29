#include "sort.h"

/**
 * radix_sort - sorts array of integers in asc order
 * @array: array
 * @size: size of array
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int arr1[10][10], arr2[10];
	int sze, i, j, k, l, m, num, div, large;

	sze = (int) size;
	div = 1;
	num = 0;
	large = array[0];
	for (i = 0; i < sze; i++)
	{
		if (array[i] > large)
			large = array[i];

		while (large > 0)
		{
			num++;
			large = large / 10;
		}

		for (m = 0; m < num; m++)
		{
			for (k = 0; k < 10; k++)
				arr2[k] = 0;
			for (i = 0; i < sze ; i++)
			{
				l = ((array[i] / div) % 10);
				arr1[l][arr2[l]++] = array[i];
			}

			i = 0;
			for (k = 0; k < 10; k++)
				for (j = 0; j < arr2[k]; j++)
					array[i++] = arr1[k][j];
			print_array(array, sze);
			div *= 10;
		}
	}
}
