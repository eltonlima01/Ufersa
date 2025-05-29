/*
Implemente as func¸ ˜oes de criac¸ ˜ao, remoc¸ ˜ao, busca e inserc¸ ˜ao.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *left, *right;
} Node;

int main ()
{
    Node *root = malloc (sizeof (Node));

    return 0;
}

Node *new_node (int data)
{
    Node *node = malloc (sizeof (Node));

    if (node)
    {    
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

void remove_node (Node *node)
{
    if (node)
    {
        remove_node (node->left);
        remove_node (node->right);
        free (node);
    }
}

Node *search_node (Node *node, int data)
{
    if (!node) { return NULL; }

    if (node->data == data) { return node; }

    if (node->data < data) { return search_node (node->left, data); }

    if (node->data > data) { return search_node (node->right, data); }
}

Node *insert_node (Node *node, int data)
{
    if (!node) { return new_node (data); }

    if (data < node->data) { node->left = insert_node (node->left, data); }

    if (data >= node->data) { node->right = insert_node (node->right, data); }

    if (node->data == data) { return node; }

    return node;
}