/*
Crie uma variável do tipo char inicializada para o caractere 'A' e um ponteiro
que aponte para esta variável. Modifique a variável criada usando o ponteiro, de
forma que seu conteúdo agora seja 'B'. Por fim, mostre o conteúdo da variável e
o conteúdo apontado pelo ponteiro.
*/

#include<stdio.h>

int main(){

    char ch = 'A', *ptr = &ch;

    *ptr = 'B';

    printf("%c, %c.\n", ch, *ptr);

    return 0;
}