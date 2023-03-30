#include "binary_trees.h"
/**
 * binary_tree_node - Function creates a binary tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: The value to put in the new node
 *
 * Description: Function creates a binary tree node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *tempnode;
	binary_tree_t *currentnode;

	tempnode = (binary_tree_t *) malloc(sizeof(binary_tree_t));
	if (tempnode == NULL)
		return (NULL);

	tempnode->left = NULL;
	tempnode->right = NULL;
	tempnode->n = value;
	if (parent == NULL)
	{
		parent = tempnode;
		currentnode = parent;
	}
	else
	{
		if (parent->left == NULL)
		{
			tempnode->parent = parent;
			parent->left = tempnode;
			currentnode = parent->left;
		}
		else if (parent->right == NULL)
		{
			tempnode->parent = parent;
			parent->right = tempnode;
			currentnode = parent->right;
		}
	}
	return (currentnode);
}
