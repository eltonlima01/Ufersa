#include <stdio.h>

//Função que inverte o numero.
int inverterNumero(int numero) {
    int invertido = 0;
    
    while (numero != 0) {
        int digito = numero % 10;      // Pega o último dígito
        invertido = invertido * 10 + digito;  // Adiciona ao número invertido
        numero = numero / 10;         // Remove o último dígito
    }
    
    return invertido;
}

int main() {
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    printf("Numero original: %d\n", num);
    printf("Numero invertido: %d\n", inverterNumero(num));
    
    return 0;
}