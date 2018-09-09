#include "binary_trees.h"


/**
 * reorder - restructure the heap
 * @heap: pointer to the heapnode
 */
void reorder(heap_t *heap)
{
    heap_t *num;
    int temp;

    if (heap == NULL)
        return;
    if (heap->left && heap->left->n > heap->n)
        num = heap->left;
    else
        num = heap;
    if (heap->right && heap->right->n > num->n)
        num = heap->right;

    if (num != heap)
    {
        temp = heap->n;
        heap->n = num->n;
        num->n = temp;
        reorder(num);
    }
}


/**
 * sizeOfHeap - returns size of heap
 * @h: pointer to heap node
 * Return: size of heap
 */
int sizeOfHeap(heap_t *h)
{
    int n;

    n = 0;
    if (h)
    {
        n += sizeOfHeap(h->left);
        n += sizeOfHeap(h->right);
        n++;
    }
    return (n);
}

/**
 * findLog - log of value to reposition heap
 * @n: value
 * Return: log o f the value n
 */
int findLog(int num)
{
    int n = 0;

    while (num != 1)
    {
        num >>= 1;
        n++;
    }
    return (n);
}

/**
 * heap_extract - removes the root node
 * @root: pointer to root of heap
 * Return: value in root node or else 0
 */
int heap_extract(heap_t **root)
{
    int postn, bitPostn, value, num;
    heap_t **pos;

    if (!root)
        return (0);
    postn = sizeOfHeap(*root);

    if (postn == 0)
        value = 0;
    else if (postn == 1)
    {
        value = (*root)->n;
        *root = NULL;
    }
    else
    {
        value = (*root)->n;
        bitPostn = findLog(postn);
        num = 1 << (bitPostn - 1);
        pos = root;
        while (num)
        {
            if (num & postn)
                pos = &((*pos)->right);
            else
                pos = &((*pos)->left);
            num >>= 1;
        }
        (*root)->n = (*pos)->n;
        free(*pos);
        *pos = NULL;
        reorder(*root);
    }
    return (value);
}
