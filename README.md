# BinaryTreeOperations

This C program provides functions to work with binary trees, focusing on operations related to preorder and postorder traversals, counting nodes, checking if two trees are reflections, creating a reflection of a tree, and determining if two trees are kindred spirits.

## How it Works

### Binary Tree Representation

The program represents binary trees using a basic node structure, where each node contains an integer value, a left child, and a right child.

### Preorder and Postorder Traversals

The program implements recursive functions to perform preorder and postorder traversals of a binary tree, storing the results in arrays.

### Counting Nodes

A function counts the number of nodes in a binary tree using recursion.

### Reflection Check and Creation

Functions check if two binary trees are reflections of each other. Additionally, a function creates a new binary tree that is a reflection of the original tree.

### Kindred Spirits

The program determines if two binary trees are kindred spirits. Two trees are considered kindred spirits if the preorder traversal of one tree is equal to the postorder traversal of the other tree.

## Functions

- `node *createNode(int data)`: Creates a new node with the specified data.
- `void preorder_recursive(node *root, int *array, int *i)`: Performs recursive preorder traversal.
- `void postorder_recursive(node *root, int *array, int *i)`: Performs recursive postorder traversal.
- `int count_nodes(node *root)`: Counts the number of nodes in a binary tree.
- `int isReflection(node *a, node *b)`: Checks if two trees are reflections of each other.
- `node *makeReflection(node *root)`: Creates a new binary tree that is a reflection of the original tree.
- `int kindredSpirits(node *a, node *b)`: Determines if two trees are kindred spirits.
- `double difficultyRating(void)`: Returns the difficulty rating of the project.
- `double hoursSpent(void)`: Returns the hours spent on the project.

## Usage

1. **Compile the Program:**
   - Open a terminal and navigate to the directory containing the program files.
   - Compile the program using the following command:
     ```bash
     gcc BinaryTreeOperations.c -o BinaryTreeOperations
     ```

2. **Run the Program:**
   - After compilation, run the program with the following command:
     ```bash
     ./BinaryTreeOperations
     ```

3. **View Output:**
   - The program performs various operations on binary trees and displays the results.

## Example

```bash
gcc BinaryTreeOperations.c -o BinaryTreeOperations
./BinaryTreeOperations
