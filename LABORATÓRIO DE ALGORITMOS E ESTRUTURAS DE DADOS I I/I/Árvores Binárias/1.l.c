#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *left, *right;
} Node;

int tree_terminals (Node *node)
{
    if (!node) { return 0; }

    if ((node->left == NULL) && (node->right) == NULL) { return 1; }

    return tree_terminals (node->left) + tree_terminals (node->right);
}