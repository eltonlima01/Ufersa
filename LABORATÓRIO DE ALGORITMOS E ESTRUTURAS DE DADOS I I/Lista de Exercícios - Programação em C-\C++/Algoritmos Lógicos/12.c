// Dada uma string (array de `char`), diga se ela é um palíndromo (ex: “arara”, “radar”).

#include <stdio.h>
#include <string.h>

int main ()
{
    char string[25], tmprr [25];

    printf ("[VERIFICADOR DE PALÍNDROMO] Digite uma palavra: ");

    scanf ("%s", string);

    int strLenght = strlen (string), temp = strLenght - 1;

    for (int i = 0; i < strLenght; i++)
    {
        tmprr [i] = string [temp];

        temp--;
    }

    if (strcmp (string, tmprr) == 0)
    {
        printf ("Essa palavra é um palíndromo: %s\n", string);
    }
    else
    {
        puts ("Essa palavra não é um palíndromo.");
    }

    return 0;
}