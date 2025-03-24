/*
Implemente os dois algoritmos de busca vistos em sala(Sequencial e Binária)
e em seguida compare seus tempos de busca nos seguintes cenários:
d) Buscando uma palavra em um texto
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int BuscaSequencial(char Texto[][15], char Palavra[]);
int BuscaBinaria(char Texto[][15], char Palavra[]);

int ComparaStrings(const void *a, const void *b){
    return strcmp((const char*)a, (const char*)b);
}

int main(){
    srand(time(NULL));

    clock_t Inicio, Fim;

    char Texto[77][15] = {"I", "dreamt", "for", "so", "long", // 5.
    "My", "flesh", "was", "dull", "gold", "and", "my", "blood", "rotted", // 9.
    "Corpse", "after", "corpse", "left", "in", "my", "wake", // 7.
    "As", "I", "awaited", "his", "return", // 5
    "Heed", "my", "words", // 3
    "I", "am", "Malenia", "Blade", "of", "Miquella", "And", "I", "have", "never", "known", "defeat", // 12
    "Wait", // 1
    "The", "scarlet", "bloom", "flowers", "once", "more", // 6
    "You", "will", "witness", "true", "horror", // 5
    "Now", "rot", // 2
    "Your", "strength", "extraordinary", // 3
    "The", "mark", "of", "a", "true", "Lord", // 6
    "Dear", "Miquella", "dearest", "Miquella", "my", "brother", "I'm", "sorry", "I", "finally", "met", "my", "match"}; // 13

    int Indice0 = rand()%77;

    char Palavra[15];
    
    strcpy(Palavra, Texto[Indice0]);

    printf("[Implementando algoritmos de busca (Sequencial e Binária) em um texto.]\nTexto:\n\n");
    printf("%s %s %s %s %s.\n%s %s %s %s %s... %s %s %s, %s.\n%s %s %s, %s %s %s %s.\n%s %s %s... %s %s.\n%s %s %s.\n%s %s %s.\n%s %s %s.\n%s %s %s %s %s %s.\n...\n%s.\n%s %s %s %s %s %s.\n%s %s %s %s %s. %s, %s!\n...\n%s %s... %s... %s %s %s %s %s %s.\n%s %s, %s %s, %s %s... %s %s, %s %s, %s %s %s.\n\n",
    Texto[0], Texto[1], Texto[2], Texto[3], Texto[4],
    Texto[5], Texto[6], Texto[7], Texto[8], Texto[9], Texto[10], Texto[11], Texto[12], Texto[13],
    Texto[14], Texto[15], Texto[16], Texto[17], Texto[18], Texto[19], Texto[20],
    Texto[21], Texto[22], Texto[23], Texto[24], Texto[25],
    Texto[26], Texto[27], Texto[28], Texto[29],
    Texto[30], Texto[31], Texto[32], Texto[33], Texto[34], Texto[35], Texto[36], Texto[37], Texto[38], Texto[39], Texto[40], Texto[41],
    Texto[42], Texto[43], Texto[44], Texto[45], Texto[46], Texto[47], Texto[48],
    Texto[49],
    Texto[50], Texto[51], Texto[52], Texto[53], Texto[54], Texto[55],
    Texto[56], Texto[57], Texto[58], Texto[59], Texto[60],
    Texto[61], Texto[62],
    Texto[63], Texto[64], Texto[65],
    Texto[66], Texto[67], Texto[68], Texto[69], Texto[70], Texto[71],
    Texto[72], Texto[73], Texto[74], Texto[75], Texto[76]);

    printf("Item buscado: %s\n", Palavra);

    Inicio = clock();
    int Indice1 = BuscaSequencial(Texto, Palavra);
    Fim = clock();

    char Chave[15]; strcpy(Chave, Texto[Indice1]);

    printf("Item encontrado (Busca Sequencial): %s\nTempo de execução: (%.8f)s\n\n", Chave, ((double)(Fim - Inicio)/CLOCKS_PER_SEC));

    qsort(Texto, 77, sizeof(Texto[0]), ComparaStrings);

    Inicio = clock();
    Indice1 = BuscaBinaria(Texto, Palavra);
    Fim = clock();

    strcpy(Chave, Texto[Indice1]);

    printf("Item encontrado (Busca Binária): %s\nTempo de execução: (%.8f)s\n\n", Chave, ((double)(Fim - Inicio)/CLOCKS_PER_SEC));

    return 0;
}

int BuscaSequencial(char Texto[][15], char Palavra[]){

    for(int i=0; i<77; i++){

        if(strcmp(Palavra, Texto[i]) == 0){
            return i;
        }

    }

    return -1;

}

int BuscaBinaria(char Texto[][15], char Palavra[]) {
    int inicio = 0, fim = 76;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        int comparacao = strcmp(Palavra, Texto[meio]);

        if (comparacao == 0) {
            return meio;
        } else if (comparacao < 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return -1;
}