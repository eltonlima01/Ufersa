/*
Construa uma função que receba um peixe e exiba o seu conteúdo.
a) Faça uma versão utilizando um parâmetro tipo peixe
b) Faça uma versão utilizando um parâmetro tipo ponteiro para peixe
*/

#include<stdio.h>

typedef struct{

	char Tipo[50];
	float Peso;
	unsigned int Comprimento;

}Peixe;

void f(Peixe P);
void f0(Peixe *P);

int main(){

	Peixe Nemo = {"Peixe-palhaço", 100, 12};

	Peixe *Ponteiro = &Nemo;

	f(Nemo);

	putchar('\n');

	f0(Ponteiro);

	return 0;
}

void f(Peixe P){

	printf("[PEIXE]\nTipo: %s;\nPeso: %.2f(g);\nComprimento: %i(cm).\n",
	P.Tipo, P.Peso, P.Comprimento);

}

void f0(Peixe *P){

	printf("[PEIXE]\nTipo: %s;\nPeso: %.2f(g);\nComprimento: %i(cm).\n",
	P->Tipo, P->Peso, P->Comprimento);

}