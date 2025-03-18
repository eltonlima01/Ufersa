/*
Crie um registro "Local" com os campos nome, país e continente. Pergunte
ao usuário quantos locais ele quer visitar nas próximas férias e crie um vetor de
locais alocando dinamicamente o espaço de acordo com quantos locais ele quer
visitar. Use um laço for para armazenar as informações dos locais que o usuário
deseja visitar, e depois do armazenamento mostre os locais que ele escolheu.
Libere o espaço alocado dinamicamente ao final do programa.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{

    char Nome[25], Pais[25], Continente[25];

}Local;

int main(){

    int Quantidade_Locais;

    printf("Quantos locais você deseja visitar nas próximas férias? ");
    scanf("%i", &Quantidade_Locais); getchar();
    putchar('\n');

    Local *locais = (Local*)malloc(Quantidade_Locais * sizeof(Local));

    for(int i=0; i<Quantidade_Locais; i++){

        printf("[%iº LOCAL]\nNome do local: ", (i+1));
        scanf("%[^\n]", locais[i].Nome); getchar();

        printf("País do local: ");
        scanf("%[^\n]", locais[i].Pais); getchar();

        printf("Continente do local: ");
        scanf("%[^\n]", locais[i].Continente); getchar();
        putchar('\n');

    }

    for(int i=0; i<Quantidade_Locais; i++){

        printf("%iº local: %s / %s / %s\n", (i+1), locais[i].Nome, locais[i].Pais, locais[i].Continente);

    }

    free(locais);
    return 0;
}