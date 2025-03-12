/*
Construa duas funções que realizem o incremento de um número em uma
unidade. A função Mais deve receber um número inteiro através de um
ponteiro. A função Incrementa deve receber um valor inteiro, sem usar
ponteiros, e retornar o valor incrementado em uma unidade. Utilize as duas
funções como no exemplo abaixo:
*/

#include<stdio.h>

void Mais(int *p);
int Incrementa(int i);

int main(){

    int num, *ptr = &num;

    printf("Digite um valor: ");

    scanf("%i", &num);

    Mais(ptr);

    printf("Resultado após Mais: %i\n", num);

    Incrementa(num);

    printf("Resultado após Incrementa: %i\n", Incrementa(num));

    return 0;
}

void Mais(int *p){

    *p=*p+1;

}

int Incrementa(int i){

    return i+1;
}