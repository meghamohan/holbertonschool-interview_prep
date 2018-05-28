#include "lists.h"
#include <stdlib.h>
/**
* insert_node - inserts a new node
* @head: head of LL
* @number: new node value
* Return: pointer to the new node
* 
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *temp, *newNode;

	temp = *head;
	newNode = malloc(sizeof(listint_t));
	if (!newNode)
		return (NULL);
	newNode->n = number;
	if (!(*head))
        {
                newNode->next = NULL;
                *head = newNode;
                return (newNode);
        }
	else if (*head && (*head)->n > number)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}
	else
	{
		while (temp->next && temp->next->n < number)
			temp = temp->next;
		newNode->next = temp->next;
		temp->next = newNode;
		return (newNode);
	}
}
	
