/*
Defina um registro que descreve um peixe. O registro deve incluir o tipo
(string), o peso (ponto-flutuante) e o comprimento (inteiro) do peixe. Em
seguida mostre:
a) Como criar uma variável de tipo peixe
b) Como criar um ponteiro para uma variável de tipo peixe.
*/

#include<stdio.h>

typedef struct{

    char Tipo[50];
    float Peso;
    int Comprimento;

}Peixe;

int main(){

    Peixe Zora, *Ruta = &Zora;

    return 0;
}