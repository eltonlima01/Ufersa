#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTATOS 100
#define TAM_NOME 50
#define TAM_TELEFONE 15

//Struct para contato.
typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
} Contato;

Contato agenda[MAX_CONTATOS];
int totalContatos = 0;

//Função void que adiciona um contato.
void adicionarContato() {
    if (totalContatos >= MAX_CONTATOS) {
        printf("Agenda cheia! Não é possível adicionar mais contatos.\n");
        return;
    }
    
    Contato novo;
    
    printf("\n--- Novo Contato ---\n");
    printf("Nome: ");
    scanf(" %[^\n]", novo.nome);
    printf("Telefone: ");
    scanf(" %[^\n]", novo.telefone);
    
    agenda[totalContatos] = novo;
    totalContatos++;
    
    printf("Contato adicionado com sucesso!\n");
}

//Função void que realiza busca por nome.
void buscarPorNome() {
    if (totalContatos == 0) {
        printf("Agenda vazia! Nenhum contato cadastrado.\n");
        return;
    }
    
    char nomeBusca[TAM_NOME];
    printf("\nDigite o nome (ou parte) para buscar: ");
    scanf(" %[^\n]", nomeBusca);
    
    int encontrados = 0;
    
    for (int i = 0; i < totalContatos; i++) {
        if (strstr(agenda[i].nome, nomeBusca) != NULL) {
            printf("\nContato encontrado:\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            encontrados++;
        }
    }
    
    if (encontrados == 0) {
        printf("Nenhum contato encontrado com '%s' no nome.\n", nomeBusca);
    }
}

//Função void que exibe todos os contatos armazenados.
void exibirTodosContatos() {
    if (totalContatos == 0) {
        printf("Agenda vazia! Nenhum contato cadastrado.\n");
        return;
    }
    
    printf("\n--- Todos os Contatos (%d) ---\n", totalContatos);
    printf("%-5s %-30s %-15s\n", "ID", "Nome", "Telefone");
    
    for (int i = 0; i < totalContatos; i++) {
        printf("%-5d %-30s %-15s %-30s\n", 
               i+1, 
               agenda[i].nome, 
               agenda[i].telefone);
            }
}

//Função void menu que permite acessar as demais funções.
void menu() {
    int opcao;
    
    do {
        printf("\n--- Agenda de Contatos ---\n");
        printf("1. Adicionar contato\n");
        printf("2. Buscar contato por nome\n");
        printf("3. Exibir todos os contatos\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                adicionarContato();
                break;
            case 2:
                buscarPorNome();
                break;
            case 3:
                exibirTodosContatos();
                break;
            case 0:
                printf("Saindo da agenda...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}