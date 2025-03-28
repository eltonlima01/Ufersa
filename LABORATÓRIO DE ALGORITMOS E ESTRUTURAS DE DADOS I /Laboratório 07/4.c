#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENU printf("[CATÁLOGO]\n1 - Adicionar novo título\n2 - Buscar títulos\n3 - Listar títulos\n0 - Sair\n[OPÇÃO]: ")

typedef struct Titulo {
    char Nome[50], Categoria[50];
    int Ano;
    struct Titulo *Prox;
} Titulo;

typedef struct {
    Titulo *Topo;
} Catalogo;

void InserirTitulo(Catalogo *catalogo, char Nome[], char Categoria[], int Ano);
void BuscarTitulo(Catalogo *catalogo, char Categoria[]);
void Exibir(Catalogo *Catalog);
void Liberar(Catalogo *Catalog);
void Pausa();
#define PAUSE Pausa()

int main() {
    Catalogo *Catalog = (Catalogo *)malloc(sizeof(Catalogo));
    Catalog->Topo = NULL;

    char Nome[50], Categoria[50];
    int Ano;
    short int Opcao;

    do {
        MENU;
        scanf("%hi", &Opcao);
        getchar();

        switch (Opcao) {
            case 1:
                puts("[Adicionar novo título]\n(1/3) Nome do título:");
                scanf("%[^\n]", Nome);
                getchar();

                puts("(2/3) Categoria:");
                scanf("%[^\n]", Categoria);
                getchar();

                puts("(3/3) Ano:");
                scanf("%i", &Ano);
                getchar();

                InserirTitulo(Catalog, Nome, Categoria, Ano);
                printf("Título '%s' (%i) adicionado com sucesso!\n", Nome, Ano);
                PAUSE;
                break;

            case 2:
                puts("[Buscar títulos]\nCategoria do título:");
                scanf("%[^\n]", Categoria);
                getchar();

                BuscarTitulo(Catalog, Categoria);
                break;

            case 3:
                puts("[Listar títulos ordenados por ano]\n");
                Exibir(Catalog);
                break;

            case 0:
                puts("Saindo...");
                break;

            default:
                puts("[ERRO] Opção inválida! Tente novamente.");
        }

    } while (Opcao != 0);

    Liberar(Catalog);
    free(Catalog);
    return 0;
}

void InserirTitulo(Catalogo *Catalog, char Nome[], char Categoria[], int Ano) {
    Titulo *Novo = (Titulo *)malloc(sizeof(Titulo));

    strcpy(Novo->Nome, Nome);
    strcpy(Novo->Categoria, Categoria);
    Novo->Ano = Ano;
    Novo->Prox = Catalog->Topo;
    Catalog->Topo = Novo;
}

void BuscarTitulo(Catalogo *Catalog, char Categoria[]) {
    Titulo *Atual = Catalog->Topo;
    int encontrado = 0;

    while (Atual != NULL) {
        if (strcmp(Atual->Categoria, Categoria) == 0) {
            printf("- %s (%i)\n", Atual->Nome, Atual->Ano);
            encontrado = 1;
        }
        Atual = Atual->Prox;
    }

    if (!encontrado) {
        puts("[ERRO] Nenhum título encontrado nessa categoria!");
    }
    PAUSE;
}

void Exibir(Catalogo *Catalog) {
    if (Catalog->Topo == NULL) {
        puts("Catálogo vazio!");
        return;
    }

    int Tmprr = 0;
    Titulo *Atual = Catalog->Topo;

    while (Atual != NULL) {
        Tmprr++;
        Atual = Atual->Prox;
    }

    Titulo **Matriz = (Titulo **)malloc(Tmprr * sizeof(Titulo *));
    Atual = Catalog->Topo;

    for (int i = 0; i < Tmprr; i++) {
        Matriz[i] = Atual;
        Atual = Atual->Prox;
    }

    for(int a=0; a<Tmprr-1; a++) {
        for (int z = 0; z < Tmprr - a - 1; z++) {
            if (Matriz[z]->Ano > Matriz[z + 1]->Ano) {
                Titulo *Temp = Matriz[z];
                Matriz[z] = Matriz[z + 1];
                Matriz[z + 1] = Temp;
            }
        }
    }

    for(int i=0; i<Tmprr; i++){
        printf("- %s (%i): %s\n", Matriz[i]->Nome, Matriz[i]->Ano, Matriz[i]->Categoria);
    }

    PAUSE;

    free(Matriz);
}

void Liberar(Catalogo *Catalog){

    Titulo *Atual = Catalog->Topo;

    while(Atual != NULL){

        Titulo *Prox = Atual->Prox;
        free(Atual);
        Atual = Prox;

    }

    Catalog->Topo = NULL;
}

void Pausa(){

    printf("Digite ENTER para continuar...");
    getchar();
}