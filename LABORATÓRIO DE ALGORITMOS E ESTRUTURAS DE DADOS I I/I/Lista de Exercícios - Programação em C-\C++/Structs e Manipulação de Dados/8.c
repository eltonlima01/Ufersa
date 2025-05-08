#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUTOS 100
#define TAM_NOME 50

//Struct para cadastro do produto.
typedef struct {
    char nome[TAM_NOME];
    int codigo;
    int quantidade;
    float preco;
} Produto;

Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

//Função void para cadastro dos produtos.
void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }
    
    Produto p;
    
    printf("\n--- Cadastro de Produto ---\n");
    printf("Nome: ");
    scanf(" %[^\n]", p.nome);
    printf("Codigo: ");
    scanf("%d", &p.codigo);
    printf("Quantidade: ");
    scanf("%d", &p.quantidade);
    printf("Preco: ");
    scanf("%f", &p.preco);
    
    produtos[totalProdutos] = p;
    totalProdutos++;
    
    printf("Produto cadastrado com sucesso!\n");
}

//Função void para listar os produtos cadastrados.
void listarProdutos() {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    
    printf("\n--- Lista de Produtos ---\n");
    printf("%-5s %-20s %-10s %-10s %-10s\n", "ID", "Nome", "Codigo", "Quant.", "Preco");
    
    for (int i = 0; i < totalProdutos; i++) {
        printf("%-5d %-20s %-10d %-10d R$%-10.2f\n", 
               i+1, 
               produtos[i].nome, 
               produtos[i].codigo, 
               produtos[i].quantidade, 
               produtos[i].preco);
    }
}

//Função void para buscar produtos.
void buscarProduto() {
    int opcao;
    printf("\n--- Buscar Produto ---\n");
    printf("1. Por codigo\n");
    printf("2. Por nome\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    
    if (opcao == 1) {
        int codigo;
        printf("Digite o codigo: ");
        scanf("%d", &codigo);
        
        for (int i = 0; i < totalProdutos; i++) {
            if (produtos[i].codigo == codigo) {
                printf("\nProduto encontrado:\n");
                printf("Nome: %s\n", produtos[i].nome);
                printf("Codigo: %d\n", produtos[i].codigo);
                printf("Quantidade: %d\n", produtos[i].quantidade);
                printf("Preco: R$%.2f\n", produtos[i].preco);
                return;
            }
        }
        printf("Produto nao encontrado.\n");
    } else if (opcao == 2) {
        char nome[TAM_NOME];
        printf("Digite o nome: ");
        scanf(" %[^\n]", nome);
        
        int encontrados = 0;
        for (int i = 0; i < totalProdutos; i++) {
            if (strstr(produtos[i].nome, nome) != NULL) {
                printf("\nProduto encontrado:\n");
                printf("Nome: %s\n", produtos[i].nome);
                printf("Codigo: %d\n", produtos[i].codigo);
                printf("Quantidade: %d\n", produtos[i].quantidade);
                printf("Preco: R$%.2f\n", produtos[i].preco);
                encontrados++;
            }
        }
        if (encontrados == 0) {
            printf("Nenhum produto encontrado com esse nome.\n");
        }
    } else {
        printf("Opcao invalida.\n");
    }
}

//Função void menu, que permite acessar as outras funções.
void menu() {
    int opcao;
    
    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Cadastrar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Buscar produto\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                buscarProduto();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}