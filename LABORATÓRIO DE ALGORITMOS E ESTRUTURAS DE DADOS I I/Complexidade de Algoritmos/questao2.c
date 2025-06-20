#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long fibonacci_iterativo(int n) {
    if (n <= 1) return n;
    
    long long a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Uso: %s <n> <n_max_iteracoes>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int n_max = atoi(argv[2]);
    clock_t start, end;
    double tempo_total = 0.0;
    long long resultado;

    for (int i = 0; i < n_max; i++) {
        start = clock();
        resultado = fibonacci_iterativo(n);
        end = clock();
        tempo_total += ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Progresso: %.2f%% concluído\n", (i+1)/(double)n_max *100);
    }

    printf("Fibonacci(%d) = %lld\n", n, resultado);
    printf("Tempo médio: %.5f µs\n", (tempo_total/n_max)*1e6);

    return 0;
}