#include "list.h"
/**
* add_node_end - adds a node to the end of LL
* @list: pointer to head of LL
* @str: data to be inserted
* Return: pointer to new node
*/
List *add_node_end(List **list, char *str)
{
	List *newNode = NULL;

	if (!list || !str)
		return (NULL);
	newNode = malloc(sizeof(List));
	if (!newNode)
		return (NULL);
	newNode->str = strdup(str);
	if (!newNode->str)
	{
		free(newNode);
		return (NULL);
	}
	if (*list)
	{
		newNode->next = *list;
		newNode->prev = (*list)->prev;
		(*list)->prev->next = newNode;
		(*list)->prev = newNode;
	}
	else
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		*list = newNode;
	}
	return (newNode);
}

/**
 * add_node_begin - adds a node to the start of LL
 * @list: pointer to head
 * @str: data to insert in new node
 * Return: pointer to new node
 */
List *add_node_begin(List **list, char *str)
{
	List *newNode = NULL;

	if (!list || !str)
		return (NULL);
	newNode = malloc(sizeof(list));
	if (!newNode)
		return (NULL);
	newNode->str = strdup(str);
	if (!newNode->str)
	{
		free(newNode);
		return (NULL);
	}
	if (*list)
	{
		newNode->next = *list;
		newNode->prev = (*list)->prev;
		(*list)->prev->next = newNode;
		(*list)->prev = newNode;
	}
	else
	{
		newNode->next = newNode;
		newNode->prev = newNode;
	}

	*list = newNode;
	return (newNode);
}
