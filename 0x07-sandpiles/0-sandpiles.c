#include "sandpiles.h"

/**
* printGrid - print a grid
* @grid: grid to print
* 
* Return: nuthing
*/
void printGrid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j >= 1)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * checkGrid - checks if pile has values more than 3
 * @grid: grid to check
 * Return: 1 if ideal, 0 if topples
 */
int checkGrid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	return (0);
}

/**
* toppleGrid - fixes the piles which are more than 3
* @grid: grid to fix
*/
void toppleGrid(int grid[3][3])
{
	int myGrid[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				myGrid[i][j] = 1;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3 && myGrid[i][j] == 1)
			{
				grid[i][j] = grid[i][j] - 4;
				if (i > 0)
					grid[i - 1][j] += 1;
				if (i < 2)
					grid[i + 1][j] += 1;
				if (j > 0)
					grid[i][j - 1] += 1;
				if (j < 2)
					grid[i][j + 1] += 1;

			}
		}
}

/**
* sandpiles_sum - calculate sum of two sanpiles
* @grid1: first sandpile
* @grid2: second sandpile
* 
* Return: nothing
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                        grid1[i][j] = grid1[i][j] + grid2[i][j];
	while(checkGrid(grid1))
	{
		printGrid(grid1);
		toppleGrid(grid1);
	}
}
