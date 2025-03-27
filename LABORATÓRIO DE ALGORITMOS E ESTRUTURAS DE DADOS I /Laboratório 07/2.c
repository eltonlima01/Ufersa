/*
Baseado na questão anterior, implemente uma lista duplamente
encadeada com as mesma funções da questão anterior.
*/

#include<stdio.h>
#include<stdlib.h>

#define MENU printf("1 - Inserir na lista (início)\n2 - Inserir na lista (fim)\n3 - Exibir lista\n4 - Buscar na lista\n5 - Remover da lista\n0 - Sair\n[Opção]: ")

typedef struct No{

    int Valor;
    struct No *Prox, *Ant;

}No;

typedef struct{
    No *Cabeca, *Pe;
}ListaDuplamenteEncadeada;

void InserirInicio(ListaDuplamenteEncadeada *Lista, int Valor);
void InserirFim(ListaDuplamenteEncadeada *Lista, int Valor);
void Exibir(ListaDuplamenteEncadeada *Lista);
int Buscar(ListaDuplamenteEncadeada *Lista, int Valor);
void Remover(ListaDuplamenteEncadeada *Lista, int Valor);
void Liberar(ListaDuplamenteEncadeada *Lista);

int main(){

    ListaDuplamenteEncadeada *Lista = (ListaDuplamenteEncadeada*)malloc(sizeof(ListaDuplamenteEncadeada));
    Lista->Cabeca = NULL;

    int Valor;
    short int Opcao;

    MENU;
    scanf("%hi", &Opcao); getchar();

    while(Opcao != 0){

        switch(Opcao){

            case 1: printf("[Inserir na lista (início)]\nValor: ");
            scanf("%i", &Valor); getchar();

            InserirInicio(Lista, Valor);

            puts("Valor adicionado! Pressione ENTER para continuar..."); getchar();
            break;

            case 2: printf("[Inserir na lista (fim)]\nValor: ");
            scanf("%i", &Valor); getchar();

            InserirFim(Lista, Valor);

            puts("Valor adicionado! Pressione ENTER para continuar..."); getchar();
            break;

            case 3: puts("[Exibir lista]");

            Exibir(Lista);

            puts("Pressione ENTER para continuar..."); getchar();
            break;

            case 4: printf("[Buscar na lista]\nValor: ");
            scanf("%i", &Valor); getchar();
            
            (Buscar(Lista, Valor) == 1) ? printf("Valor (%i) encontrado!\n", Valor) : printf("Valor (%i) não encontrado!\n", Valor);

            puts("Pressione ENTER para continuar..."); getchar();
            break;

            case 5: printf("[Remover da lista]\nValor: ");
            scanf("%i", &Valor); getchar();

            Remover(Lista, Valor);

            puts("Valor removido! Pressione ENTER para continuar..."); getchar();
            break;

            case 0: puts("Saindo...");
            break;

            default: puts("[Erro] Opção inválida! Tente novamente.\n");
        }

        MENU;
        scanf("%hi", &Opcao); getchar();

    }

    Liberar(Lista);
    free(Lista);
    return 0;
}

void InserirInicio(ListaDuplamenteEncadeada *Lista, int Valor){

    No *Novo = (No*)malloc(sizeof(No));

    Novo->Valor = Valor;
    Novo->Prox = Lista->Cabeca;
    Novo->Ant = NULL;

    if(Lista->Cabeca != NULL){

        Lista->Cabeca->Ant = Novo;

    }else{

        Lista->Pe = Novo;

    }

    Lista->Cabeca = Novo;

}

void InserirFim(ListaDuplamenteEncadeada *Lista, int Valor){

    No *Novo = (No*)malloc(sizeof(No));

    Novo->Valor = Valor;
    Novo->Prox = NULL;
    Novo->Ant = Lista->Pe;

    if(Lista->Pe != NULL){

        Lista->Pe->Prox = Novo;
        
    }else{

        Lista->Cabeca = Novo;

    }

    Lista->Pe = Novo;

}

void Remover(ListaDuplamenteEncadeada *Lista, int Valor){

    No *Atual = Lista->Cabeca;

    while((Atual != NULL) && (Atual->Valor != Valor)){
        Atual = Atual->Prox;
    }

    if(Atual == NULL){

        puts("Nó não encontrado!\n");
        return;

    }

    if(Atual->Ant != NULL){

        Atual->Ant->Prox = Atual->Prox;

    }else{

        Lista->Cabeca = Atual->Prox;

    }

    if(Atual->Prox != NULL){

        Atual->Prox->Ant = Atual->Ant;

    }else{

        Lista->Pe = Atual->Ant;

    }

    free(Atual);
}

int Buscar(ListaDuplamenteEncadeada *Lista, int Valor){

    No *Atual = Lista->Cabeca;

    while(Atual != NULL){

        if(Atual->Valor == Valor){
            return 1;
        }

        Atual = Atual->Prox;

    }

    return 0;
}

void Exibir(ListaDuplamenteEncadeada *Lista){

    No *Atual = Lista->Cabeca;

    if(Atual == NULL){
        puts("Lista vazia!");
    }

    while(Atual != NULL){

        printf("- %i;\n", Atual->Valor);
        Atual = Atual->Prox;

    }

}

void Liberar(ListaDuplamenteEncadeada *Lista){

    No *Atual = Lista->Cabeca;

    while(Atual != NULL){

        No *Proximo = Atual->Prox;
        free(Atual);
        Atual = Proximo;

    }

    Lista->Cabeca = NULL;
    Lista->Pe = NULL;

}