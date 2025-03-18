/*
Inicie o programa perguntando ao usuário quantos inteiros ele deseja
armazenar em um vetor. Use a informação digitada para criar um vetor
dinâmico com o espaço necessário para armazenar a quantidade de inteiros
desejada. Depois disso, deixe que o próprio usuário preencha o vetor, utilizando
o tamanho do vetor como condição de parada de um laço for. Mostre o vetor
que foi preenchido através de outro laço e libere o espaço alocado
dinamicamente ao final do programa.
*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    int Tamanho_Vetor;

    printf("Quantos valores deseja guardar? ");
    scanf("%i", &Tamanho_Vetor);

    putchar('\n');

    while(Tamanho_Vetor < 1){

        printf("[ERRO] Pelo menos um(01) valor deve ser guardado.\nQuantos valores deseja guardar? ");
        scanf("%i", &Tamanho_Vetor);

    }

    int *Vetor = (int*)malloc(Tamanho_Vetor * sizeof(int));

    if(Tamanho_Vetor == 1){

        printf("Qual o valor? ");
        scanf("%i", Vetor);

        printf("O valor %i foi armazenado.\n", *Vetor);

        free(Vetor);
        return 0;

    }else{

        puts("Quais os valores?");

        for(int i=0; i<Tamanho_Vetor; i++){

            printf("(%i/%i): ", (i+1), Tamanho_Vetor);
            scanf("%i", &Vetor[i]);

        }

    }

    putchar('\n');

    int a = Tamanho_Vetor - 1, z = a - 1;

    printf("Os valores ");

    for(int i=0; i<Tamanho_Vetor; i++){

        if(i == z){
            printf("%i e", Vetor[i]);
        }else if(i == a){
            printf(" %i foram armazenados.\n", Vetor[i]);
        }else{
            printf("%i, ", Vetor[i]);
        }

    }

    free(Vetor);
    return 0;
}