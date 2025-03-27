/*
Baseado na 1º questão, adapte o código para transformá-lo em uma Lista
Circular.
*/

#include<stdio.h>
#include<stdlib.h>

#define MENU printf("1 - Inserir na lista (início)\n2 - Inserir na lista (fim)\n3 - Exibir lista\n4 - Buscar na lista\n5 - Remover da lista\n0 - Sair\n[Opção]: ")

typedef struct No{

    int Valor;
    struct No *Prox, *Ant;

}No;

typedef struct{
    No *Cabeca;
}ListaCircular;

void InserirInicio(ListaCircular *Lista, int Valor);
void InserirFim(ListaCircular *Lista, int Valor);
void Exibir(ListaCircular *Lista);
int Buscar(ListaCircular *Lista, int Valor);
void Remover(ListaCircular *Lista, int Valor);
void Liberar(ListaCircular *Lista);

int main(){

    ListaCircular *Lista = (ListaCircular*)malloc(sizeof(ListaCircular));
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

            puts("Pressione ENTER para continuar..."); getchar();
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

void InserirInicio(ListaCircular *Lista, int Valor){

    No *Novo = (No*)malloc(sizeof(No));

    Novo->Valor = Valor;

    if(Lista->Cabeca == NULL){

        Novo->Prox = Novo;
        Novo->Ant = Novo;
        Lista->Cabeca = Novo;

    }else{

        No *Ultimo = Lista->Cabeca->Ant;
        Novo->Prox = Lista->Cabeca;
        Novo->Ant = Ultimo;
        Ultimo->Prox = Novo;
        Lista->Cabeca->Ant = Novo;
        Lista->Cabeca = Novo;

    }
}

void InserirFim(ListaCircular *Lista, int Valor){

    No *Novo = (No*)malloc(sizeof(No));

    Novo->Valor = Valor;

    if(Lista->Cabeca == NULL){

        Novo->Prox = Novo;
        Novo->Ant = Novo;
        Lista->Cabeca = Novo;
        
    }else{

        No *Ultimo = Lista->Cabeca->Ant;
        Novo->Prox = Lista->Cabeca;
        Novo->Ant = Ultimo;
        Ultimo->Prox = Novo;
        Lista->Cabeca->Ant = Novo;

    }
}

void Remover(ListaCircular *Lista, int Valor){

    if(Lista->Cabeca == NULL){

        puts("Lista vazia!");
        return;

    }

    No *Atual = Lista->Cabeca;

    do{

        if(Atual->Valor == Valor){

            if(Atual->Prox == Atual){

                free(Atual);
                Lista->Cabeca = NULL;
                puts("Valor removido!");
                return;

            }else{

                if(Atual == Lista->Cabeca){

                    Lista->Cabeca = Atual->Prox;

                }

                Atual->Prox->Ant = Atual->Ant;
                Atual->Ant->Prox = Atual->Prox;
                free(Atual);
                puts("Valor removido!");

                return;
            }
        }

        Atual = Atual->Prox;

    }while(Atual != Lista->Cabeca);

    puts("Valor não encontrado!");

}

int Buscar(ListaCircular *Lista, int Valor){

    if(Lista->Cabeca == NULL){
        return 0;
    }

    No *Atual = Lista->Cabeca;

    do{

        if(Atual->Valor == Valor){
            return 1;
        }

        Atual = Atual->Prox;

    }while(Atual != Lista->Cabeca);

    return 0;
}

void Exibir(ListaCircular *Lista){

    if(Lista->Cabeca == NULL){

        puts("Lista Vazia!");
        return;

    }

    No *Atual = Lista->Cabeca;

    do{

        printf("- %i\n", Atual->Valor);
        Atual = Atual->Prox;

    }while(Atual != Lista->Cabeca);

}

void Liberar(ListaCircular *Lista){

    if(Lista->Cabeca == NULL){

        return;

    }

    No *Atual = Lista->Cabeca, *Proximo;

    do{

        Proximo = Atual->Prox;
        free(Atual);
        Atual = Proximo;

    }while(Atual != Lista->Cabeca);

    Lista->Cabeca = NULL;

}