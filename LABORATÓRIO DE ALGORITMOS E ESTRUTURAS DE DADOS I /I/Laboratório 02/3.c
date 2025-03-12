/*
Descubra o que acontece ao tentarmos acessar um ponteiro que contém um
endereço inválido. Para isso tente mostrar o conteúdo apontado por um ponteiro
recém-criado:
*/

#include<stdio.h>

int main(){

    int *Ponteiro;

    printf("%i, %p.\n", *Ponteiro, Ponteiro);

    return 0;
}