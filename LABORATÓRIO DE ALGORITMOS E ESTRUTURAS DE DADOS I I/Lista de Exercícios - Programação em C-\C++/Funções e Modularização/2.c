#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Função que verifica se o número é primo.
bool ehPrimo(int n){
    if (n <= 1){
        return false;
    }
    if (n == 2){
        return true;
    }
    if (n % 2 == 0){
        return false;
    }
//Verifica divisores ate a raiz quadrada de n.
int limite = (int)sqrt(n) + 1;
    
    for (int i = 3; i <= limite; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main (){
    int inicio, fim;

    printf("Insira o inicio: \n");
    scanf("%d", &inicio);

    printf("Insira o final: \n");
    scanf("%d", &fim);

    printf("Imprima os numeros primos entre %d e %d: \n", inicio, fim);

    for (int i = inicio; i <= fim; i++){
        if (ehPrimo(i)){
            printf("%d, ", i);
        }
    }
    printf("\n");
    return 0;
}