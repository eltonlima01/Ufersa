// Escreva uma função para criptografar uma mensagem usando a Cifra de César (deslocamento de letras).

#include <stdio.h>

int main ()
{
    char string [100];
    int stringLenght;

    puts ("[CIFRA DE CÉSAR]\nDigite a mensagem a ser criptografada:");

    scanf ("%[^\n]", string);

    for (int i = 0; i < (sizeof (string) / sizeof (char)); i++)
    {
        if (string [i] == '\0')
        {
            stringLenght = i;
            break;
        }
    }

    for (int i = 0; i < stringLenght; i++)
    {
        if (!(string [i] == ' '))
        {
            string [i] += 3;
        }
    }

    printf ("Mensagem criptografada: %s\n", string);

    return 0;
}