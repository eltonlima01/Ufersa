#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *left, *right;
} Node;

int tree_nodes (Node *node)
{
    if (node == NULL) { return 0; }

    return 1 + tree_nodes (node->left) + tree_nodes (node->right);
}