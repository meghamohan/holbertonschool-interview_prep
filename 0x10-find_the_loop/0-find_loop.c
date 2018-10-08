#include "lists.h"

/**
* find_listint_loop- finds loop in a LL
* @head: pointer to head
* Return: pointer to node where loop starts or else
* null
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast = head, *slow = head;

	if(!head)
		return (NULL);
	while(slow && fast)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow && fast)
			{
				if (slow == fast)
					return (slow);
				slow = slow->next;
				fast = fast->next;
			}
		}
	}
	return (NULL);
}
