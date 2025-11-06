#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *left, *right;
} Node;

int node_level (Node *node, int target, int level)
{
    if (!node) { return 0; }

    if (node->data == target) { return level; }
    int left = node_level (node->left, target, level + 1);

    if (left != 0) { return left; }

    return node_level (node->right, target, level + 1);
}