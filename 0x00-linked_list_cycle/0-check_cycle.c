#include "lists.h"
/**
* check_cycle - function to check if a LL
* has a cycle or not
* @list: pointer to head of the list
* Return: 1 if it has a cycle, 0 if not
*/

int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	slow = list;
	fast = list;
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
