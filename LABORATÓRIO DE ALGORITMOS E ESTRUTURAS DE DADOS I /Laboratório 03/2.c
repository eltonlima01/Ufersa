/*
Defina o registro balao como mostrado abaixo. Construa um programa para
alocar dinamicamente uma variável do tipo balao. Peça ao usuário para entrar
com valores para cada um dos membros e em seguida exiba o conteúdo do
registro.
*/

#include<stdio.h>
#include<stdlib.h>

struct balao{

    float diametro; // diâmetro em metros
    char marca[20]; // nome da marca
    int modelo; // número do modelo

};

int main(){

    struct balao *Led_Zeppelin = (struct balao*)malloc(sizeof(struct balao));

    printf("[BALÃO]\nDiâmetro do balão (em metros): ");
    scanf("%f", &Led_Zeppelin->diametro); getchar();
    putchar('\n');
    
    printf("Nome da marca do balão: ");
    scanf("%[^\n]", Led_Zeppelin->marca);
    putchar('\n');

    printf("Número do modelo do balão: ");
    scanf("%i", &Led_Zeppelin->modelo);
    putchar('\n');

    printf("[BALÃO]\nDiâmetro: (%.2f)m\nMarca: %s\nModelo: %i\n",
    Led_Zeppelin->diametro, Led_Zeppelin->marca, Led_Zeppelin->modelo);

    free(Led_Zeppelin);

    return 0;
}