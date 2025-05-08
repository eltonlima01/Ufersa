// Escreva uma função recursiva para gerar o `n`-ésimo número de Fibonacci.

#include <stdio.h>

int fibonacci (int n);

int main ()
{
    int n;

    printf ("[FIBONACCI] Digite o número índice da sequência: ");

    scanf ("%i", &n);

    while (n <= 0)
    {
        puts ("[ERRO] Índice inválido.\nDigite o número índice da sequência: ");
        scanf ("%i", &n);
    }

    printf ("%iº número da sequência de Fibonacci: %i\n", n, fibonacci (n - 1));

    return 0;
}

int fibonacci (int n)
{
    if ((n == 0) || (n == 1))
    {
        return n;
    }
    else
    {
        return fibonacci (n - 1) + fibonacci (n - 2);
    }
}