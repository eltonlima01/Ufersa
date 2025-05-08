// Crie uma matriz `4x4` e calcule a soma da diagonal principal.

#include <stdio.h>

int main ()
{
    int matriz [4][4] =
    {
        {2, 8, 10, 15},
        {3, 7, 13, 14},
        {5, 8, 25, 32},
        {7, 12, 19, 45}
    };

    int soma = 0;

    puts ("Matriz 4x4:");

    for (int i = 0; i < 4; i++)
    {
        printf ("[");

        for (int j = 0; j < 4; j++)
        {
            (j == 3) ? printf ("%i]\n", matriz [i][j]) : printf ("%i, ", matriz [i][j]);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
            {
                soma += matriz [i][j];
            }
        }
    }

    printf ("Soma dos elementos da matriz principal: %i\n", soma);

    return 0;
}