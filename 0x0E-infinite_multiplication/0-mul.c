#include "holberton.h"
#include <stdio.h>

/**
 * isDigit - check if a str is num
 * @s: s
 * Return: 0 if num else -1
 */
int isDigit(char *s)
{
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
	}
	return (0);
}

/**
 * myStrlen - find length of string
 * @s: string
 * Return: length of string
 */
size_t myStrlen(char *s)
{
	size_t i = 0;

	if (s)
	{
		for (; s[i]; i++)
			;
	}
	return (i);
}

/**
* myPrint - prints a word
* *s: string to print
* Return: nothing
*/
void myPrint(char *s)
{
	size_t i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	_putchar('\n');
}

/**
* main - entry point
* @argc: no of args
* @argv: pointers
* Return: null
* 
*/
int main(int argc, char **argv)
{
	char *mul, *start, *stop;
	int i, j, k, l1, l2, t;

	mul = NULL;
	k = 0;
	if (argc != 3 || isDigit(argv[1]) != 0 || isDigit(argv[2]) != 0)
	{
		myPrint("Error");
		exit(98);
	}
	l1 = myStrlen(argv[1]);
	l2 = myStrlen(argv[2]);
	mul = malloc((l1 + l2) * sizeof(char));
	if (!mul)
	{
		myPrint("Error");
		exit(98);;
	}
	for (i = 0; i < (l1 + l2); i++)
		mul[i] = '0';
	start = l1 > l2 ? argv[1] : argv[2];
	stop = l1 > l2 ? argv[2] : argv[1];

	for (i = (l1 > l2 ? l2 : l1) - 1; i >= 0; i--)
	{
		for (j = (l1 > l2 ? l1 : l2) - 1; j >= 0; j--)
		{
			t = (stop[i] - '0') * (start[j] - '0');
			t += (mul[(i + j + 1)] - '0') + k;
			k = t / 10;
			mul[(i + j + 1)] = (t % 10) + '0';
		}
		if (k != 0)
			mul[i] = k + '0';
		k = 0;
	}
	for (i = 0; mul[i] == '0' && mul[i + 1] != '\0'; i++)
		;
	myPrint(mul + i);
	return (0);
}
