/*
Declare um ponteiro para inteiro, aloque memória dinamicamente para ele e
armazene o número 100 nessa memória. Mostre o conteúdo apontado. Peça que
o usuário digite um novo número inteiro e armazene-o na memória previamente
alocada. Libere o espaço alocado dinamicamente ao final do programa.
*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    int *Ponteiro = (int*)malloc(sizeof(int));

    *Ponteiro = 100;

    printf("Conteúdo armazenado: %i\n", *Ponteiro);
    putchar('\n');

    printf("Digite novo valor para esse bloco de memória: ");
    scanf("%i", Ponteiro);
    putchar('\n');

    printf("Conteúdo armazenado: %i\n", *Ponteiro);

    free(Ponteiro);
    return 0;
}