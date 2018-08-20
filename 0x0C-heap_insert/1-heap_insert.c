#include "binary_trees.h"

/**
 * heap_insert - inserts value into binary heap
 * @root: root node pointer
 * @value: value to be inserted
 * Return: pointer to new node
 */
heap_t *heap_insert(binary_tree_t **root, int value)
{
	binary_tree_t *newNode = NULL;

        newNode = malloc(sizeof(binary_tree_t));
        if (!newNode)
                return (NULL);
        newNode->n = value;
        newNode->parent = parent;
        newNode->left = NULL;
        newNode->right = NULL;
        return (newNode);	
}
