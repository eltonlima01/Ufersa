#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *left, *right;
} Node;

int tree_height (Node *node)
{
    if (!node)
    {
        return -1;
    }
        
    int leftHeight = tree_height (node->left);
    int rightHeight = tree_height (node->right);

    if (leftHeight > rightHeight) { return (1 + leftHeight); }
    else { return (1 + rightHeight); }
}