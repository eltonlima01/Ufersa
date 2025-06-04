#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *left, *right;
} Node;

void post_order (Node *node)
{
    if (!node)
    {
        post_order (node->left);
        post_order (node->right);
        printf ("%i\n", node->data);
    }
}