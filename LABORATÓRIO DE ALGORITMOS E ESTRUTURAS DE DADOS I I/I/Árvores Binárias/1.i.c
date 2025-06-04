#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *left, *right;
} Node;

int data_sum (Node *node)
{
    if (!node) { return 0; }

    return node->data + data_sum (node->left) + data_sum (node->right);
}