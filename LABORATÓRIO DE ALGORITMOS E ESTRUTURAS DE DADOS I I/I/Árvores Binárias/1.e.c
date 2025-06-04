#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *left, *right;
} Node;

void pre_order (Node *node)
{
    if (!node)
    {
        printf ("%i\n", node->data);
        pre_order (node->left);
        pre_order (node->right);
    }
}