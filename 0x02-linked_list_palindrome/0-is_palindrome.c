#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * reverseList - reverses a linked list
 * @head: LL
 * Return: node of LL from the mid
 */
listint_t *reverseList(listint_t *head)
{
    listint_t *temp1, *temp2;

    temp1 = head;
    temp2 = NULL;
    if (head)
    {
        while (temp1->next)
        {
            temp2 = temp1->next;
            temp1->next = temp1->next->next;
            temp2->next = head;
            head = temp2;
        }
    }
    if (temp2)
        return (temp2);
    else
        return (temp1);
}


/**
 * is_palindrome - checks if a LL is palindrome
 * @head: LL node
 *
 * Return: 0 if not palindrome 1 if palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *walk, *temp;
    int i, length;

    i = 0;
    walk = *head;
    if (!head)
        return (1);
    for (length = 0; walk; length++)
        walk = walk->next;
    /*
    * traverse through LL till the
    * half way point
    **/
    for (walk = *head; i < (length / 2); i++)
        walk = walk->next;
    if (length % 2)
        walk = walk->next;
    walk = reverseList(walk);
    /**
    * compare reversed node and from the
    * node from the head
    **/
    for (temp = *head; i < (length / 2); i++)
    {
        if (temp->n != walk->n)
            return (0);
        walk = walk->next;
        temp = temp->next;
    }
    return (1);
}
