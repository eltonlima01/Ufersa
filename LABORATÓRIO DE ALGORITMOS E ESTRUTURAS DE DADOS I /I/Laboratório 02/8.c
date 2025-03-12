/*
8º Declare um registro "Tigela" com os campos estado (cheia ou vazia) e tipo de
alimento (sopa ou canja). Crie uma função "Fome" que recebe um ponteiro para
uma Tigela e altera o seu estado para "vazia". Na função principal crie uma
tigela cheia, crie um ponteiro que aponta para essa tigela e então mostre como a
tigela estava antes da janta. Depois chame a função Fome com o ponteiro que
aponta para a tigela e ao fim mostre a tigela depois da janta.
*/

#include<stdio.h>
#include<string.h>

typedef struct{

    char Estado[50]; // Cheia/Vazia;
    char Alimento[50]; // Sopa/Canja;

} Tigela;

void Fome (Tigela *tig);

int main(){

    Tigela tig0 = {"Cheia", "Sopa"}, *tig1 = &tig0;

    printf("[TIGELA]\nAlimento: %s\nEstado: %s\n", tig0.Alimento, tig0.Estado);

    Fome(tig1);

    printf("[TIGELA]\nAlimento: %s\nEstado: %s\n", tig0.Alimento, tig0.Estado);    

    return 0;
}

void Fome (Tigela *tig){

    strcpy(tig->Estado, "Vazia");

}