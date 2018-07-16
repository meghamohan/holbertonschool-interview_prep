#include "search.h"

/**
* lengthOfList - length of a skiplist
* @list: pointer to list
* Return: number of elements
*
*/
size_t lengthOfList(skiplist_t *list)
{
	skiplist_t *t = list;
	size_t  i = 0;

	while(t)
	{
		i++;
		t = t->next;
	}
	return (i);
}


/**
* linear_skip - searches for element in a skiplist
* @list: pointer to skiplist
* @value: value
* Return: pointer to node,NULL else
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp = NULL;

	if (list == NULL)
		return (NULL);

	for (temp = list;  temp != NULL; temp = temp->express)
	{
		if (temp->express && temp->express->n > value)
		{
			printf("Value checked at index [%lu] = [%d]\n",
				temp->express->index, temp->express->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
				temp->index, temp->express->index);
			break;
		}
		else if (temp->express && temp->express->n == value)
		{
			printf("Value checked at index [%lu] = [%d]\n",
				temp->express->index, temp->express->n);
			return (temp->express);
		}
		else if (temp->n == value)
		{
			printf("Value checked at index [%lu] = [%d]\n",
				temp->index, temp->n);
			return (temp);
		}
		else if (!temp->express)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				temp->index, lengthOfList(list) - 1);
			break;
		}
		else
			printf("Value checked at index [%lu] = [%d]\n",
				temp->express->index, temp->express->n);
	}
	while (temp)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			temp->index, temp->n);
		if (temp->n == value)
			return (temp);
		if (temp->n > value)
			return (NULL);
		 temp = temp->next;
	}
	return (NULL);
}
