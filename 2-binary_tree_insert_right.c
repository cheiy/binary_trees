#include "binary_trees.h"
/**
 * binary_tree_insert_right - Function inserts a node as the right-child
 * of another node.
 * @parent: Pointer to the node to insert the right-child in
 * @value: The value to store in the new node.
 *
 * Description: Function inserts a node as the right-child of another node.
 * If parent already has a right-child, the new node takes the place of the
 * right-child and the old right-child is set as the right-child of the new
 * node.
 * Return: A pointer to the created node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *currentnode;
	binary_tree_t *tempnode;

	if (parent == NULL)
		return (NULL);
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
	else if (parent->right == NULL)
	{
		tempnode->parent = parent;
		currentnode = tempnode;
		parent->right = currentnode;
		currentnode = parent->right;
	}
	else if (parent->right != NULL)
	{
		tempnode->parent = parent;
		currentnode = parent->right;
		currentnode->parent = tempnode;
		tempnode->right = currentnode;
		parent->right = tempnode;
		currentnode = parent->right;
	}
	return (currentnode);
}
