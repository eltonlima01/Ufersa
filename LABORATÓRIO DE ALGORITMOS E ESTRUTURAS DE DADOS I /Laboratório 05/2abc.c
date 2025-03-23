/*
Implemente os dois algoritmos de busca vistos em sala(Sequencial e Binária)
e em seguida compare seus tempos de busca nos seguintes cenários:
a) Array com 1000 elementos
b) Array com 100000
c) Array com 1000000
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int Tamanho = 1000; // 1000 para A, 100.000 para B, 1.000.000 para C

void AleatoriezarVetor(int Vetor[]);
void ExibirVetor(int Vetor[]);
void OrdenarVetor(int Vetor[]);

int BuscaSequencial(int Vetor[], int Chave);
int BuscaBinaria(int Vetor[], int Chave);

int main(){
    srand(time(NULL));

    clock_t Inicio, Fim;

    int Vetor[Tamanho];
    AleatoriezarVetor(Vetor);
    OrdenarVetor(Vetor);
    int Chave0 = Vetor[rand()%Tamanho], Chave1;

    printf("[Implementando algoritmos de busca (Sequencial e Binária) em um vetor de %i elementos.]\nElementos do vetor:\n\n", Tamanho);
    ExibirVetor(Vetor);

    printf("Chave: %i\n", Chave0);

    Inicio = clock();
    Chave1 = BuscaSequencial(Vetor, Chave0);
    Fim = clock();

    printf("Chave encontrada (Busca Sequencial): %i\nTempo de Execução: (%.8f)s\n\n", Chave1, ((double)(Fim - Inicio)/CLOCKS_PER_SEC));

    Inicio = clock();
    Chave1 = BuscaBinaria(Vetor, Chave0);
    Fim = clock();

    printf("Chave encontrada (Busca Binária): %i\nTempo de Execução: (%.8f)s\n\n", Chave1, ((double)(Fim - Inicio)/CLOCKS_PER_SEC));

    return 0;
}

void AleatoriezarVetor(int Vetor[]){

    for(int i=0; i<Tamanho; i++){
        Vetor[i] = rand()%1000;
    }

}

void ExibirVetor(int Vetor[]){

    int Z = Tamanho - 1;

    for(int i=0; i<Tamanho; i++){
        (i == Z) ? printf("%i.\n\n", Vetor[i]) : printf("%i, ", Vetor[i]);
    }

}

void OrdenarVetor(int Vetor[]){

    int Chave;

    for(int a=1, z; a<Tamanho; a++){

        Chave = Vetor[a];
        z = a - 1;

        while((z >= 0) && (Vetor[z] > Chave)){

            Vetor[z+1] = Vetor[z];
            z = z - 1;

        }
        
        Vetor[z+1] = Chave;

    }

}

int BuscaSequencial(int Vetor[], int Chave){

    for(int i=0; i<Tamanho; i++){

        if(Vetor[i] == Chave){
            return Vetor[i];
        }

    }

    return -1;

}

int BuscaBinaria(int Vetor[], int Chave){

    int Esquerda = 0, Direita = Tamanho - 1;

    while(Esquerda <= Direita){

        int Meio = Esquerda + (Direita - Esquerda) / 2;

        if(Vetor[Meio] == Chave){
            return Vetor[Meio];
        }

        if(Vetor[Meio] < Chave){
            Esquerda = Meio + 1;
        }else{
            Direita = Meio - 1;
        }

    }

    return -1;
}