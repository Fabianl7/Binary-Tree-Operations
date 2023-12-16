#include "KindredSpirits.h"
#include <stdio.h>
#include <stdlib.h>

// This function was taken from the binary tree lecture notes
node *createNode(int data)
{
	node *n = calloc(1, sizeof(node));
	n->data = data;
	return n;
}

// This function is a modified version of the one from the binary tree lecture notes
void preorder_recursive(node *root, int *array, int *i)
{
	if (root == NULL)
		return;

	// Goes through the root, left subtree, and then the right subtree
	array[*i] = root->data;
	(*i)++;
	preorder_recursive(root->left, array, i);
	preorder_recursive(root->right, array, i);
}

// This function is a modified version of the one from the binary tree lecture notes
void postorder_recursive(node *root, int *array, int *i)
{
	if (root == NULL)
		return;

	// Goes through the left subtree, right subtree, and then the root
	postorder_recursive(root->left, array, i);
	postorder_recursive(root->right, array, i);
	array[*i] = root->data;
	(*i)++;
}

// This function was taken from the binary tree lecture notes
int count_nodes(node *root)
{
	if (root == NULL)
		return 0;

	// Uses recursion to go through every node
	return 1 + count_nodes(root->left) + count_nodes(root->right);
}

// Checks if two binary trees are a reflection of each other
int isReflection(node *a, node *b)
{
	if (a == NULL && b == NULL)
		return 1;

	if (a == NULL || b == NULL)
		return 0;

	if (a->data != b->data)
		return 0;

	// Compares the left subtrees to right subtrees and vice-versa
	return isReflection(a->left, b->right) && isReflection(a->right, b->left);
}

// Creates a new binary tree that is a refleciton of the one passed
node *makeReflection(node *root)
{
	if (root == NULL)
		return NULL;

	// The left subtrees of the new binary tree are the right subtrees of the passed tree
	// and vice-versa
	node *newNode = createNode(root->data);

	newNode->right = makeReflection(root->left);
	newNode->left = makeReflection(root->right);

	return newNode;
}

// Checks if the two passed trees are kindred spirits while not modifying them
// Two trees are kindred spirits if the preorder of one is equal 
// to the postorder of the other one
int kindredSpirits(node *a, node *b)
{
	int i = 0, j = 0;
	int numNodesA, numNodesB;
	int *preorderA, *preorderB, *postorderA, *postorderB;
	int flag = 1;
	int *count = &i, *count2 = &j;

	// Returns the appropriate number if two nodes are NULL or if they are different
	if (a == NULL && b == NULL)
		return 1;

	if (a == NULL || b == NULL)
		return 0;

	numNodesA = count_nodes(a);
	numNodesB = count_nodes(b);

	// If the two trees have a different number of nodes, they are not kindred spirits
	if (numNodesA != numNodesB)
		return 0;

	preorderA = malloc(sizeof(int) * numNodesA);
	preorderB = malloc(sizeof(int) * numNodesB);
	postorderA = malloc(sizeof(int) * numNodesA);
	postorderB = malloc(sizeof(int) * numNodesB);

	// Fills the arrays with the preorder and postorder of each tree
	preorder_recursive(a, preorderA, count);
	preorder_recursive(b, preorderB, count2);
	i = 0, j = 0;
	postorder_recursive(a, postorderA, count);
	postorder_recursive(b, postorderB, count2);

	// Loops through the arrays comparing them
	// This also verifies if the order of the trees is swapped
	for (i = 0; i < numNodesA; i++)
	{
		if (preorderA[i] != postorderB[i])
			flag = 0;
	}

	if (flag) 
		return flag;
	flag = 1;

	// Loops through the arrays and frees their memory
	for (i = 0; i < numNodesB; i++)
	{
		if (preorderB[i] != postorderA[i])
		{
			free(preorderA);
			free(preorderB);
			free(postorderA);
			free(postorderB);

			return 0;
		}
	}

	free(preorderA);
	free(preorderB);
	free(postorderA);
	free(postorderB);

	return flag;
}

double difficultyRating(void)
{
	return 2.5;
}

double hoursSpent(void)
{
	return 12.3;
}

#include "testcase10.c"
