/*
Implemente uma Lista Encadeada Simples, contendo os seguintes
métodos:
● inserir_no_inicio(valor): Adiciona um nó no início da lista.
● inserir_no_fim(valor): Adiciona um nó no final da lista.
● remover(valor): Remove um nó específico.
● buscar(valor): Retorna se o elemento está presente na lista.
● exibir(): Exibe todos os elementos da lista.
*/

#include<stdio.h>
#include<stdlib.h>

#define MENU puts("1 - Inserir na lista (início)\n2 - Inserir na lista (fim)\n3 - Exibir lista\n4 - Buscar na lista\n5 - Remover da lista\n0 - Sair")

typedef struct No{

    int Valor;
    struct No *Prox;

}No;

typedef struct{
    No *Cabeca;
}ListaEncadeada;

void InicializarLista(ListaEncadeada *Lista);
void InserirInicio(ListaEncadeada *Lista, int Valor);
void InserirFim(ListaEncadeada *Lista, int Valor);
void Exibir(ListaEncadeada *Lista);
int Buscar(ListaEncadeada *Lista, int Valor);
void Remover(ListaEncadeada *Lista, int Valor);

int main(){

    ListaEncadeada Lista;
    InicializarLista(&Lista);

    int Valor;
    short int Opcao;

    MENU; scanf("%hi", &Opcao); getchar();

    while(Opcao != 0){

        switch(Opcao){

            case 1: printf("[Inserir na lista (início)]\nValor: ");
            scanf("%i", &Valor); getchar();

            InserirInicio(&Lista, Valor);

            puts("Valor adicionado! Pressione ENTER para continuar..."); getchar();
            break;

            case 2: printf("[Inserir na lista (fim)]\nValor: ");
            scanf("%i", &Valor); getchar();

            InserirFim(&Lista, Valor);

            puts("Valor adicionado! Pressione ENTER para continuar..."); getchar();
            break;

            case 3: puts("[Exibir lista]");

            Exibir(&Lista);

            puts("Pressione ENTER para continuar..."); getchar();
            break;

            case 4: printf("[Buscar na lista]\nValor: ");
            scanf("%i", &Valor); getchar();
            
            (Buscar(&Lista, Valor) == 1) ? printf("Valor (%i) encontrado!\n", Valor) : printf("Valor (%i) não encontrado!\n", Valor);

            puts("Pressione ENTER para continuar..."); getchar();
            break;

            case 5: printf("[Remover da lista]\nValor: ");
            scanf("%i", &Valor); getchar();

            Remover(&Lista, Valor);

            puts("Valor removido! Pressione ENTER para continuar..."); getchar();
            break;

            case 0: puts("Saindo...");
            break;

            default: puts("[Erro] Opção inválida! Tente novamente.");
        }

        MENU;
        scanf("%hi", &Opcao); getchar();

    }

    return 0;
}

void InicializarLista(ListaEncadeada *Lista){
    Lista->Cabeca = NULL;
}

void InserirInicio(ListaEncadeada *Lista, int Valor){

    No *Novo = (No*)malloc(sizeof(No));

    Novo->Valor = Valor;
    Novo->Prox = Lista->Cabeca;
    Lista->Cabeca = Novo;

}

void InserirFim(ListaEncadeada *Lista, int Valor){

    No *Novo = (No*)malloc(sizeof(No));

    Novo->Valor = Valor;
    Novo->Prox = NULL;

    if(Lista->Cabeca == NULL){

        Lista->Cabeca = Novo;

    }else{

        No *Tmprr = Lista->Cabeca;

        while(Tmprr->Prox != NULL){
            Tmprr = Tmprr->Prox;
        }

        Tmprr->Prox = Novo;

    }

}

void Remover(ListaEncadeada *Lista, int Valor){

    No *Atual = Lista->Cabeca, *Anterior = NULL;

    while((Atual != NULL) && (Atual->Valor != Valor)){

        Anterior = Atual;
        Atual = Atual->Prox;

    }

    if(Atual == NULL){

        puts("Nó não encontrado!\n");
        return;

    }

    if(Anterior == NULL){

        Lista->Cabeca = Atual->Prox;

    }else{

        Anterior->Prox = Atual->Prox;

    }

    free(Atual);
}

int Buscar(ListaEncadeada *Lista, int Valor){

    No *Tmprr = Lista->Cabeca;

    while(Tmprr != NULL){

        if(Tmprr->Valor == Valor){
            return 1;
        }

        Tmprr = Tmprr->Prox;

    }

    return 0;
}

void Exibir(ListaEncadeada *Lista){

    No *Tmprr = Lista->Cabeca;

    if(Tmprr == NULL){
        puts("Lista vazia!");
    }

    while(Tmprr != NULL){

        printf("- %i;\n", Tmprr->Valor);
        Tmprr = Tmprr->Prox;

    }

}