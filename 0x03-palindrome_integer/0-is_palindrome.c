#include "palindrome.h"

/**
* is_palindrome - checks if an int is a palindrome
* @n: number to check
* 
* Return: if palindrome 1, 0 otherwise
**/
int is_palindrome(unsigned long n)
{
    unsigned long i, j;

    i = 0;
    j = n;
    while (j > 0)
    {
        i = i * 10 + (j % 10);
        j = j / 10;
    }
    if (i == n)
        return (1);
    return (0);
}
