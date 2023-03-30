#include "binary_trees.h"
/**
 * binary_tree_insert_left - Function inserts a node as the left-child
 * of another node.
 * @parent: Pointer to the node to insert the left-child in
 * @value: The value to store in the new node.
 *
 * Description: Function inserts a node as the left-child of another node.
 * If parent already has a left-child, the new node takes the place of the
 * left-child and the old left-child is set as the left-child of the new
 * node.
 * Return: A pointer to the created node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *currentnode;
	binary_tree_t *tempnode;

	tempnode = (binary_tree_t *) malloc(sizeof(binary_tree_t));
	if (tempnode == NULL)
		return (NULL);
	tempnode->left = NULL;
	tempnode->right = NULL;
	tempnode->n = value;
	if (parent == NULL)
	{
		tempnode->parent = parent;
		parent = tempnode;
		currentnode = parent;
	}
	else if (parent->left == NULL)
	{
		tempnode->parent = parent;
		currentnode = tempnode;
		parent->left = currentnode;
		currentnode = parent->left;
	}
	else if (parent->left != NULL)
	{
		tempnode->parent = parent;
		currentnode = parent->left;
		currentnode->parent = tempnode;
		tempnode->left = currentnode;
		parent->left = tempnode;
		currentnode = parent->left;
	}
	return (currentnode);
}
