#include <stdio.h>

int potencia(int base, int expoente) {
    int resultado = 1;
    
    // Calcula a potência usando multiplicações repetidas
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    
    return resultado;
}

int main() {
    int base, expoente;
    
    printf("Digite a base: ");
    scanf("%d", &base);
    
    printf("Digite o expoente: ");
    scanf("%d", &expoente);
    
    // Chama a função e imprime apenas o resultado final
    printf("Resultado: %d^%d = %d\n", base, expoente, potencia(base, expoente));
    
    return 0;
}