/*
Defina um registro ASCII que armazena um caractere e um valor inteiro
associado. Crie uma função que recebe um valor inteiro e um caractere, e
retorna o endereço de um elemento do tipo ASCII, alocado dinamicamente na
memória. O programa principal deve chamar a função passando valores lidos do
usuário, receber o retorno em um ponteiro, exibir os valores de retorno e deletar
a memória que foi alocada dentro da função.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{

    char Caractere;
    int Numero;

}ASCII;

ASCII* f(char c, int i);

int main(){

    char Caractere;
    int Numero;

    printf("[ASCII]\nDigite um caractere: ");
    scanf("%c", &Caractere); getchar();

    printf("Digite um número: ");
    scanf("%i", &Numero); getchar();
    putchar('\n');

    ASCII* ascii = f(Caractere, Numero);

    printf("Caractere: %c\nNúmero: %i\n", ascii->Caractere, ascii->Numero);

    free(ascii);
    return 0;
}

ASCII* f(char c, int i){

    ASCII *ascii = (ASCII*)malloc(sizeof(ASCII));

    ascii->Caractere = c;
    ascii->Numero = i;

    return ascii;
}