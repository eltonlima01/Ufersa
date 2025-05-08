// Implemente busca binária em um vetor ordenado.

#include <stdio.h>

int main ()
{
    int vetor [] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34},
    vecLenght = sizeof (vetor) / sizeof (int);

    int chave;

    puts ("Elementos do vetor: ");

    for (int i = 0; i < vecLenght; i++)
    {
        (i == (vecLenght - 1)) ? printf ("%i.\n", vetor [i]) : printf ("%i, ", vetor [i]);
    }

    printf ("Digite um número elemento do vetor para ser buscado: ");

    scanf ("%i", &chave);

    int esquerda = 0, direita = vecLenght - 1, meio;

    while (esquerda <= direita)
    {
        meio = (esquerda + direita) / 2;

        if (vetor [meio] == chave)
        {
            printf ("%iº elemento do vetor: %i\n", meio + 1, vetor [meio]);
            return 0;
        }

        if (vetor [meio] < chave)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }

    printf ("O número %i não é elemento do vetor.\n", chave);

    return 0;
}