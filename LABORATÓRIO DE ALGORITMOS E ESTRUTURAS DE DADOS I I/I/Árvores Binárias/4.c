#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno
{
    char nome [50];
    int matricula;
    float nota;
    struct Aluno *left, *right;
} Aluno;

float totalMedia = 0.0f;
int count = 0;

void sum_media (Aluno *node)
{
    if (!node) { return; }

    printf ("{Aluno: %s / Nota: %.2f}\n", node->nome, node->nota);
    
    sum_media (node->left);
    sum_media (node->right);

    count++;
    totalMedia += node->nota;
}