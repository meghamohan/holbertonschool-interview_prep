#include "menger.h"
#include <stdio.h>
#include <math.h>


/**
* findIfMid - checks if the coordinates need to
* be empty or filled for the menger sponge
* @x: row
* @y: column
*
* Return: 1 if not a mid portion, 0 if it is
*/
unsigned int findIfMid(unsigned int x, unsigned int y)
{
	while (x && y)
	{
		if ((x % 3 == 1) && (y % 3 == 1))
			return (0);
		x = x / 3;
		y = y / 3;
	}
	return (1);
}

/**
* menger - print menger sponges
* @level: level of menger sponge
* Return: void function
*/
void menger(int level)
{
	unsigned int lvl, i, j;

	lvl = pow(3, level);
	for (i = 0; i < lvl; i++)
	{
		for (j = 0; j < lvl; j++)
		{
			/* to leave the void at the center of sponge */
			if (findIfMid(i, j))
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}
