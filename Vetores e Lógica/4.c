// Leia 10 números inteiros e mostre quantas vezes cada número distinto aparece.

#include <stdio.h>

int main ()
{
    int vetor [10], contador = 0;

    puts ("Digite 10 (dez) números:");

    for (int i = 0; i < 10; i++)
    {
        scanf ("%i", &vetor[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (vetor[i] == vetor[j])
            {
                contador++;
            }

            if (j == 9)
            {
                printf ("O número %i apareceu %i vez(es).\n", vetor[i], contador);

                contador = 0;
            }
        }
    }

    return 0;
}