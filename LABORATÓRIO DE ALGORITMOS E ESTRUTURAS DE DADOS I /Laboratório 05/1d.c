/*
Implemente os algoritmos de ordenação vistos na disciplina(bubble,
insertion, merge, quick) e compare seus tempos de execução nos seguintes
cenários:
d) Array de Caracteres
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int Tamanho = 1000; // 1000 para A, 100.000 para B, 1.000.000 para C

void BubbleSort(char Vetor[]);
void InsertionSort(char Vetor[]);
void MergeSort(char Vetor[], int Esquerda, int Direita);
void QuickSort(char Vetor[], int Esquerda, int Direita);

void AleatoriezarVetor(char Vetor[]);
void ExibirVetor(char Vetor[]);

int main(){
    srand(time(NULL));

    clock_t Inicio, Fim;

    char Vetor[Tamanho];

    AleatoriezarVetor(Vetor);

    printf("[Implementando algoritmos de ordenação em um vetor de %i elementos.]\n\n[BUBBLE SORT] Antes:\n\n", Tamanho);
    ExibirVetor(Vetor);

    Inicio = clock();
    BubbleSort(Vetor);
    Fim = clock();

    printf("Depois:\n\n");
    ExibirVetor(Vetor);

    printf("Tempo de execução: (%.4f)s\n\n", ((double)(Fim - Inicio)/CLOCKS_PER_SEC));

    AleatoriezarVetor(Vetor);

    printf("[INSERTION SORT] Antes:\n\n");
    ExibirVetor(Vetor);

    
    Inicio = clock();
    InsertionSort(Vetor);
    Fim = clock();
        
    printf("Depois:\n\n");
    ExibirVetor(Vetor);

    printf("Tempo de execução: (%.4f)s\n\n", ((double)(Fim - Inicio)/CLOCKS_PER_SEC));

    AleatoriezarVetor(Vetor);

    printf("[MERGE SORT] Antes:\n\n");
    ExibirVetor(Vetor);

    Inicio = clock();
    MergeSort(Vetor, 0, (Tamanho-1));
    Fim = clock();

    printf("Depois:\n\n");
    ExibirVetor(Vetor);

    printf("Tempo de execução: (%.4f)s\n\n", ((double)(Fim - Inicio)/CLOCKS_PER_SEC));

    AleatoriezarVetor(Vetor);

    printf("[Quick Sort] Antes:\n\n");
    ExibirVetor(Vetor);

    Inicio = clock();
    QuickSort(Vetor, 0, (Tamanho-1));
    Fim = clock();

    printf("Depois:\n\n");
    ExibirVetor(Vetor);

    printf("Tempo de execução: (%.4f)s\n\n", ((double)(Fim - Inicio)/CLOCKS_PER_SEC));

    return 0;
}

void AleatoriezarVetor(char Vetor[]){

    for(int i=0; i<Tamanho; i++){
        Vetor[i] = 'A' + (rand()%26);
    }

}

void ExibirVetor(char Vetor[]){

    for(int i=0; i<Tamanho; i++){
        (i == (Tamanho-1)) ? printf("%c.\n\n", Vetor[i]) : printf("%c, ", Vetor[i]);
    }

}

void BubbleSort(char Vetor[]){

    for(int a=0; a<(Tamanho-1); a++){
        for(int z=0; z<(Tamanho-1); z++){

            if(Vetor[z] > Vetor[z+1]){

                int Tmprr = Vetor[z+1];
                Vetor[z+1] = Vetor[z];
                Vetor[z] = Tmprr;

            }

        }

    }

}

void InsertionSort(char Vetor[]){

    char Chave;

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

void Merge(char Vetor[], int Esquerda, int Meio, int Direita){

    int i, j, k,
    n1 = Meio - Esquerda + 1, n2 = Direita - Meio;
    char *Esq = (char*)malloc(n1 * sizeof(char)), *Dir = (char*)malloc(n2 * sizeof(char));

    for(i=0; i<n1; i++){
        Esq[i] = Vetor[Esquerda+i];
    }

    for(j=0; j<n2; j++){
        Dir[j] = Vetor[Meio+1+j];
    }

    i = 0; j = 0; k = Esquerda;

    while((i < n1) && (j < n2)){

        if(Esq[i] <= Dir[j]){

            Vetor[k] = Esq[i];
            i++;

        }else{

            Vetor[k] = Dir[j];
            j++;

        }

        k++;

    }

    while(i < n1){

        Vetor[k] = Esq[i];

        i++; k++;

    }

    while(j < n2){

        Vetor[k] = Dir[j];

        j++; k++;

    }

    free(Esq);
    free(Dir);

}

void MergeSort(char Vetor[], int Esquerda, int Direita){

    if(Esquerda < Direita){

        int Meio = Esquerda + (Direita - Esquerda) / 2;

        MergeSort(Vetor, Esquerda, Meio);
        MergeSort(Vetor, (Meio+1), Direita);
        Merge(Vetor, Esquerda, Meio, Direita);

    }

}

int Quick(char Vetor[], int Esquerda, int Direita){

    int Pivo = Vetor[Direita], i = (Esquerda - 1);

    for(int j = Esquerda; j < Direita; j++){

        if(Vetor[j] < Pivo){

            i++;

            char Tmprr = Vetor[i];
            Vetor[i] = Vetor[j];
            Vetor[j] = Tmprr;

        }

    }

    char Tmprr = Vetor[i + 1];
    Vetor[i + 1] = Vetor[Direita];
    Vetor[Direita] = Tmprr;

    return (i + 1);
}

void QuickSort(char Vetor[], int Esquerda, int Direita){

    if(Esquerda < Direita){

        int Pivo = Quick(Vetor, Esquerda, Direita);
        QuickSort(Vetor, Esquerda, (Pivo - 1));
        QuickSort(Vetor, (Pivo + 1), Direita);

    }

}