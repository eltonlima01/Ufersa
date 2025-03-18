/*
Construa um registro para guardar informações sobre um carro. Um carro
deve ter um modelo, ano de fabricação e preço. Em seguida construa um vetor
estático de 10 carros inicializando os dois primeiros carros respectivamente para
"Vectra", 2009, R$58.000,00 e "Polo", 2008, R$45.000,00. Use um ponteiro
para apontar para o segundo carro e exibir seus dados.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{

    char modelo[20];
    int ano;
    float preco;

}carro;

int main(){

    carro Carros[10] = {{"Vectra", 2009, 58000}, {"Polo", 2008, 45000}}, *Ponteiro = &Carros[1];

    printf("[CARRO]\nModelo: %s\nAno: %i\nPreço: R$%.2f\n", Ponteiro->modelo, Ponteiro->ano, Ponteiro->preco);

    return 0;
}