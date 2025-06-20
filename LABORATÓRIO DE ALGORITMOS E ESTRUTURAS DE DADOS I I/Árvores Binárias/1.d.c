#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *left, *right;
} Node;

void order (Node *node)
{
    if (node)
    {
        printf ("%i\n", node->data);
        order (node->left);
        order (node->right);
    }
}