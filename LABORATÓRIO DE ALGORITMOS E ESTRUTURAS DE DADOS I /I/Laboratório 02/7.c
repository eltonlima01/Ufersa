#include <stdio.h>
#include <stdint.h>

typedef union {
    struct {
        uint8_t R, G, B, A;
    };
    uint32_t Intensidade;
} Cor;

void readColor(Cor *c) {
    printf("Digite uma cor no formato\nRGBA: ");
    scanf("%hhu %hhu %hhu %hhu", &c->R, &c->G, &c->B, &c->A);
}

void readIColor(Cor *c) {
    printf("Int32: ");
    scanf("%u", &c->Intensidade);
}

void showColor(const Cor *c) {
    printf("Cor (RGBA): (%u, %u, %u, %u)\n", c->R, c->G, c->B, c->A);
    printf("Inteiro 32 bits: %u (0x%X)\n", c->Intensidade, c->Intensidade);
}

int main() {

    Cor cor;

    readColor(&cor);

    //printf("\nCor:\n");

    showColor(&cor);

    readIColor(&cor);

    //printf("\nCor:\n");

    showColor(&cor);

    return 0;
}
