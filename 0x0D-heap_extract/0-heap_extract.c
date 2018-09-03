#include "binary_trees.h"


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
 * heap_extract - removes the root node
 * @root: pointer to root of heap
 * Return: value in root node or else 0
 */
int heap_extract(heap_t **root)
{
    int postn, value;

    if (!root)
        return (0);
    postn = sizeOfHeap(*root);

    if (postn == 0)
        value = 0;

    return (value);
}
