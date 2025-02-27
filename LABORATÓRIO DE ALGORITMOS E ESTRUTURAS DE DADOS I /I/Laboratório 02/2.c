#include<stdio.h>

typedef struct{

	char Tipo[50];
	float Peso;
	unsigned int Comprimento;

}Peixe;

int main(){

	Peixe Nemo = {"Peixe-palhaço", 100, 12};

	Peixe *Ponteiro = &Nemo;

	printf("[PEIXE]\nTipo: %s;\nPeso: %.2f(g);\nComprimento: %i(cm).\n",
	Nemo.Tipo, Nemo.Peso, Nemo.Comprimento);

	putchar('\n');

	printf("[PEIXE]\nTipo: %s;\nPeso: %.2f(g);\nComprimento: %i(cm).\n",
	Ponteiro->Tipo, Ponteiro->Peso, Ponteiro->Comprimento);

	return 0;
}