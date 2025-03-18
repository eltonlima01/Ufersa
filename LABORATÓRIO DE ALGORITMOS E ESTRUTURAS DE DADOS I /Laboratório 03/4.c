/*
Repita o exercício anterior criando um vetor dinâmico de carros. Ao invés de
inicializar o vetor com valores predefinidos, peça ao usuário para digitar os
dados de dois carros. Use uma função para receber o vetor de carros e exibir o
valor total dos carros.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{

    char modelo[20];
    int ano;
    float preco;

}carro;

void f(carro Carros[]);

int main(){

    carro *Carros = (carro*)malloc(2 * sizeof(carro));

    printf("Entre com os dados de 2 carros:\n(1/2): ");
    scanf("%s%i%f", Carros[0].modelo, &Carros[0].ano, &Carros[0].preco);

    printf("(2/2): ");
    scanf("%s%i%f", Carros[1].modelo, &Carros[1].ano, &Carros[1].preco);

    f(Carros);

    free(Carros);
    return 0;
}

void f(carro Carros[]){
    printf("O valor total é R$%.2f\n", (Carros[0].preco + Carros[1].preco));
}