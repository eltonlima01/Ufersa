/*
Crie um programa que peça ao usuário para digitar o número de alunos em
uma turma. O programa deve usar essa informação para criar um vetor dinâmico
que armazene as notas finais desses alunos. Peça ao usuário para entrar com a
nota de dois alunos e em seguida mostre essas notas usando cout.
*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    int num;

    printf("Digite o número de alunos (mínimo 2): ");
    scanf("%i", &num);

    while(num < 2){

        putchar('\n');
        printf("[ERRO]: Mínimo 2 alunos(as).\nTente novamente: ");
        scanf("%i", &num);

    }

    putchar('\n');

    float *notas = (float*)malloc(num*sizeof(float));

    printf("Digite as notas dos (%i) alunos(as):\n", num);

    for(int i=0; i<num; i++){

        printf("(%i/%i): ", (i+1), num);
        scanf("%f", &notas[i]);

    }

    printf("As notas digitadas foram ");

    for(int i=0; i<num; i++){
        (i == (num-1)) ? printf("(%.2f).\n", notas[i]) : printf("(%.2f), ", notas[i]);
    }

    free(notas);

    return 0;
}