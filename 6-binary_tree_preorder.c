#include "binary_trees.h"
/**
 * binary_tree_preorder - Function goes through a binary tree using
 * pre-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node. The value to
 * the node must be passed as a parameter to this function.
 *
 * Description: Function goes through a binary tree using pre-order
 * traversal.
 *
 * Return: Nothing.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
