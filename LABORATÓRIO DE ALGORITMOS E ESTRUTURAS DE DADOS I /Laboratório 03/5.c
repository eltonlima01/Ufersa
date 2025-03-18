/*
Construa um vetor dinâmico de alunos. O registro aluno deve ser composto
por nome (ou matrícula), código da disciplina (número inteiro sem sinal), e
situação da disciplina. A situação da disciplina deve ser uma enumeração com
os valores: Aprovado, Trancado, Reprovado. Peça ao usuário para digitar o
número de alunos do vetor e em seguida leia os dados do primeiro aluno. Para
finalizar mostre os dados do primeiro aluno usando uma função que recebe um
ponteiro para aluno.
*/

#include<stdio.h>
#include<stdlib.h>

typedef enum{

    Aprovado = 1, Trancado, Reprovado

}Situacao_Disciplina;

typedef struct{

    char Nome[25];
    unsigned int Codigo_Disciplina;
    Situacao_Disciplina Situacao;

}Alunos;

void f(Alunos *aluno);

int main(){

    int Numero_Alunos, SituacaoTMPRR;

    printf("Digite o número de alunos: ");
    scanf("%i", &Numero_Alunos); getchar();
    putchar('\n');

    Alunos *aluno = (Alunos*)malloc(Numero_Alunos * sizeof(Alunos));

    printf("[DADOS DO(A) (1)º(ª) ALUNO(A)]\nNome: ");
    scanf("%[^\n]", aluno->Nome); getchar();
    putchar('\n');

    printf("Código da disciplina: ");
    scanf("%u", &aluno->Codigo_Disciplina); getchar();
    putchar('\n');

    printf("Situação: ");
    scanf("%i", &SituacaoTMPRR); getchar();
    putchar('\n');

    while((SituacaoTMPRR < 1) || (SituacaoTMPRR > 3)){

        printf("[ERRO]: Estado de situação inválido!\nSituação: ");
        scanf("%i", &SituacaoTMPRR);

        if((SituacaoTMPRR >= 1) && (SituacaoTMPRR <= 3)){
            putchar('\n');
        }

    }

    aluno->Situacao = (Situacao_Disciplina)SituacaoTMPRR;

    f(aluno);

    free(aluno);
    return 0;
}

void f(Alunos *aluno){

    printf("[ALUNO (1)]\nNome: %s\nCódigo da disciplina: %u\nSituação: ",
    aluno->Nome, aluno->Codigo_Disciplina);

    switch(aluno->Situacao){

        case Aprovado: puts("Aprovado");
        break;

        case Trancado: puts("Trancado");
        break;

        case Reprovado: puts("Reprovado");
        break;

    }

}