#include <stdio.h>

typedef enum {
    JPG,
    PNG,
    BMP
} TipoImagem;

typedef struct {
    char nome[50];
    int altura, largura;
    TipoImagem tipo;
} Imagem;

void Detalhes(const Imagem *img) {

    const char *tipos[] = {"jpg", "png", "bmp"};
    
    printf("A imagem \"%s\" com tamanho %dx%d tem formato %s.\n", 
           img->nome, img->largura, img->altura, tipos[img->tipo]);
}

int main() {

    Imagem img = {"backg.png", 1080, 1920, PNG};
    
    Detalhes(&img);
    
    return 0;
}
