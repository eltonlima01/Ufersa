#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *left, *right;
} Node;

int node_depth (Node *node, int target, int depth)
{
    if (!node) { return -1; }

    if (node->data == target) { return depth; }

    int left = node_depth (node->left, target, depth + 1);

    if (left != -1) { return left; }

    return node_depth (node->right, target, depth + 1);
}