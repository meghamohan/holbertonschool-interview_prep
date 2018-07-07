#include "binary_trees.h"

/**
* newNode - creates a new node
* 
* Return: return the new node
*/
avl_t *newNode(void)
{
	avl_t *new = malloc(sizeof(avl_t));

	if (new == NULL)
		exit(EXIT_FAILURE);
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;

	return (new);
}

/**
* arrayToAVL - AVL from array 
* @root: current node ptr
* @array: pointer to sorted array
* @start: start index
* @end: last index
* Return: root node of AVL tree
*/
avl_t *arrayToAVL(avl_t *root, int *array, size_t start, size_t end)
{
	size_t mid, data;
	avl_t *lft, *rgt;

	/*
	* printf("start = %u, end = %u\n",
	*  (unsigned)start, (unsigned)end);
	*/
	mid = (start + end) / 2;
	data = array[mid];
	root->n = data;
	if (start < mid)
	{
		lft = newNode();
		rgt = newNode();
		lft->parent = root;
		rgt->parent = root;
		root->left = arrayToAVL(lft, array, start, mid - 1);
		/*
		* printf("%d\n", root->left->n);
		*/
		root->right = arrayToAVL(rgt, array, mid + 1, end);
		/*
		* printf("%d\n", root->right->n);
		*/
	}
	else if (mid + 1 == end)
	{
		rgt = newNode();
		root->right = rgt;
		rgt->n = array[end];
	}
	return (root);	
}
/**
* sorted_array_to_avl - creates AVL tree from a
*  sorted array
* @array: pointer to sorted array
* @size: number of elements in array
* Return: root node of AVL tree
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!size || !array)
		return (NULL);
	root = newNode();
	return (arrayToAVL(root, array, 0, size - 1));
}
