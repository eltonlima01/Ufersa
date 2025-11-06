// Dado dois vetores de inteiros, mostre os elementos comuns entre eles.

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int vetor0 [] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34},
    vetor1 [] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    int vecLenght0 = sizeof (vetor0) / sizeof (int),
    vecLenght1 = sizeof (vetor1) / sizeof (int);

    puts ("Primeiro vetor:");

    for (int i = 0; i < vecLenght0; i++)
    {
        (i == (vecLenght0 - 1)) ? printf ("%i.\n", vetor0 [i]) : printf ("%i, ", vetor0 [i]);
    }

    puts ("Segundo vetor:");

        for (int i = 0; i < vecLenght1; i++)
    {
        (i == (vecLenght0 - 1)) ? printf ("%i.\n", vetor1 [i]) : printf ("%i, ", vetor1 [i]);
    }

    for (int i = 0; i < vecLenght0; i++)
    {
        for (int j = 0; j < vecLenght1; j++)
        {
            if (vetor0 [i] == vetor1 [j])
            {
                printf ("(%i) é elemento comum entre os dois vetores.\n", vetor0 [i]);
            }
        }
    }

    return 0;
}