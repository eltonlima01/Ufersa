#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno
{
    char nome [50];
    int matricula;
    float nota;
    struct Aluno *left, *right;
} Aluno;

Aluno *insert_node (Aluno *node, char nome [], int matricula, float nota);
void in_order (Aluno *node);
void search_node (Aluno *node, char nome []);

char alunos [3][50] =
{
    {"Elton Caio Vieira de Lima"},
    {"Lucas Vieres Araújo Farias"},
    {"Artur Santos Nogueira"}
};

int main ()
{
    Aluno *root = NULL;

    root = insert_node (root, alunos [0], 20250, 50.0);
    root = insert_node (root, alunos [1], 20250, 100.0);
    root = insert_node (root, alunos [2], 20251, 75.0);

    in_order (root);

    char tmprr [50];

    scanf ("%[^\n]", tmprr);

    search_node (root, tmprr);

    return 0;
}

Aluno *create_node (char nome [], int matricula, float nota)
{
    Aluno *node = malloc (sizeof (Aluno));

    if (node)
    {
        strcpy (node->nome, nome);
        node->matricula = matricula;
        node->nota = nota;

        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

Aluno *insert_node (Aluno *node, char nome [], int matricula, float nota)
{
    if (!node) { return create_node (nome, matricula, nota); }

    if (matricula >= node->matricula) { node->right = insert_node (node->right, nome, matricula, nota); }
    else
    { node->left = insert_node (node->left, nome, matricula, nota); }

    return node;
}

void in_order (Aluno *node)
{
    if (!node) { return; }

    in_order (node->left);

    printf ("Nome: %s / Matrícula: %i / Nota: %.2f\n",
    node->nome, node->matricula, node->nota);

    in_order (node->right);
}

void search_node (Aluno *node, char nome [])
{
    if (!node) { return; }

    if (strcmp (node->nome, nome) == 0)
    {
        printf ("Aluno: %s / Matrícula: %i / Nota: %.2f\n",
        node->nome, node->matricula, node->nota);

        return;
    }
    
    search_node (node->left, nome);
    search_node (node->right, nome);
}