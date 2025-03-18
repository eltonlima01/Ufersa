/*
Crie um programa que peça ao usuário para digitar o número de alunos em
uma turma. O programa deve usar essa informação para criar um vetor dinâmico
que armazene as notas finais desses alunos. Peça ao usuário para entrar com a
nota de dois alunos e em seguida mostre essas notas usando cout.
*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    int numero_alunos;

    printf("Digite o número de alunos (mínimo 2): ");
    scanf("%i", &numero_alunos);
    putchar('\n');

    while(numero_alunos < 2){

        printf("[ERRO]: Mínimo 2 alunos(as).\nTente novamente: ");
        scanf("%i", &numero_alunos);

        if(numero_alunos == 2){
            putchar('\n');
        }

    }

    float *nota_final = (float*)malloc(numero_alunos*sizeof(float));

    printf("Digite as notas dos (%i) alunos(as):\n", numero_alunos);

    for(int z=0; z<numero_alunos; z=z+1){

        printf("(%i/%i): ", (z+1), numero_alunos);
        scanf("%f", &nota_final[z]);

    }

    putchar('\n');

    printf("As notas digitadas foram ");

    int a = numero_alunos - 1;

    for(int z=0; z<numero_alunos; z++){
        (z == (a)) ? printf("e (%.2f).\n", nota_final[z]) : printf("(%.2f), ", nota_final[z]);
    }

    free(nota_final);

    return 0;
}