#include <stdio.h>
#include <stdlib.h>

//Definição da Struct aluno.
struct Aluno{
    char nome[50];
    int matricula;
    float media;
};


int main(){
    int n;

    //Informa a quantidade de alunos que deseja cadastrar.
    printf("Deseja cadastrar quantos alunos? \n");
    scanf("%d", &n);

    // Aloca memória para o array de alunos
    struct Aluno *alunos = (struct Aluno*)malloc(n * sizeof(struct Aluno));
    
    if (alunos == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }
    
    for(int i = 0; i <= n; i++){
        printf("\nAluno %d:\n", i+1);

        printf("Nome: ");
        scanf(" %[^\n]", &alunos[i].nome); // Lê até encontrar uma quebra de linha

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Media: ");
        scanf("%f", &alunos[i].media);
    }

    printf("\nAlunos aprovados (media >= 6.0): \n");
    printf("---------------------------------)");

    int aprovados = 0;
    for(int i = 0; i <= n; i++){
        if(alunos[i].media >= 6.0){
            printf("Aluno: %c\n", alunos[i].nome);
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Media: %.2f\n", alunos[i].media);
            printf("-----------------------------------\n");
            aprovados++;
        }
    }
    if(aprovados == 0){
        printf("Nenhum aluno aprovado!\n");
    } else {
        printf("Quantidade de alunos aprovados: %d\n", aprovados);
    }
    free (alunos);

    return 0;
}