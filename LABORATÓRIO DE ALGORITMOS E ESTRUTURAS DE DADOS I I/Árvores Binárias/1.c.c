#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *left, *right;
} Node;

Node *create_node (int data);
void remove_node (Node *node);
Node *search_node (Node *node, int data);
Node *insert_node (Node *node, int data);

int main (int argc, char *argv [])
{
    int n [] =
    {
        atoi (argv [1]),
        atoi (argv [2]),
        atoi (argv [3]),
        atoi (argv [4]),
        atoi (argv [5]),
        atoi (argv [6])
    };

    Node *root = NULL;

    root = insert_node (root, n [0]);
    root = insert_node (root, n [1]);
    root = insert_node (root, n [2]);

    printf ("{%i, ", root->data);
    (root->left == NULL) ? printf ("null, ") : printf ("%i, ", root->left->data);
    (root->right == NULL) ? printf ("null}\n") : printf ("%i}\n", root->right->data);

    remove_node (root);
    root = NULL;

    root = insert_node (root, n [3]);
    root = insert_node (root, n [4]);
    root = insert_node (root, n [5]);

    printf ("{%i, ", root->data);
    (root->left == NULL) ? printf ("null, ") : printf ("%i, ", root->left->data);
    (root->right == NULL) ? printf ("null}\n") : printf ("%i}\n", root->right->data);

    return 0;
}

Node *create_node (int data)
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

    if (data >= node->data) { return search_node (node->right, data); }
    else { return search_node (node->left, data); }
}

Node *insert_node (Node *node, int data)
{
    if (!node) { return create_node (data); }

    if (data >= node->data) { node->right = insert_node (node->right, data); }
    else { node->left = insert_node (node->left, data); }

    return node;
}