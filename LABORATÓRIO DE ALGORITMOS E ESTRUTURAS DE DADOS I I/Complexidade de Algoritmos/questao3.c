#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PHI (1.618033988749894848204586834365638)
#define SQRT5 (2.23606797749978969640917366873128)

long long fib_binet(int n) {
    return round((pow(PHI, n) - pow(-PHI, -n)) / SQRT5);
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
        resultado = fib_binet(n);
        end = clock();
        tempo_total += ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Progresso: %.2f%% concluído\n", (i+1)/(double)n_max *100);
    }

    printf("Fibonacci(%d) = %lld\n", n, resultado);
    printf("Tempo médio: %.5f µs\n", (tempo_total/n_max)*1e6);
    printf("Precisão válida para n < 70\n");

    return 0;
}