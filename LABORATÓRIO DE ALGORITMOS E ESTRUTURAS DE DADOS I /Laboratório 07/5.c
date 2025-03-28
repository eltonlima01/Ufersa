#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Musica {
    char titulo[50];
    char artista[50];
    float duracao;
    struct Musica *prox;
    struct Musica *ant;
} Musica;

typedef struct {
    Musica *atual;
} Playlist;

Playlist *criarPlaylist();
void adicionarMusica(Playlist *playlist, char titulo[], char artista[], float duracao);
void removerMusica(Playlist *playlist, char titulo[]);
void exibirPlaylist(Playlist *playlist);
void reorganizarMusica(Playlist *playlist, char titulo[], int novaPos);
void liberarPlaylist(Playlist *playlist);
void pausa();

#define PAUSE pausa()

int main() {
    Playlist *playlist = criarPlaylist();
    int opcao;
    char titulo[50], artista[50];
    float duracao;
    int novaPos;

    do {
        printf("\n[MENU]\n");
        printf("1 - Adicionar música\n");
        printf("2 - Remover música\n");
        printf("3 - Exibir playlist\n");
        printf("4 - Reorganizar playlist\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Título: ");
                scanf("%[^\n]", titulo);
                getchar();
                printf("Artista: ");
                scanf("%[^\n]", artista);
                getchar();
                printf("Duração (min): ");
                scanf("%f", &duracao);
                getchar();
                adicionarMusica(playlist, titulo, artista, duracao);
                printf("Música adicionada com sucesso!\n");
                PAUSE;
                break;
            case 2:
                printf("Título da música a remover: ");
                scanf("%[^\n]", titulo);
                getchar();
                removerMusica(playlist, titulo);
                PAUSE;
                break;
            case 3:
                exibirPlaylist(playlist);
                PAUSE;
                break;
            case 4:
                printf("Título da música a mover: ");
                scanf("%[^\n]", titulo);
                getchar();
                printf("Nova posição (1 = topo): ");
                scanf("%d", &novaPos);
                getchar();
                reorganizarMusica(playlist, titulo, novaPos);
                PAUSE;
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("[ERRO] Opção inválida!\n");
                PAUSE;
        }
    } while (opcao != 0);

    liberarPlaylist(playlist);
    return 0;
}

Playlist *criarPlaylist() {
    Playlist *playlist = (Playlist *)malloc(sizeof(Playlist));
    playlist->atual = NULL;
    return playlist;
}

void adicionarMusica(Playlist *playlist, char titulo[], char artista[], float duracao) {
    Musica *nova = (Musica *)malloc(sizeof(Musica));
    strcpy(nova->titulo, titulo);
    strcpy(nova->artista, artista);
    nova->duracao = duracao;

    if (playlist->atual == NULL) {
        nova->prox = nova;
        nova->ant = nova;
        playlist->atual = nova;
    } else {
        Musica *ultimo = playlist->atual->ant;
        ultimo->prox = nova;
        nova->ant = ultimo;
        nova->prox = playlist->atual;
        playlist->atual->ant = nova;
    }
}

void removerMusica(Playlist *playlist, char titulo[]) {
    if (playlist->atual == NULL) {
        printf("[ERRO] Playlist vazia!\n");
        return;
    }

    Musica *atual = playlist->atual;
    Musica *inicio = playlist->atual;
    do {
        if (strcmp(atual->titulo, titulo) == 0) {
            if (atual->prox == atual) {
                free(atual);
                playlist->atual = NULL;
            } else {
                atual->ant->prox = atual->prox;
                atual->prox->ant = atual->ant;
                if (playlist->atual == atual) {
                    playlist->atual = atual->prox;
                }
                free(atual);
            }
            printf("Música removida com sucesso!\n");
            return;
        }
        atual = atual->prox;
    } while (atual != inicio);

    printf("[ERRO] Música não encontrada!\n");
}

void exibirPlaylist(Playlist *playlist) {
    if (playlist->atual == NULL) {
        printf("Playlist vazia!\n");
        return;
    }

    Musica *atual = playlist->atual;
    Musica *inicio = playlist->atual;
    int i = 1;

    printf("\n[Playlist]\n");
    do {
        printf("%d. %s - %s (%.2f min)\n", i++, atual->titulo, atual->artista, atual->duracao);
        atual = atual->prox;
    } while (atual != inicio);
}

void reorganizarMusica(Playlist *playlist, char titulo[], int novaPos) {
    if (playlist->atual == NULL) {
        printf("[ERRO] Playlist vazia!\n");
        return;
    }

    Musica *atual = playlist->atual;
    Musica *inicio = playlist->atual;
    Musica *musicaRemovida = NULL;

    do {
        if (strcmp(atual->titulo, titulo) == 0) {
            musicaRemovida = atual;
            break;
        }
        atual = atual->prox;
    } while (atual != inicio);

    if (musicaRemovida == NULL) {
        printf("[ERRO] Música não encontrada!\n");
        return;
    }

    if (musicaRemovida->prox == musicaRemovida) {
        return;
    }

    musicaRemovida->ant->prox = musicaRemovida->prox;
    musicaRemovida->prox->ant = musicaRemovida->ant;
    if (playlist->atual == musicaRemovida) {
        playlist->atual = musicaRemovida->prox;
    }

    atual = playlist->atual;
    for (int i = 1; i < novaPos && atual->prox != playlist->atual; i++) {
        atual = atual->prox;
    }

    musicaRemovida->prox = atual;
    musicaRemovida->ant = atual->ant;
    atual->ant->prox = musicaRemovida;
    atual->ant = musicaRemovida;

    if (novaPos == 1) {
        playlist->atual = musicaRemovida;
    }

    printf("Música movida para posição %d!\n", novaPos);
}

void liberarPlaylist(Playlist *playlist) {
    if (playlist->atual == NULL) {
        free(playlist);
        return;
    }

    Musica *atual = playlist->atual;
    Musica *inicio = playlist->atual;

    do {
        Musica *prox = atual->prox;
        free(atual);
        atual = prox;
    } while (atual != inicio);

    free(playlist);
}

void pausa() {
    printf("Pressione ENTER para continuar...\n");
    getchar();
}
