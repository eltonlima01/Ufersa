/*
Defina o registro balao como mostrado abaixo. Construa um programa para
alocar dinamicamente uma variável do tipo balao. Peça ao usuário para entrar
com valores para cada um dos membros e em seguida exiba o conteúdo do
registro.
*/

#include<stdio.h>
#include<stdlib.h>

struct balao{

    float diametro; // Diâmetro em metros
    char marca[20]; // Nome da marca
    int modelo; // Número do modelo

};

int main(){

    struct balao Led, *Zeppelin = (struct balao*)malloc(sizeof(struct balao));

    printf("[BALÃO] Digite:\n- O diâmetro do balão: ");
    scanf("%f", &Zeppelin->diametro); getchar();

    printf("- Marca do balão: ");
    scanf("%[^\n]", Zeppelin->marca);

    printf("- Modelo do balão: ");
    scanf("%i", &Zeppelin->modelo);

    printf("[BALÃO]\nDiâmetro: (%.2f)m\nMarca: %s\nModelo: (%i)\n", Zeppelin->diametro, Zeppelin->marca, Zeppelin->modelo);

    free(Zeppelin);

    return 0;
}