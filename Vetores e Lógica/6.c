// Crie duas matrizes `3x3`, some seus valores e exiba o resultado.

#include <stdio.h>

#define i  3
#define j  3

int main ()
{
    int matriz0 [i][j] =
    {
        {1, 3, 5},
        {7, 9, 11},
        {13, 15, 17}
    },
    matriz1 [i][j] =
    {
        {0, 1, 1},
        {2, 3, 5},
        {8, 13, 21}
    };

    puts ("Primeira matriz: ");

    for (int linhas = 0; linhas < i; linhas++)
    {
        printf ("[");
        for (int colunas = 0; colunas < j; colunas++)
        {
            (colunas == (j - 1)) ? printf ("%i]\n", matriz0 [linhas][colunas]) : printf ("%i, ", matriz0 [linhas][colunas]);
        }
    }

    puts ("Segunda matriz:");

        for (int linhas = 0; linhas < i; linhas++)
    {
        printf ("[");
        for (int colunas = 0; colunas < j; colunas++)
        {
            (colunas == (j - 1)) ? printf ("%i]\n", matriz1 [linhas][colunas]) : printf ("%i, ", matriz1 [linhas][colunas]);
        }
    }

    puts ("Soma da primeira matriz com a segunda:");

    for (int linhas = 0; linhas < i; linhas++)
    {
        printf ("[");
        
        for (int colunas = 0; colunas < j; colunas++)
        {
            (colunas == (j - 1)) ?
            printf ("%i]\n", matriz0 [linhas][colunas] + matriz1 [linhas][colunas]) : printf ("%i, ", matriz0 [linhas][colunas] + matriz1 [linhas][colunas]);
        }
    }

    return 0;
}