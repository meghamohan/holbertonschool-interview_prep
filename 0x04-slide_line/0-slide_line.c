#include "slide_line.h"
#include <stdio.h>

/**
 * combineLeft - combines arrays to  left
 * @arr: pointer to int array
 * @size: number of items
 */
void combineLeft(int *arr, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			arr[i + 1] *= 2;
			arr[i] = 0;
			++i;
		}
	}
}

/**
 * combineRight - combines arrays to the right
 * @arr: pointer to a int array
 * @size: number of items
 */
void combineRight(int *arr, size_t size)
{
	size_t i;

	for (i = size - 1; i + 1 > 1; i--)
	{
		if (arr[i] == arr[i - 1])
		{
			arr[i - 1] *= 2;
			arr[i] = 0;
			--i;
		}
	}
}

/**
 * shiftRight - moves right
 * @arr: pointer to int array
 * @size: number of items
 */
void shiftRight(int *array, size_t size)
{
	unsigned int i, j;

	for (i = 0; i < size - 2; i++)
	{
		if (array[i] != 0)
                {
                        j = i;
                        while (array[i + 1] == 0 && i < size - 1)
                        {
                                array[i + 1] = array[i];
                                array[i] = 0;
                                ++i;
                        }
                        i = j;
                }
	}
}

/**
 * shiftLeft - moves to left
 * @array: pointer to int array
 * @size: number of items
 */
void shiftLeft(int *array, size_t size)
{
        unsigned int i, j;

        for (i = 1; i < size; i++)
        {
                if (array[i] != 0)
                {
                        j = i;
                        while (array[i - 1] == 0 && i > 0)
                        {
                                array[i - 1] = array[i];
                                array[i] = 0;
                                --i;
                        }
                        i = j;
                }
        }
}

/**
 * slide_line - slides a line to a direction, adding indentical ints
 * @line: a pointer to an array of ints
 * @size: number of elements in the array
 * @direction: left or right
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == 0 || size < 1)
		return (0);
	switch (direction)
	{
		case SLIDE_LEFT:
			shiftLeft(line, size);
			combineLeft(line, size);
			shiftLeft(line, size);
			break;
		case SLIDE_RIGHT:
			shiftRight(line, size);
			combineRight(line, size);
			shiftRight(line, size);
	}
	return (1);
}
